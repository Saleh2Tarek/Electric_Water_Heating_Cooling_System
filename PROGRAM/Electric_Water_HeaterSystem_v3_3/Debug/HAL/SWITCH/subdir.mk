################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SWITCH/SWITCH_config.c \
../HAL/SWITCH/SWITCH_program.c 

OBJS += \
./HAL/SWITCH/SWITCH_config.o \
./HAL/SWITCH/SWITCH_program.o 

C_DEPS += \
./HAL/SWITCH/SWITCH_config.d \
./HAL/SWITCH/SWITCH_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SWITCH/%.o: ../HAL/SWITCH/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


