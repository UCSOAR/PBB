################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.d 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.o Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.su Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.cyclo: ../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.c Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu17 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32G491xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Drivers/STM32G4xx_HAL_Driver" -I../../Core/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarOS/Core/Inc" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarOS/Core" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarOS/Drivers" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarOS/Drivers/Inc" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarOS" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarOS/Components/DataBroker/Inc" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/LoggingModule" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/LoggingModule/Inc" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/Flash/Driver" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarOS/Libraries/embedded-template-library/include" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/Flash/Inc" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/SoarDebug/Inc" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/FlightSafety/Inc" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/FlightSafety" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/PBBControl" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/Communication" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarCommunications/SoarProto" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarCommunications/SoarProto/EmbeddedProto" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarCommunications/SoarProto/EmbeddedProto/src" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarCommunications/SoarProto/Aegis/_C++" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarCommunications/SoarProto/Aegis" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/PBBControl/Inc" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/Communication/Inc" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/Sensors" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/Components/Sensors/Inc" -I"C:/Users/shiva/Documents/SOAR/Software/Aegis/PBB/SoarDrivers/MAX31856" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F

clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.d ./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o ./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F

