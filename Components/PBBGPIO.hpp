/**
 ******************************************************************************
 * File Name          : GPIO.hpp
 * Description        :
 *
 *    GPIO contains all GPIO pins wrapped in a namespace and corresponding functions
 *
 *    All GPIO pins should be controlled through this abstraction layer to ensure readable control.
 *
 ******************************************************************************
*/
#ifndef AVIONICS_INCLUDE_SOAR_CORE_GPIO_H
#define AVIONICS_INCLUDE_SOAR_CORE_GPIO_H
#include "SystemDefines.hpp"
#include "main.h"
#include "stm32g4xx_hal.h"

namespace GPIO
{
    namespace _MAIN_ENGINE_VALVE // Main engine valve GPIO Open/Close should ONLY be touched by MEVManager
    {
        inline void Open() {
//        	HAL_GPIO_WritePin(LAUNCH_GPIO_Port, LAUNCH_Pin, GPIO_PIN_SET);
        	}
        inline void Close() {
//        	HAL_GPIO_WritePin(LAUNCH_GPIO_Port, LAUNCH_Pin, GPIO_PIN_RESET);
        }

        inline bool IsOpen() {
        	return false;
//        	return HAL_GPIO_ReadPin(LAUNCH_GPIO_Port, LAUNCH_Pin) == GPIO_PIN_SET;
        }
    }

	namespace Drain
	{
		inline void Open() {
//			HAL_GPIO_WritePin(DRAIN_CONTROL_GPIO_Port, DRAIN_CONTROL_Pin, GPIO_PIN_RESET);
		}

		inline void Close() {
//			HAL_GPIO_WritePin(DRAIN_CONTROL_GPIO_Port, DRAIN_CONTROL_Pin, GPIO_PIN_SET);
		}

		inline bool IsOpen() {
			return false;
//			return HAL_GPIO_ReadPin(DRAIN_CONTROL_GPIO_Port, DRAIN_CONTROL_Pin) == GPIO_PIN_RESET;
		}
	}	

}

#endif /* AVIONICS_INCLUDE_SOAR_CORE_GPIO_H */
