################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/model/BraidedLinkedList.cpp \
../src/model/Student.cpp \
../src/model/fileInputAndOutput.cpp 

OBJS += \
./src/model/BraidedLinkedList.o \
./src/model/Student.o \
./src/model/fileInputAndOutput.o 

CPP_DEPS += \
./src/model/BraidedLinkedList.d \
./src/model/Student.d \
./src/model/fileInputAndOutput.d 


# Each subdirectory must supply rules for building sources it contributes
src/model/%.o: ../src/model/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/Daniel/Downloads/DanielBurkhartGradeBraider/src/controller" -I"/Users/Daniel/Downloads/DanielBurkhartGradeBraider/src/model" -I"/Users/Daniel/Downloads/DanielBurkhartGradeBraider/src/view" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


