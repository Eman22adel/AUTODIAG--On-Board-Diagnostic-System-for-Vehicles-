################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/COM_H.c \
../HAL/SERIAL_COM.c 

OBJS += \
./HAL/COM_H.o \
./HAL/SERIAL_COM.o 

C_DEPS += \
./HAL/COM_H.d \
./HAL/SERIAL_COM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o HAL/%.su HAL/%.cyclo: ../HAL/%.c HAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/emana/STM32CubeIDE/workspace_1.13.2/Diagnostic/APP" -I"C:/Users/emana/STM32CubeIDE/workspace_1.13.2/Diagnostic/HAL" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL

clean-HAL:
	-$(RM) ./HAL/COM_H.cyclo ./HAL/COM_H.d ./HAL/COM_H.o ./HAL/COM_H.su ./HAL/SERIAL_COM.cyclo ./HAL/SERIAL_COM.d ./HAL/SERIAL_COM.o ./HAL/SERIAL_COM.su

.PHONY: clean-HAL

