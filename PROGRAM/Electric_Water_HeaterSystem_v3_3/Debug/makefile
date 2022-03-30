################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/INTERNAL_EEPROM/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/TEMPERATURE_SENSOR/subdir.mk
-include HAL/SWITCH/subdir.mk
-include HAL/SEVENSEGMENT/subdir.mk
-include HAL/LED_SYSTEM/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/HEAT_COOL/subdir.mk
-include APP/TMU/subdir.mk
-include APP/SYSTEM/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Electric_Water_HeaterSystem_v3_3.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Electric_Water_HeaterSystem_v3_3.elf secondary-outputs

# Tool invocations
Electric_Water_HeaterSystem_v3_3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Electric_Water_HeaterSystem_v3_3.map -mmcu=atmega32 -o "Electric_Water_HeaterSystem_v3_3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Electric_Water_HeaterSystem_v3_3.lss: Electric_Water_HeaterSystem_v3_3.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Electric_Water_HeaterSystem_v3_3.elf  >"Electric_Water_HeaterSystem_v3_3.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Electric_Water_HeaterSystem_v3_3.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Electric_Water_HeaterSystem_v3_3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Electric_Water_HeaterSystem_v3_3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
