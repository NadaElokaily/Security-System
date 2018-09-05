################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ATmega32/subdir.mk
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
SmartDUDES.lss \

FLASH_IMAGE += \
SmartDUDES.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SmartDUDES.elf secondary-outputs

# Tool invocations
SmartDUDES.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SmartDUDES.map -mmcu=atmega32 -o "SmartDUDES.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SmartDUDES.lss: SmartDUDES.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SmartDUDES.elf  >"SmartDUDES.lss"
	@echo 'Finished building: $@'
	@echo ' '

SmartDUDES.hex: SmartDUDES.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SmartDUDES.elf  "SmartDUDES.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SmartDUDES.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SmartDUDES.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SmartDUDES.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
