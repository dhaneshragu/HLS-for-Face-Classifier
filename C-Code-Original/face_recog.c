#include <math.h> 
#include <string.h>
#include "./include/k2c_include.h"
#include "./include/k2c_tensor_include.h"
#include "./include/k2c_activations.c"
#include "./include/k2c_convolution_layers.c"
#include "./include/k2c_core_layers.c"
#include "./include/k2c_embedding_layers.c"
#include "./include/k2c_helper_functions.c"
#include "./include/k2c_merge_layers.c"
#include "./include/k2c_normalization_layers.c"
#include "./include/k2c_pooling_layers.c"
#include "./include/k2c_recurrent_layers.c"


 


void new_cfile(k2c_tensor dense_7_input_input, k2c_tensor dense_12_output,float dense_7_output_array[128],float dense_7_kernel_array[16384],float dense_7_bias_array[128],float dense_8_output_array[64],float dense_8_kernel_array[8192],float dense_8_bias_array[64],float dense_9_output_array[64],float dense_9_kernel_array[4096],float dense_9_bias_array[64],float dense_10_output_array[32],float dense_10_kernel_array[2048],float dense_10_bias_array[32],float dense_11_output_array[32],float dense_11_kernel_array[1024],float dense_11_bias_array[32],float dense_12_kernel_array[160],float dense_12_bias_array[5]) { 

int i;

// k2c_tensor dense_7_output = {dense_7_output_array,1,128,{128,  1,  1,  1,  1}}; 
k2c_tensor dense_7_output;
    for (i = 0; i < 128; i++) {
        dense_7_output.array[i] = dense_7_output_array[i];
    }
    dense_7_output.ndim = 1;
    dense_7_output.numel = 128;
    dense_7_output.shape[0] = 128;
    dense_7_output.shape[1] = 1;
    dense_7_output.shape[2] = 1;
    dense_7_output.shape[3] = 1;
    dense_7_output.shape[4] = 1;
// k2c_tensor dense_7_kernel = {dense_7_kernel_array,2,16384,{128,128,  1,  1,  1}}; 
k2c_tensor dense_7_kernel;
    for (i = 0; i < 16384; i++) {
        dense_7_kernel.array[i] = dense_7_kernel_array[i];
    }
    dense_7_kernel.ndim = 2;
    dense_7_kernel.numel = 16384;
    dense_7_kernel.shape[0] = 128;
    dense_7_kernel.shape[1] = 128;
    dense_7_kernel.shape[2] = 1;
    dense_7_kernel.shape[3] = 1;
    dense_7_kernel.shape[4] = 1;
// k2c_tensor dense_7_bias = {dense_7_bias_array,1,128,{128,  1,  1,  1,  1}}; 
k2c_tensor dense_7_bias;
    for (i = 0; i < 128; i++) {
        dense_7_bias.array[i] = dense_7_bias_array[i];
    }
    dense_7_bias.ndim = 1;
    dense_7_bias.numel = 128;
    dense_7_bias.shape[0] = 128;
    dense_7_bias.shape[1] = 1;
    dense_7_bias.shape[2] = 1;
    dense_7_bias.shape[3] = 1;
    dense_7_bias.shape[4] = 1;
float dense_7_fwork[16512] = {0}; 

 
// k2c_tensor dense_8_output = {dense_8_output_array,1,64,{64, 1, 1, 1, 1}}; 
k2c_tensor dense_8_output;
for(i=0;i<64;i++){
    dense_8_output.array[i] = dense_8_output_array[i];
}
dense_8_output.ndim = 1;
dense_8_output.numel = 64;
dense_8_output.shape[0] = 64;
dense_8_output.shape[1] = 1;
dense_8_output.shape[2] = 1;
dense_8_output.shape[3] = 1;
dense_8_output.shape[4] = 1;
// k2c_tensor dense_8_kernel = {dense_8_kernel_array,2,8192,{128, 64,  1,  1,  1}}; 
k2c_tensor dense_8_kernel;
for(i=0;i<8192;i++){
    dense_8_kernel.array[i] = dense_8_kernel_array[i];
}
dense_8_kernel.ndim = 2;
dense_8_kernel.numel = 8192;
dense_8_kernel.shape[0] = 128;
dense_8_kernel.shape[1] = 64;
dense_8_kernel.shape[2] = 1;
dense_8_kernel.shape[3] = 1;
dense_8_kernel.shape[4] = 1;
// k2c_tensor dense_8_bias = {dense_8_bias_array,1,64,{64, 1, 1, 1, 1}}; 
k2c_tensor dense_8_bias;
for(i=0;i<64;i++){
    dense_8_bias.array[i] = dense_8_bias_array[i];
}
dense_8_bias.ndim = 1;
dense_8_bias.numel = 64;
dense_8_bias.shape[0] = 64;
dense_8_bias.shape[1] = 1;
dense_8_bias.shape[2] = 1;
dense_8_bias.shape[3] = 1;
dense_8_bias.shape[4] = 1;
float dense_8_fwork[8320] = {0}; 

 
// k2c_tensor dense_9_output = {dense_9_output_array,1,64,{64, 1, 1, 1, 1}}; 
k2c_tensor dense_9_output;
    for (i = 0; i < 64; i++) {
        dense_9_output.array[i] = dense_9_output_array[i];
    }
    dense_9_output.numel = 64;
    dense_9_output.shape[0] = 64;
    dense_9_output.ndim = 1;
    dense_9_output.shape[1] = 1;
    dense_9_output.shape[2] = 1;
    dense_9_output.shape[3] = 1;
    dense_9_output.shape[4] = 1;
// k2c_tensor dense_9_kernel = {dense_9_kernel_array,2,4096,{64,64, 1, 1, 1}}; 
k2c_tensor dense_9_kernel;
    for (i = 0; i < 4096; i++) {
        dense_9_kernel.array[i] = dense_9_kernel_array[i];
    }
    dense_9_kernel.numel = 4096;
    dense_9_kernel.shape[0] = 64;
    dense_9_kernel.ndim = 2;
    dense_9_kernel.shape[1] = 64;
    dense_9_kernel.shape[2] = 1;
    dense_9_kernel.shape[3] = 1;
    dense_9_kernel.shape[4] = 1;
// k2c_tensor dense_9_bias = {dense_9_bias_array,1,64,{64, 1, 1, 1, 1}}; 
k2c_tensor dense_9_bias;
    for (i = 0; i < 64; i++) {
        dense_9_bias.array[i] = dense_9_bias_array[i];
    }
    dense_9_bias.numel = 64;
    dense_9_bias.shape[0] = 64;
    dense_9_bias.ndim = 2;
    dense_9_bias.shape[1] = 1;
    dense_9_bias.shape[2] = 1;
    dense_9_bias.shape[3] = 1;
    dense_9_bias.shape[4] = 1;
float dense_9_fwork[4160] = {0}; 

 
// k2c_tensor dense_10_output = {dense_10_output_array,1,32,{32, 1, 1, 1, 1}};  
k2c_tensor dense_10_output;
    for (i = 0; i < 32; i++) {
        dense_10_output.array[i] = dense_10_output_array[i];
    }
    dense_10_output.ndim = 1;
    dense_10_output.numel = 32;
    dense_10_output.shape[0] = 32;
    dense_10_output.shape[1] = 1;
    dense_10_output.shape[2] = 1;
    dense_10_output.shape[3] = 1;
    dense_10_output.shape[4] = 1;
// k2c_tensor dense_10_kernel = {dense_10_kernel_array,2,2048,{64,32, 1, 1, 1}}; 
k2c_tensor dense_10_kernel;
    for (i = 0; i < 2048; i++) {
        dense_10_kernel.array[i] = dense_10_kernel_array[i];
    }
    dense_10_kernel.ndim = 2;
    dense_10_kernel.numel = 2048;
    dense_10_kernel.shape[0] = 64;
    dense_10_kernel.shape[1] = 32;
    dense_10_kernel.shape[2] = 1;
    dense_10_kernel.shape[3] = 1;
    dense_10_kernel.shape[4] = 1;
// k2c_tensor dense_10_bias = {dense_10_bias_array,1,32,{32, 1, 1, 1, 1}}; 
k2c_tensor dense_10_bias;
    for (i = 0; i < 32; i++) {
        dense_10_bias.array[i] = dense_10_bias_array[i];
    }
    dense_10_bias.ndim = 1;
    dense_10_bias.numel = 32;
    dense_10_bias.shape[0] = 32;
    dense_10_bias.shape[1] = 1;
    dense_10_bias.shape[2] = 1;
    dense_10_bias.shape[3] = 1;
    dense_10_bias.shape[4] = 1;
float dense_10_fwork[2112] = {0}; 

 
// k2c_tensor dense_11_output = {dense_11_output_array,1,32,{32, 1, 1, 1, 1}}; 
k2c_tensor dense_11_output;
for(i=0;i<32;i++){
    dense_11_output.array[i] = dense_11_output_array[i];
}
dense_11_output.ndim = 1;
dense_11_output.numel = 32;
dense_11_output.shape[0] = 32;
dense_11_output.shape[1] = 1;
dense_11_output.shape[2] = 1;
dense_11_output.shape[3] = 1;
dense_11_output.shape[4] = 1;
// k2c_tensor dense_11_kernel = {dense_11_kernel_array,2,1024,{32,32, 1, 1, 1}}; 
k2c_tensor dense_11_kernel;
for(i=0;i<1024;i++){
    dense_11_kernel.array[i] = dense_11_kernel_array[i];
}
dense_11_kernel.ndim = 2;
dense_11_kernel.numel = 1024;
dense_11_kernel.shape[0] = 32;
dense_11_kernel.shape[1] = 32;
dense_11_kernel.shape[2] = 1;
dense_11_kernel.shape[3] = 1;
dense_11_kernel.shape[4] = 1;
// k2c_tensor dense_11_bias = {dense_11_bias_array,1,32,{32, 1, 1, 1, 1}}; 
k2c_tensor dense_11_bias;
for(i=0;i<32;i++){
    dense_11_bias.array[i] = dense_11_bias_array[i];
}
dense_11_bias.ndim = 1;
dense_11_bias.numel = 32;
dense_11_bias.shape[0] = 32;
dense_11_bias.shape[1] = 1;
dense_11_bias.shape[2] = 1;
dense_11_bias.shape[3] = 1;
dense_11_bias.shape[4] = 1;
float dense_11_fwork[1056] = {0}; 

 
// k2c_tensor dense_12_kernel = {dense_12_kernel_array,2,160,{32, 5, 1, 1, 1}}; 
k2c_tensor dense_12_kernel;
    for (i = 0; i < 160; i++) {
        dense_12_kernel.array[i] = dense_12_kernel_array[i];
    }
    dense_12_kernel.numel = 160;
    dense_12_kernel.shape[0] = 32;
    dense_12_kernel.ndim = 2;
    dense_12_kernel.shape[1] = 5;
    dense_12_kernel.shape[2] = 1;
    dense_12_kernel.shape[3] = 1;
    dense_12_kernel.shape[4] = 1;
// k2c_tensor dense_12_bias = {dense_12_bias_array,1,5,{5,1,1,1,1}}; 
k2c_tensor dense_12_bias;
    for (i = 0; i < 5; i++) {
        dense_12_bias.array[i] = dense_12_bias_array[i];
    }
    dense_12_bias.numel = 5;
    dense_12_bias.shape[0] = 5;
    dense_12_bias.ndim = 1;
    dense_12_bias.shape[1] = 1;
    dense_12_bias.shape[2] = 1;
    dense_12_bias.shape[3] = 1;
    dense_12_bias.shape[4] = 1;
float dense_12_fwork[192] = {0}; 

 
k2c_dense(dense_7_output,dense_7_input_input,&dense_7_kernel, 
	&dense_7_bias,2,dense_7_fwork); 
k2c_dense(dense_8_output,dense_7_output,&dense_8_kernel, 
	&dense_8_bias,2,dense_8_fwork); 
k2c_dense(dense_9_output,dense_8_output,&dense_9_kernel, 
	&dense_9_bias,2,dense_9_fwork); 
k2c_dense(dense_10_output,dense_9_output,&dense_10_kernel, 
	&dense_10_bias,2,dense_10_fwork); 
k2c_dense(dense_11_output,dense_10_output,&dense_11_kernel, 
	&dense_11_bias,2,dense_11_fwork); 
k2c_dense(dense_12_output,dense_11_output,&dense_12_kernel, 
	&dense_12_bias,6,dense_12_fwork); 

 } 

void new_cfile_initialize(float** dense_7_output_array 
,float** dense_7_kernel_array 
,float** dense_7_bias_array 
,float** dense_8_output_array 
,float** dense_8_kernel_array 
,float** dense_8_bias_array 
,float** dense_9_output_array 
,float** dense_9_kernel_array 
,float** dense_9_bias_array 
,float** dense_10_output_array 
,float** dense_10_kernel_array 
,float** dense_10_bias_array 
,float** dense_11_output_array 
,float** dense_11_kernel_array 
,float** dense_11_bias_array 
,float** dense_12_kernel_array 
,float** dense_12_bias_array 
) { 

*dense_7_output_array = k2c_read_array("new_cfiledense_7_output_array.csv",128); 
*dense_7_kernel_array = k2c_read_array("new_cfiledense_7_kernel_array.csv",16384); 
*dense_7_bias_array = k2c_read_array("new_cfiledense_7_bias_array.csv",128); 
*dense_8_output_array = k2c_read_array("new_cfiledense_8_output_array.csv",64); 
*dense_8_kernel_array = k2c_read_array("new_cfiledense_8_kernel_array.csv",8192); 
*dense_8_bias_array = k2c_read_array("new_cfiledense_8_bias_array.csv",64); 
*dense_9_output_array = k2c_read_array("new_cfiledense_9_output_array.csv",64); 
*dense_9_kernel_array = k2c_read_array("new_cfiledense_9_kernel_array.csv",4096); 
*dense_9_bias_array = k2c_read_array("new_cfiledense_9_bias_array.csv",64); 
*dense_10_output_array = k2c_read_array("new_cfiledense_10_output_array.csv",32); 
*dense_10_kernel_array = k2c_read_array("new_cfiledense_10_kernel_array.csv",2048); 
*dense_10_bias_array = k2c_read_array("new_cfiledense_10_bias_array.csv",32); 
*dense_11_output_array = k2c_read_array("new_cfiledense_11_output_array.csv",32); 
*dense_11_kernel_array = k2c_read_array("new_cfiledense_11_kernel_array.csv",1024); 
*dense_11_bias_array = k2c_read_array("new_cfiledense_11_bias_array.csv",32); 
*dense_12_kernel_array = k2c_read_array("new_cfiledense_12_kernel_array.csv",160); 
*dense_12_bias_array = k2c_read_array("new_cfiledense_12_bias_array.csv",5); 
} 

void new_cfile_terminate(float* dense_7_output_array,float* dense_7_kernel_array,float* dense_7_bias_array,float* dense_8_output_array,float* dense_8_kernel_array,float* dense_8_bias_array,float* dense_9_output_array,float* dense_9_kernel_array,float* dense_9_bias_array,float* dense_10_output_array,float* dense_10_kernel_array,float* dense_10_bias_array,float* dense_11_output_array,float* dense_11_kernel_array,float* dense_11_bias_array,float* dense_12_kernel_array,float* dense_12_bias_array) { 

free(dense_7_output_array); 
free(dense_7_kernel_array); 
free(dense_7_bias_array); 
free(dense_8_output_array); 
free(dense_8_kernel_array); 
free(dense_8_bias_array); 
free(dense_9_output_array); 
free(dense_9_kernel_array); 
free(dense_9_bias_array); 
free(dense_10_output_array); 
free(dense_10_kernel_array); 
free(dense_10_bias_array); 
free(dense_11_output_array); 
free(dense_11_kernel_array); 
free(dense_11_bias_array); 
free(dense_12_kernel_array); 
free(dense_12_bias_array); 
} 

