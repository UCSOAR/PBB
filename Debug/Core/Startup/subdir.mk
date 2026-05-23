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
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/eljav/Documents/SOAR/PBB/Drivers/STM32G4xx_HAL_Driver" -I../../Core/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/eljav/Documents/SOAR/PBB/Components" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarOS/Core/Inc" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarOS/Core" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarOS/Drivers" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarOS/Drivers/Inc" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarOS" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/LoggingModule" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/LoggingModule/Inc" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/Flash/Driver" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarOS/Libraries/embedded-template-library/include" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/Flash/Inc" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/SoarDebug/Inc" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/FlightSafety/Inc" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/FlightSafety" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/PBBControl" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/Communication" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarCommunications/SoarProto" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarCommunications/SoarProto/EmbeddedProto" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarCommunications/SoarProto/EmbeddedProto/src" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarCommunications/SoarProto/Aegis/_C++" -I"C:/Users/eljav/Documents/SOAR/PBB/SoarCommunications/SoarProto/Aegis" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/PBBControl/Inc" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/Communication/Inc" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/Sensors" -I"C:/Users/eljav/Documents/SOAR/PBB/Components/Sensors/Inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32g491mesx.d ./Core/Startup/startup_stm32g491mesx.o

.PHONY: clean-Core-2f-Startup

