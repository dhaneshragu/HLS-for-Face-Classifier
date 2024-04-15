#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

// hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 36
#define N_INPUT_2_1 36
#define N_INPUT_3_1 3
#define OUT_HEIGHT_2 36
#define OUT_WIDTH_2 36
#define N_FILT_2 80
#define OUT_HEIGHT_2 36
#define OUT_WIDTH_2 36
#define N_FILT_2 80
#define OUT_HEIGHT_4 18
#define OUT_WIDTH_4 18
#define N_FILT_4 80
#define OUT_HEIGHT_5 18
#define OUT_WIDTH_5 18
#define N_FILT_5 64
#define OUT_HEIGHT_5 18
#define OUT_WIDTH_5 18
#define N_FILT_5 64
#define OUT_HEIGHT_7 9
#define OUT_WIDTH_7 9
#define N_FILT_7 64
#define OUT_HEIGHT_8 9
#define OUT_WIDTH_8 9
#define N_FILT_8 40
#define OUT_HEIGHT_8 9
#define OUT_WIDTH_8 9
#define N_FILT_8 40
#define OUT_HEIGHT_10 4
#define OUT_WIDTH_10 4
#define N_FILT_10 40
#define OUT_HEIGHT_11 4
#define OUT_WIDTH_11 4
#define N_FILT_11 20
#define OUT_HEIGHT_11 4
#define OUT_WIDTH_11 4
#define N_FILT_11 20
#define OUT_HEIGHT_13 2
#define OUT_WIDTH_13 2
#define N_FILT_13 20
#define N_SIZE_0_14 80
#define N_LAYER_15 64
#define N_LAYER_15 64
#define N_LAYER_17 48
#define N_LAYER_17 48
#define N_LAYER_19 2
#define N_LAYER_19 2

// hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> layer2_t;
typedef ap_fixed<16,6> layer3_t;
typedef ap_fixed<18,8> conv2d_relu_table_t;
typedef ap_fixed<16,6> layer4_t;
typedef ap_fixed<16,6> layer5_t;
typedef ap_fixed<16,6> layer6_t;
typedef ap_fixed<18,8> conv2d_1_relu_table_t;
typedef ap_fixed<16,6> layer7_t;
typedef ap_fixed<16,6> layer8_t;
typedef ap_fixed<16,6> layer9_t;
typedef ap_fixed<18,8> conv2d_2_relu_table_t;
typedef ap_fixed<16,6> layer10_t;
typedef ap_fixed<16,6> layer11_t;
typedef ap_fixed<16,6> layer12_t;
typedef ap_fixed<18,8> conv2d_3_relu_table_t;
typedef ap_fixed<16,6> layer13_t;
typedef ap_fixed<16,6> layer15_t;
typedef ap_uint<1> layer15_index;
typedef ap_fixed<16,6> layer16_t;
typedef ap_fixed<18,8> dense_relu_table_t;
typedef ap_fixed<16,6> layer17_t;
typedef ap_uint<1> layer17_index;
typedef ap_fixed<16,6> layer18_t;
typedef ap_fixed<18,8> dense_1_relu_table_t;
typedef ap_fixed<16,6> layer19_t;
typedef ap_uint<1> layer19_index;
typedef ap_fixed<16,6> result_t;
typedef ap_fixed<18,8> dense_2_sigmoid_table_t;

#endif
