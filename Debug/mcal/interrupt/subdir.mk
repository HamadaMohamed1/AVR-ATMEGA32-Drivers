################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mcal/interrupt/external_interrupt.c \
../mcal/interrupt/general_interrupt.c 

OBJS += \
./mcal/interrupt/external_interrupt.o \
./mcal/interrupt/general_interrupt.o 

C_DEPS += \
./mcal/interrupt/external_interrupt.d \
./mcal/interrupt/general_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
mcal/interrupt/%.o: ../mcal/interrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


