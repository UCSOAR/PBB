################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32g491mesx.s 

S_DEPS += \
./Core/Startup/startup_stm32g491mesx.d 

OBJS += \
./Core/Startup/startup_stm32g491mesx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Drivers/STM32G4xx_HAL_Driver" -I../../Core/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Core/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Core" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Drivers" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Drivers/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Components/DataBroker/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Libraries/embedded-template-library/include" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/SoarDebug/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/FlightSafety/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/FlightSafety" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/PBBControl" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Communication" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/EmbeddedProto" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/EmbeddedProto/src" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/Aegis/_C++" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/Aegis" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/PBBControl/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Communication/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Sensors" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Sensors/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarDrivers/MAX31856" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/ActualLoggingTask/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/ActualFlash" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Components/SystemTypes" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32g491mesx.d ./Core/Startup/startup_stm32g491mesx.o

.PHONY: clean-Core-2f-Startup

