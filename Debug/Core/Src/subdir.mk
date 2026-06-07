################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app_freertos.c \
../Core/Src/main.c \
../Core/Src/stm32g4xx_hal_msp.c \
../Core/Src/stm32g4xx_hal_timebase_tim.c \
../Core/Src/stm32g4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32g4xx.c 

C_DEPS += \
./Core/Src/app_freertos.d \
./Core/Src/main.d \
./Core/Src/stm32g4xx_hal_msp.d \
./Core/Src/stm32g4xx_hal_timebase_tim.d \
./Core/Src/stm32g4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32g4xx.d 

OBJS += \
./Core/Src/app_freertos.o \
./Core/Src/main.o \
./Core/Src/stm32g4xx_hal_msp.o \
./Core/Src/stm32g4xx_hal_timebase_tim.o \
./Core/Src/stm32g4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32g4xx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu17 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32G491xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Drivers/STM32G4xx_HAL_Driver" -I../../Core/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Core/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Core" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Drivers" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Drivers/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Components/DataBroker/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarOS/Libraries/embedded-template-library/include" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/SoarDebug/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/FlightSafety/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/FlightSafety" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/PBBControl" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Communication" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/EmbeddedProto" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/EmbeddedProto/src" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/Aegis/_C++" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarCommunications/SoarProto/Aegis" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/PBBControl/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Communication/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Sensors" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/Components/Sensors/Inc" -I"C:/Users/Local user/Desktop/soar stuff/git update/who/PBB/SoarDrivers/MAX31856" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/app_freertos.cyclo ./Core/Src/app_freertos.d ./Core/Src/app_freertos.o ./Core/Src/app_freertos.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32g4xx_hal_msp.cyclo ./Core/Src/stm32g4xx_hal_msp.d ./Core/Src/stm32g4xx_hal_msp.o ./Core/Src/stm32g4xx_hal_msp.su ./Core/Src/stm32g4xx_hal_timebase_tim.cyclo ./Core/Src/stm32g4xx_hal_timebase_tim.d ./Core/Src/stm32g4xx_hal_timebase_tim.o ./Core/Src/stm32g4xx_hal_timebase_tim.su ./Core/Src/stm32g4xx_it.cyclo ./Core/Src/stm32g4xx_it.d ./Core/Src/stm32g4xx_it.o ./Core/Src/stm32g4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32g4xx.cyclo ./Core/Src/system_stm32g4xx.d ./Core/Src/system_stm32g4xx.o ./Core/Src/system_stm32g4xx.su

.PHONY: clean-Core-2f-Src

