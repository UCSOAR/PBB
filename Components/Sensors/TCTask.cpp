/*
 * TCTask.cpp
 *
 *  Created on: Jan 23, 2026
 *      Author: me
 */


/************************************
 * INCLUDES
 ************************************/
#include "TCTask.hpp"
#include "SystemDefines.hpp"
#include "Command.hpp"

#include "Task.hpp"
#include "main.h"
#include "ProtocolTask.hpp"
#include "PBBProtoTask.hpp"
#include "DataBroker.hpp"


/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * VARIABLES
 ************************************/

/************************************
 * FUNCTION DECLARATIONS
 ************************************/

/************************************
 * FUNCTION DEFINITIONS
 ************************************/
TCTask::TCTask():Task(TASK_TC_QUEUE_DEPTH_OBJS)
{
    data = (ThermocoupleData*)soar_malloc(sizeof(ThermocoupleData));
}

/**
 * @brief Initialize the TCTask
 *        Do not modify this function aside from adding the task name
 */
void TCTask::InitTask()
{
    // Make sure the task is not already initialized
    SOAR_ASSERT(rtTaskHandle == nullptr, "Cannot initialize TC task twice");

    BaseType_t rtValue =
        xTaskCreate((TaskFunction_t)TCTask::RunTask,
            (const char*)"TCTask",
            (uint16_t)TASK_TC_STACK_DEPTH_WORDS,
            (void*)this,
            (UBaseType_t)TASK_TC_PRIORITY,
            (TaskHandle_t*)&rtTaskHandle);

    SOAR_ASSERT(rtValue == pdPASS, "TCTask::InitTask() - xTaskCreate() failed");


}

void TCTask::Run(void * pvParams){

	osDelay(100);
	TCDriver1.Init(&hspi2, SPI2_TC_CS1_N_GPIO_Port, SPI2_TC_CS1_N_Pin);
	TCDriver2.Init(&hspi2, SPI2_TC_CS2_N_GPIO_Port, SPI2_TC_CS2_N_Pin);
	TCDriver3.Init(&hspi2, SPI2_TC_CS3_N_GPIO_Port, SPI2_TC_CS3_N_Pin);


	TCDriver1.SetCR1((0b0011<<4) | MAX31856_REG::CR1_TYPE_K);
	TCDriver2.SetCR1((0b0011<<4) | MAX31856_REG::CR1_TYPE_K);
	TCDriver3.SetCR1((0b0011<<4) | MAX31856_REG::CR1_TYPE_K);

	// cont conv mode
	TCDriver1.SetCR0(0b10000000);
	TCDriver2.SetCR0(0b10000000);
	TCDriver3.SetCR0(0b10000000);

    while (1) {
        Command cm;
        bool res = qEvtQueue->ReceiveWait(cm);
        if(res){
        	HandleCommand(cm);
        }
#define MAX(a,b) (a > b ? a : b)
        osDelay(MAX(ticksPerFlashLog,100));

        if(ticksPerFlashLog != 0) {
        	SampleTC();
			DataBroker::Publish<ThermocoupleData>(data);
        }
    }

}

void TCTask::HandleCommand(Command& cm){

	switch (cm.GetCommand()) {
	    case REQUEST_COMMAND: {
	        HandleRequestCommand(cm.GetTaskCommand());
	    }
	    case TASK_SPECIFIC_COMMAND: {
	    	if(cm.GetTaskCommand() == TC_SET_FLASH_RATE) {
	    		ticksPerFlashLog = *(uint32_t*)cm.GetDataPointer();
	    		SOAR_PRINT("tc rate %d\n",ticksPerFlashLog);
	    	}
	        break;
	    }
	    default:
	        SOAR_PRINT("TCTask - Received Unsupported Command {%d}\n", cm.GetCommand());
	        break;
	    }
	cm.Reset();

	return;

}

/**
 * @brief Handles a Request Command
 * @param taskCommand The command to handle
 */
void TCTask::HandleRequestCommand(uint16_t taskCommand)
{
    //Switch for task specific command within DATA_COMMAND
    switch (taskCommand) {
    case TC_REQUEST_NEW_SAMPLE:
        SampleTC();
        break;
    case TC_REQUEST_TRANSMIT:
    	SampleTC();
    	TransmitProtocolTCData();
        break;
    case TC_REQUEST_DEBUG:

        SOAR_PRINT("|TC_TASK| TC (C): %d.%d, %d.%d, %d.%d, MCU Timestamp: %u\r\n",
        		int(data->temp1),abs(int(data->temp1*100-int(data->temp1)*100)),
				int(data->temp2),abs(int(data->temp2*100-int(data->temp2)*100)),
				int(data->temp3),abs(int(data->temp3*100-int(data->temp3)*100)),
        		TICKS_TO_MS(xTaskGetTickCount()));
        break;
    default:
        SOAR_PRINT("UARTTask - Received Unsupported REQUEST_COMMAND {%d}\n", taskCommand);
        break;
    }
}

void TCTask::SampleTC()
{


	data->temp1 = TCDriver1.ReadThermocoupleTempC();

	data->temp2 = TCDriver2.ReadThermocoupleTempC();

	data->temp3 = TCDriver3.ReadThermocoupleTempC();

}



void TCTask::TransmitProtocolTCData()
{

    Proto::TelemetryMessage msg;
	msg.set_source(Proto::Node::NODE_PBB);
	msg.set_target(Proto::Node::NODE_FSB);
	Proto::PbbTemperature tempData;

	tempData.set_ib_temperature(data->temp1);
	tempData.set_lower_pv_tc1(data->temp2);
	tempData.set_low_solenoid_heater_tc(data->temp3);

	msg.set_pbbTemperature(tempData);

	EmbeddedProto::WriteBufferFixedSize<DEFAULT_PROTOCOL_WRITE_BUFFER_SIZE> writeBuffer;
	msg.serialize(writeBuffer);

    // Send the barometer data
	PBBProtocolTask::SendProtobufMessage(writeBuffer, Proto::MessageID::MSG_TELEMETRY);
}
