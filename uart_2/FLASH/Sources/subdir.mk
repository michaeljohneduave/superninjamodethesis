################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Application.c" \
"../Sources/Events.c" \
"../Sources/ProcessorExpert.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/Application.c \
../Sources/Events.c \
../Sources/ProcessorExpert.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/Application.o \
./Sources/Events.o \
./Sources/ProcessorExpert.o \
./Sources/sa_mtb.o \

C_DEPS += \
./Sources/Application.d \
./Sources/Events.d \
./Sources/ProcessorExpert.d \
./Sources/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/Application.o" \
"./Sources/Events.o" \
"./Sources/ProcessorExpert.o" \
"./Sources/sa_mtb.o" \

C_DEPS_QUOTED += \
"./Sources/Application.d" \
"./Sources/Events.d" \
"./Sources/ProcessorExpert.d" \
"./Sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/Application.o \
./Sources/Events.o \
./Sources/ProcessorExpert.o \
./Sources/sa_mtb.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Application.o: ../Sources/Application.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Application.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Application.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Events.o: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Events.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert.o: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ProcessorExpert.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/ProcessorExpert.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb.o: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '


