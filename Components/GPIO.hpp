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
    namespace _MAIN_ENGINE_VALVE
    {
        inline void Open() {
        	HAL_GPIO_WritePin(MEV_GPIO_Port, MEV_Pin, GPIO_PIN_SET);
		}
        inline void Close() {
        	HAL_GPIO_WritePin(MEV_GPIO_Port, MEV_Pin, GPIO_PIN_RESET);
        }

        inline bool IsOpen() {
        	return HAL_GPIO_ReadPin(MEV_GPIO_Port, MEV_Pin) == GPIO_PIN_SET;
        }
    }

	namespace Drain
	{
		//TODO: LastTask Drain invalid while MEV SOL
		inline void Open() {
			HAL_GPIO_WritePin(DRAIN_GPIO_Port, DRAIN_Pin, GPIO_PIN_SET);
		}

		inline void Close() {
			HAL_GPIO_WritePin(DRAIN_GPIO_Port, DRAIN_Pin, GPIO_PIN_RESET);
		}

		inline bool IsOpen() {
			return HAL_GPIO_ReadPin(DRAIN_GPIO_Port, DRAIN_Pin) == GPIO_PIN_SET;
		}
	}	

}

#endif /* AVIONICS_INCLUDE_SOAR_CORE_GPIO_H */
