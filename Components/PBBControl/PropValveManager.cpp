/*
 * PropValveManager.cpp
 *
 *  Created on: May 22, 2026
 *      Author: Javier Dal Monte Casoni
 */

#include "PropValveManager.h"
#include "PBBStateMachine.hpp"

PropValveManager::PropValveManager() : state_(RS_NONE) {
    // TODO Auto-generated constructor stub
}

PropValveManager::~PropValveManager() {
    // TODO Auto-generated destructor stub
}
//

bool PropValveManager::RequestMEVOpen() {
	// If state is launch, close drain, delay, open MEV
    if ((GPIO::Drain::IsOpen()) && (state_ == RS_LAUNCH)){
        GPIO::Drain::Close();
        osDelay(100); // Delay to ensure the drain has time to close before opening the MEV
        GPIO::_MAIN_ENGINE_VALVE::Open();
        return true;
    }
    // if state is not launch, just open MEV if drain is not open
    else if ((state_ != RS_LAUNCH) && !(GPIO::Drain::IsOpen())) {
		GPIO::_MAIN_ENGINE_VALVE::Open();
		return true;
	}
    // if Drain is open and state is not launch, return false, caller should close drain first
	else {
		return false; // this means drain is open, caller should close drain first
	}
}

bool PropValveManager::RequestDrainOpen() {
    if (GPIO::_MAIN_ENGINE_VALVE::IsOpen()) {
        return false; // this means MEV is open, caller should close MEV first
    }
    GPIO::Drain::Open();
    return true;
}

void PropValveManager::RequestMEVClose() {
    GPIO::_MAIN_ENGINE_VALVE::Close();
}

void PropValveManager::RequestDrainClose() {
    GPIO::Drain::Close();
}



//TODO: Find where GUI commands are translated into MEV/Drain actions. [x]
//TODO: Route those actions through PropValveManager instead of direct GPIO. [x]
//TODO: wire PropValveManager::OnStateChange() from the FSM transition path [x]
//TODO: Launch onEnter does what is here on the manager regarding MEV force drain close and MEV open [ ]
