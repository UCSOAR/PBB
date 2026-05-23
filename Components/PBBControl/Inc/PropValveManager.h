/*
 * PropValveManager.h
 *
 *  Created on: May 22, 2026
 *      Author: Javier Dal Monte Casoni
 */

#ifndef COMPONENTS_PBBCONTROL_PROPVALVEMANAGER_H_
#define COMPONENTS_PBBCONTROL_PROPVALVEMANAGER_H_

#include "SystemDefines.hpp"
#include "GPIO.hpp"

class PropValveManager {
public:
	static PropValveManager& Inst() {
		static PropValveManager inst;
		return inst;
	}

	PropValveManager();
	virtual ~PropValveManager();

	void OnStateChange(uint8_t state) { state_ = state; }

	bool RequestMEVOpen();
	bool RequestDrainOpen();
	void RequestMEVClose();
	void RequestDrainClose();

private:
    uint8_t state_; // Set in constructor and updated by the state machine
};


#endif /* COMPONENTS_PBBCONTROL_PROPVALVEMANAGER_H_ */
