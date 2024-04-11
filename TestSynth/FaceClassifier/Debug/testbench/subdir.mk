################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/face_classifier_c_test_suite.c 

OBJS += \
./testbench/face_classifier_c_test_suite.o 

C_DEPS += \
./testbench/face_classifier_c_test_suite.d 


# Each subdirectory must supply rules for building sources it contributes
testbench/face_classifier_c_test_suite.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/face_classifier_c_test_suite.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


