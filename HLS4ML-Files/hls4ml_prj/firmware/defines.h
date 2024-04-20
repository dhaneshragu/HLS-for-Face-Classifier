#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

// hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 2622
#define N_LAYER_2 100
#define N_LAYER_2 100
#define N_LAYER_6 10
#define N_LAYER_6 10
#define N_LAYER_10 6
#define N_LAYER_10 6

// hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> layer2_t;
typedef ap_uint<1> layer2_index;
typedef ap_fixed<16,6> layer5_t;
typedef ap_fixed<18,8> activation_1_table_t;
typedef ap_fixed<16,6> layer6_t;
typedef ap_uint<1> layer6_index;
typedef ap_fixed<16,6> layer9_t;
typedef ap_fixed<18,8> activation_2_table_t;
typedef ap_fixed<16,6> layer10_t;
typedef ap_uint<1> layer10_index;
typedef ap_fixed<16,6> result_t;
typedef ap_fixed<18,8> activation_3_table_t;
typedef ap_fixed<18,8,AP_RND,AP_SAT> activation_3_exp_table_t;
typedef ap_fixed<18,8,AP_RND,AP_SAT> activation_3_inv_table_t;

#endif
