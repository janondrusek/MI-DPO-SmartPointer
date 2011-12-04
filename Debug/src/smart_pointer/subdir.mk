################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/smart_pointer/LocationSmartPointer.cpp \
../src/smart_pointer/RC.cpp \
../src/smart_pointer/WorldFacadeSmartPointerImpl.cpp 

OBJS += \
./src/smart_pointer/LocationSmartPointer.o \
./src/smart_pointer/RC.o \
./src/smart_pointer/WorldFacadeSmartPointerImpl.o 

CPP_DEPS += \
./src/smart_pointer/LocationSmartPointer.d \
./src/smart_pointer/RC.d \
./src/smart_pointer/WorldFacadeSmartPointerImpl.d 


# Each subdirectory must supply rules for building sources it contributes
src/smart_pointer/%.o: ../src/smart_pointer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"D:\Documents\Development\workspaceSchool\MI-DPO-SmartPointer\src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


