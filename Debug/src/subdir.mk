################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Agent.cpp \
../src/Location.cpp \
../src/Main.cpp \
../src/Object.cpp \
../src/WorldFacade.cpp \
../src/midpo_utils.cpp 

OBJS += \
./src/Agent.o \
./src/Location.o \
./src/Main.o \
./src/Object.o \
./src/WorldFacade.o \
./src/midpo_utils.o 

CPP_DEPS += \
./src/Agent.d \
./src/Location.d \
./src/Main.d \
./src/Object.d \
./src/WorldFacade.d \
./src/midpo_utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"D:\cygwin\usr\include" -I"D:\cygwin\usr\include\w32api" -I"D:\cygwin\lib\gcc\i686-pc-cygwin\3.4.4\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


