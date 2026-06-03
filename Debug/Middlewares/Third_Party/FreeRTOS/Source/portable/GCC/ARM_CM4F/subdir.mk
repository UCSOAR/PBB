################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu17 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32G491xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Drivers/STM32G4xx_HAL_Driver" -I../../Core/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Core/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Core" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Drivers" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Drivers/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Components/DataBroker/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Libraries/embedded-template-library/include" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/SoarDebug/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/FlightSafety/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/FlightSafety" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/PBBControl" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Communication" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/EmbeddedProto" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/EmbeddedProto/src" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/Aegis/_C++" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/Aegis" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/PBBControl/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Communication/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Sensors" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Sensors/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarDrivers/MAX31856" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/ActualLoggingTask/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/ActualFlash" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Components/SystemTypes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F

clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.d ./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o ./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F

