################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/DCM.c \
../APP/DEM.c \
../APP/MASTER_BUS.c 

OBJS += \
./APP/DCM.o \
./APP/DEM.o \
./APP/MASTER_BUS.o 

C_DEPS += \
./APP/DCM.d \
./APP/DEM.d \
./APP/MASTER_BUS.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o APP/%.su APP/%.cyclo: ../APP/%.c APP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/emana/STM32CubeIDE/workspace_1.13.2/Diagnostic/APP" -I"C:/Users/emana/STM32CubeIDE/workspace_1.13.2/Diagnostic/HAL" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP

clean-APP:
	-$(RM) ./APP/DCM.cyclo ./APP/DCM.d ./APP/DCM.o ./APP/DCM.su ./APP/DEM.cyclo ./APP/DEM.d ./APP/DEM.o ./APP/DEM.su ./APP/MASTER_BUS.cyclo ./APP/MASTER_BUS.d ./APP/MASTER_BUS.o ./APP/MASTER_BUS.su

.PHONY: clean-APP

