################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/DC_Motor/DC_Motor.c 

OBJS += \
./HAL/DC_Motor/DC_Motor.o 

C_DEPS += \
./HAL/DC_Motor/DC_Motor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/DC_Motor/%.o: ../HAL/DC_Motor/%.c HAL/DC_Motor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


