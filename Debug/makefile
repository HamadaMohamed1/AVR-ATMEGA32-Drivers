################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mcal/uart/subdir.mk
-include mcal/timer0/subdir.mk
-include mcal/spi/subdir.mk
-include mcal/interrupt/subdir.mk
-include mcal/i2c/subdir.mk
-include mcal/gpio/subdir.mk
-include mcal/eeprom/subdir.mk
-include hal/seven_segment/subdir.mk
-include hal/relay/subdir.mk
-include hal/led/subdir.mk
-include hal/lcd/subdir.mk
-include hal/keypad/subdir.mk
-include hal/button/subdir.mk
-include app/subdir.mk
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
my_atmega32_drivers.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: my_atmega32_drivers.elf secondary-outputs

# Tool invocations
my_atmega32_drivers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,my_atmega32_drivers.map -mmcu=atmega32 -o "my_atmega32_drivers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

my_atmega32_drivers.lss: my_atmega32_drivers.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S my_atmega32_drivers.elf  >"my_atmega32_drivers.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: my_atmega32_drivers.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 my_atmega32_drivers.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) my_atmega32_drivers.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
