################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/app/atan.c 

C_DEPS += \
./src/app/atan.d 

OBJS += \
./src/app/atan.o 


# Each subdirectory must supply rules for building sources it contributes
src/app/%.o: ../src/app/%.c src/app/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-app

clean-src-2f-app:
	-$(RM) ./src/app/atan.d ./src/app/atan.o

.PHONY: clean-src-2f-app

