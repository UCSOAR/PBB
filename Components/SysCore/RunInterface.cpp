/*
 *  RunInterface.cpp
 *
 *  Created on: Apr 3, 2023
 *      Author: Chris (cjchanx)
 */

#include "../../SoarOS/Drivers/Inc/UARTDriver.hpp"
#include "main_avionics.hpp"

#include "RunInterface.hpp"

extern "C" {
void run_interface() { run_main(); }

void cpp_USART1_IRQHandler() {
		Driver::usart1.HandleIRQ_UART();}

void cpp_UART5_IRQHandler() {
		Driver::uart5.HandleIRQ_UART();}
}
