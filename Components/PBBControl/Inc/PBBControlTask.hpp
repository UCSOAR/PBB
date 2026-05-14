/*
 * PBBControlTask.hpp
 *
 *  Created on: May 13, 2026
 *      Author: Andrey
 */

#ifndef PBBCONTROLTASK_HPP_
#define PBBCONTROLTASK_HPP_

/************************************
 * INCLUDES
 ************************************/
#include "Task.hpp"
#include "SystemDefines.hpp"
#include "PBBStateMachine.hpp"
#include "PBBStates.hpp"

/************************************
 * MACROS AND DEFINES
 ************************************/
// TODO NEW
constexpr uint16_t FLIGHT_TASK_BOOTUP_TELE_CYCLES = 20;

/************************************
 * TYPEDEFS
 ************************************/
 enum FlightTaskRequests
 {
 	FT_REQUEST_NONE = 0,
 	FT_REQUEST_TRANSMIT_STATE,	// Send the current state over the UART
 };

/************************************
 * CLASS DEFINITIONS
 ************************************/
class PBBControlTask : public Task
{
public:
    static PBBControlTask& Inst() {
        static PBBControlTask inst;
        return inst;
    }

    void InitTask();

protected:
    static void RunTask(void* pvParams) { PBBControlTask::Inst().Run(pvParams); } // Static Task Interface, passes control to the instance Run();

    void Run(void * pvParams); // Main run code

    void HandleCommand(Command& cm);

    void SendRocketState();

private:
    // Private Functions
    PBBControlTask();        // Private constructor
    PBBControlTask(const PBBControlTask&);                        // Prevent copy-construction
    PBBControlTask& operator=(const PBBControlTask&);            // Prevent assignment

    // Private Variables
    RocketSM* rsm_;
    uint16_t firstStateSent_;
};

/************************************
 * FUNCTION DECLARATIONS
 ************************************/

#endif /* PBBCONTROLTASK_HPP_ */
