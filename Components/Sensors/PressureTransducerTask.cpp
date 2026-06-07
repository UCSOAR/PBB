/**
 ********************************************************************************
 * @file    PressureTransducerTask.cpp
 * @author  Shivam Desai
 * @date    May 12, 2026
 * @brief
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "PressureTransducerTask.hpp"
#include "main.h"
#include "DebugTask.hpp"
#include "Task.hpp"
#include <time.h>
#include "PBBProtoTask.hpp"
#include "CubeUtils.hpp"
#include "DataBroker.hpp"
#include "ActualLoggingTask.hpp"

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
/**
 * @brief Default constructor, sets and sets up storage for member variables
 */
PressureTransducerTask::PressureTransducerTask() : Task(TASK_PRESSURE_TRANSDUCER_QUEUE_DEPTH_OBJS)
{
	data = (PBBPressureTransducerData*)soar_malloc(sizeof(PBBPressureTransducerData));
	bigdump = (PTRambufData*)soar_malloc(sizeof(PTRambufData)*BIGDUMPSIZE);
}

/**
 * @brief Creates a task for the FreeRTOS Scheduler
 */
void PressureTransducerTask::InitTask()
{
	// Make sure the task is not already initialized
	SOAR_ASSERT(rtTaskHandle == nullptr, "Cannot initialize PT task twice");

	// Start the task
	BaseType_t rtValue =
			xTaskCreate((TaskFunction_t)PressureTransducerTask::RunTask,
					(const char*)"PTTask",
					(uint16_t)TASK_PRESSURE_TRANSDUCER_STACK_DEPTH_WORDS,
					(void*)this,
					(UBaseType_t)TASK_PRESSURE_TRANSDUCER_PRIORITY,
					(TaskHandle_t*)&rtTaskHandle);

	//Ensure creation succeded
	SOAR_ASSERT(rtValue == pdPASS, "PressureTransducerTask::InitTask() - xTaskCreate() failed");
}

/**
 * @brief PresssureTransducerTask run loop
 * @param pvParams Currently unused task context
 */
void PressureTransducerTask::Run(void * pvParams)
{

	bool reporteddumpstat = false;
	uint32_t last = HAL_GetTick();
	while (1) {
		Command cm;

		//Wait forever for a command
		bool res = qEvtQueue->Receive(cm);

		//Process the command
		if(res)
			HandleCommand(cm);

#define MIN(a,b) (a > b ? b : a)
		osDelay(MIN(ticksPerFlashLog, 300));

		uint32_t th = HAL_GetTick();
		if(th - last > ticksPerFlashLog) {
			last = th;
			if(ticksPerFlashLog != 0) {
				SamplePressureTransducer();
				if(ticksPerFlashLog < 3 && bigdumpi < BIGDUMPSIZE) {
					bigdump[bigdumpi++] = {*data,HAL_GetTick()};
					if(!reporteddumpstat) {
						SOAR_PRINT("we have switched to big dump, starting at %d!\n",bigdumpi);
						reporteddumpstat = true;
					}
				} else {
					DataBroker::Publish<PBBPressureTransducerData>(data);
				}
			}

			if(bigdumpi > 0 && (ticksPerFlashLog >= 3 || ticksPerFlashLog == 0)) {
				for(uint16_t i = 0; i < 10; i++) {
					Command cm = {TASK_SPECIFIC_COMMAND,LOG_FROM_RAMBUF};
					cm.CopyDataToCommand((uint8_t*)&bigdump[--bigdumpi], sizeof(bigdump[0]));
					ActualLoggingTask::Inst().SendCommandReference(cm);
					if(bigdumpi == 0) {
						SOAR_PRINT("done catching up!\n");
						break;
					}
				}
				if(reporteddumpstat) {
					SOAR_PRINT("catching up... (%d)\n",bigdumpi);
					reporteddumpstat = false;
				}
			}
		}
	}
}

/**
 * @brief Handles a command
 * @param cm Command reference to handle
 */
void PressureTransducerTask::HandleCommand(Command& cm)
{
	//TODO: Since this task will stall for a few milliseconds, we may need a way to eat the whole queue (combine similar eg. REQUEST commands and eat to WDG command etc)
	//TODO: Maybe a HandleEvtQueue instead that takes in the whole queue and eats the whole thing in order of non-blocking to blocking

	//Switch for the GLOBAL_COMMAND
	switch (cm.GetCommand()) {
	case REQUEST_COMMAND: {
		HandleRequestCommand(cm.GetTaskCommand());
	}
	case TASK_SPECIFIC_COMMAND: {
		if(cm.GetTaskCommand() == PT_SET_FLASH_RATE) {
			ticksPerFlashLog = *(uint32_t*)cm.GetDataPointer();
			SOAR_PRINT("pt rate %d\n",ticksPerFlashLog);
		}
		break;
	}
	default:
		SOAR_PRINT("PressureTransducerTask - Received Unsupported Command {%d}\n", cm.GetCommand());
		break;
	}

	//No matter what we happens, we must reset allocated data
	cm.Reset();
}

/**
 * @brief Handles a Request Command
 * @param taskCommand The command to handle
 */
void PressureTransducerTask::HandleRequestCommand(uint16_t taskCommand)
{
	//Switch for task specific command within DATA_COMMAND
	switch (taskCommand) {
	case PT_REQUEST_NEW_SAMPLE:
		SamplePressureTransducer();
		break;
	case PT_REQUEST_TRANSMIT:
		// TODO NEW
		SamplePressureTransducer();
		TransmitProtocolPressureData();
		break;
	case PT_REQUEST_DEBUG:
		//SOAR_PRINT("\t-- Pressure Transducer Data --\n");
		SOAR_PRINT("|PT_TASK| Pressure 1 (PSI): %d.%d, MCU Timestamp: %u\r\n", data->pressure_1 / 1000, data->pressure_1 % 1000,
				timestampPT);
		SOAR_PRINT("|PT_TASK| Pressure 2 (PSI): %d.%d, MCU Timestamp: %u\r\n", data->pressure_2 / 1000, data->pressure_2 % 1000,
				timestampPT);
		//SOAR_PRINT(" Pressure (psi): %d.%d\n", data->pressure_ / 1000, data->pressure_ % 1000);
		break;
	default:
		SOAR_PRINT("PressureTransducerTask - Received Unsupported REQUEST_COMMAND {%d}\n", taskCommand);
		break;
	}
}


void ADC_Select_CH3 (void)
{
	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Channel = ADC_CHANNEL_3;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_640CYCLES_5;
	sConfig.SingleDiff = ADC_SINGLE_ENDED;
	sConfig.OffsetNumber = ADC_OFFSET_NONE;
	sConfig.Offset = 0;
	if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
	{
		Error_Handler();
	}
}

void ADC_Select_CH16 (void)
{
	ADC_ChannelConfTypeDef sConfig = {0};
	/** Configure Regular Channel
	 */
	sConfig.Channel = ADC_CHANNEL_16;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_640CYCLES_5;
	sConfig.SingleDiff = ADC_SINGLE_ENDED;
	sConfig.OffsetNumber = ADC_OFFSET_NONE;
	sConfig.Offset = 0;
	if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
	{
		Error_Handler();
	}
}

void PressureTransducerTask::SamplePressureTransducer()
{
	static const int PT_VOLTAGE_ADC_POLL_TIMEOUT = 50;
	static const double PRESSURE_SCALE = 1.5220883534136546;

	static bool adc3Calibrated = false;

	double adcVal[2] = {};
	double pressureTransducerValue1 = 0;
	double pressureTransducerValue2 = 0;
	double vi = 0;

	/* Calibrate ADC once before conversions */
	if (!adc3Calibrated)
	{
		HAL_ADC_Stop(&hadc3);

		if (HAL_ADCEx_Calibration_Start(&hadc3, ADC_SINGLE_ENDED) != HAL_OK)
		{
			Error_Handler();
		}

		adc3Calibrated = true;
		osDelay(50);
	}

	/* ---------------- CH3 ---------------- */
	ADC_Select_CH3();
	//osDelay(1);

	// Real conversion
	if (HAL_ADC_Start(&hadc3) != HAL_OK)
	{
		Error_Handler();
	}

	if (HAL_ADC_PollForConversion(&hadc3, PT_VOLTAGE_ADC_POLL_TIMEOUT) == HAL_OK)
	{
		adcVal[0] = HAL_ADC_GetValue(&hadc3);
	}

	if (HAL_ADC_Stop(&hadc3) != HAL_OK)
	{
		Error_Handler();
	}

	/* ---------------- CH16 ---------------- */
	ADC_Select_CH16();
	//osDelay(1);

	if (HAL_ADC_Start(&hadc3) != HAL_OK)
	{
		Error_Handler();
	}

	if (HAL_ADC_PollForConversion(&hadc3, PT_VOLTAGE_ADC_POLL_TIMEOUT) == HAL_OK)
	{
		adcVal[1] = HAL_ADC_GetValue(&hadc3);
	}

	if (HAL_ADC_Stop(&hadc3) != HAL_OK)
	{
		Error_Handler();
	}

	/* ---------------- Convert ADC to pressure ---------------- */

	// PT2
	// 0.321
	vi = (((3.335 / 4095.0) * adcVal[0]))/4;
	pressureTransducerValue1 = (250 * (vi * PRESSURE_SCALE) - 125) * 1000;
	data->pressure_1 = (int32_t)pressureTransducerValue1;

	// PT1
	// 0.32
	vi = (((3.335 / 4095.0) * adcVal[1]))/4;
	pressureTransducerValue2 = (250 * (vi * PRESSURE_SCALE) - 125) * 1000;
	data->pressure_2 = (int32_t)pressureTransducerValue2;

	timestampPT = HAL_GetTick();
}

/**
 * @brief Transmits a protocol barometer data sample
 */
void PressureTransducerTask::TransmitProtocolPressureData()
{
	// SOAR_PRINT("Pressure Transducer Transmit...\n");

	Proto::TelemetryMessage msg;
	msg.set_source(Proto::Node::NODE_PBB);
	msg.set_target(Proto::Node::NODE_FSB);
	Proto::PbbPressure pressData;
	pressData.set_ib_pressure(data->pressure_1);
	pressData.set_lower_pv_pressure(data->pressure_2);
	msg.set_pbbPressure(pressData);

	EmbeddedProto::WriteBufferFixedSize<DEFAULT_PROTOCOL_WRITE_BUFFER_SIZE> writeBuffer;
	msg.serialize(writeBuffer);

	// Send the barometer data
	PBBProtocolTask::SendProtobufMessage(writeBuffer, Proto::MessageID::MSG_TELEMETRY);
}
