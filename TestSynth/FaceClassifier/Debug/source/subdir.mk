################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/face_classifier_c.c \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_activations.c \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_convolution_layers.c \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_core_layers.c \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_embedding_layers.c \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_helper_functions.c \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_merge_layers.c \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_normalization_layers.c \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_pooling_layers.c \
C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_recurrent_layers.c 

OBJS += \
./source/face_classifier_c.o \
./source/k2c_activations.o \
./source/k2c_convolution_layers.o \
./source/k2c_core_layers.o \
./source/k2c_embedding_layers.o \
./source/k2c_helper_functions.o \
./source/k2c_merge_layers.o \
./source/k2c_normalization_layers.o \
./source/k2c_pooling_layers.o \
./source/k2c_recurrent_layers.o 

C_DEPS += \
./source/face_classifier_c.d \
./source/k2c_activations.d \
./source/k2c_convolution_layers.d \
./source/k2c_core_layers.d \
./source/k2c_embedding_layers.d \
./source/k2c_helper_functions.d \
./source/k2c_merge_layers.d \
./source/k2c_normalization_layers.d \
./source/k2c_pooling_layers.d \
./source/k2c_recurrent_layers.d 


# Each subdirectory must supply rules for building sources it contributes
source/face_classifier_c.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/face_classifier_c.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/k2c_activations.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_activations.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/k2c_convolution_layers.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_convolution_layers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/k2c_core_layers.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_core_layers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/k2c_embedding_layers.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_embedding_layers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/k2c_helper_functions.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_helper_functions.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/k2c_merge_layers.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_merge_layers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/k2c_normalization_layers.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_normalization_layers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/k2c_pooling_layers.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_pooling_layers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/k2c_recurrent_layers.o: C:/Users/ketan/Desktop/college/CS-577-Course-Project/C-Code-Original/include/k2c_recurrent_layers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2018.2/include/ap_sysc -IC:/Xilinx/Vivado/2018.2/include -IC:/Xilinx/Vivado/2018.2/include/etc -IC:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth -IC:/Xilinx/Vivado/2018.2/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.2/win64/tools/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


