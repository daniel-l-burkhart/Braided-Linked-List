################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/controller/GradeBraiderController.cpp 

OBJS += \
./src/controller/GradeBraiderController.o 

CPP_DEPS += \
./src/controller/GradeBraiderController.d 


# Each subdirectory must supply rules for building sources it contributes
src/controller/%.o: ../src/controller/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/Daniel/Downloads/DanielBurkhartGradeBraider/src/controller" -I"/Users/Daniel/Downloads/DanielBurkhartGradeBraider/src/model" -I"/Users/Daniel/Downloads/DanielBurkhartGradeBraider/src/view" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


