################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PWM.c \
../adc.c \
../dc_motor.c \
../gpio.c \
../lcd.c \
../lm_35.c \
../main.c 

OBJS += \
./PWM.o \
./adc.o \
./dc_motor.o \
./gpio.o \
./lcd.o \
./lm_35.o \
./main.o 

C_DEPS += \
./PWM.d \
./adc.d \
./dc_motor.d \
./gpio.d \
./lcd.d \
./lm_35.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


