#include <iostream>

#include "myproject.h"
#include "parameters.h"

void myproject(
    input_t dense_input[N_INPUT_1_1],
    result_t layer12_out[N_LAYER_10]
) {

    // hls-fpga-machine-learning insert IO
 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        // hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 262200>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 100>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_default_t, 1000>(w6, "w6.txt");
        nnet::load_weights_from_txt<model_default_t, 10>(b6, "b6.txt");
        nnet::load_weights_from_txt<model_default_t, 60>(w10, "w10.txt");
        nnet::load_weights_from_txt<model_default_t, 6>(b10, "b10.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    // hls-fpga-machine-learning insert layers

    layer2_t layer2_out[N_LAYER_2];
   
    nnet::dense<input_t, layer2_t, config2>(dense_input, layer2_out, w2, b2); // dense

    layer5_t layer5_out[N_LAYER_2];
   
    nnet::tanh<layer2_t, layer5_t, tanh_config5>(layer2_out, layer5_out); // activation_1

    layer6_t layer6_out[N_LAYER_6];
   
    nnet::dense<layer5_t, layer6_t, config6>(layer5_out, layer6_out, w6, b6); // dense_1

    layer9_t layer9_out[N_LAYER_6];
   
    nnet::tanh<layer6_t, layer9_t, tanh_config9>(layer6_out, layer9_out); // activation_2

    layer10_t layer10_out[N_LAYER_10];
   
    nnet::dense<layer9_t, layer10_t, config10>(layer9_out, layer10_out, w10, b10); // dense_2

    nnet::softmax<layer10_t, result_t, softmax_config12>(layer10_out, layer12_out); // activation_3

}
