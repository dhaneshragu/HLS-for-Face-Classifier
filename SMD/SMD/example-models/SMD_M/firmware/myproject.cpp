#include <iostream>

#include "myproject.h"
#include "parameters.h"

void myproject(
    input_t conv2d_input[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1],
    result_t layer20_out[N_LAYER_19]
) {

    // hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=conv2d_input complete dim=0
    #pragma HLS ARRAY_PARTITION variable=layer20_out complete dim=0
    #pragma HLS INTERFACE ap_vld port=conv2d_input,layer20_out 
    #pragma HLS DATAFLOW 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        // hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 2160>(w2, "w2.txt");
        nnet::load_weights_from_txt<model_default_t, 80>(b2, "b2.txt");
        nnet::load_weights_from_txt<model_default_t, 46080>(w5, "w5.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b5, "b5.txt");
        nnet::load_weights_from_txt<model_default_t, 23040>(w8, "w8.txt");
        nnet::load_weights_from_txt<model_default_t, 40>(b8, "b8.txt");
        nnet::load_weights_from_txt<model_default_t, 7200>(w11, "w11.txt");
        nnet::load_weights_from_txt<model_default_t, 20>(b11, "b11.txt");
        nnet::load_weights_from_txt<model_default_t, 5120>(w15, "w15.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b15, "b15.txt");
        nnet::load_weights_from_txt<model_default_t, 3072>(w17, "w17.txt");
        nnet::load_weights_from_txt<model_default_t, 48>(b17, "b17.txt");
        nnet::load_weights_from_txt<model_default_t, 96>(w19, "w19.txt");
        nnet::load_weights_from_txt<model_default_t, 2>(b19, "b19.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    // hls-fpga-machine-learning insert layers

    layer2_t layer2_out[OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2];
    #pragma HLS ARRAY_PARTITION variable=layer2_out complete dim=0
    nnet::conv_2d_cl<input_t, layer2_t, config2>(conv2d_input, layer2_out, w2, b2); // conv2d

    layer3_t layer3_out[OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2];
    #pragma HLS ARRAY_PARTITION variable=layer3_out complete dim=0
    nnet::relu<layer2_t, layer3_t, relu_config3>(layer2_out, layer3_out); // conv2d_relu

    layer4_t layer4_out[OUT_HEIGHT_4*OUT_WIDTH_4*N_FILT_4];
    #pragma HLS ARRAY_PARTITION variable=layer4_out complete dim=0
    nnet::pooling2d_cl<layer3_t, layer4_t, config4>(layer3_out, layer4_out); // max_pooling2d

    layer5_t layer5_out[OUT_HEIGHT_5*OUT_WIDTH_5*N_FILT_5];
    #pragma HLS ARRAY_PARTITION variable=layer5_out complete dim=0
    nnet::conv_2d_cl<layer4_t, layer5_t, config5>(layer4_out, layer5_out, w5, b5); // conv2d_1

    layer6_t layer6_out[OUT_HEIGHT_5*OUT_WIDTH_5*N_FILT_5];
    #pragma HLS ARRAY_PARTITION variable=layer6_out complete dim=0
    nnet::relu<layer5_t, layer6_t, relu_config6>(layer5_out, layer6_out); // conv2d_1_relu

    layer7_t layer7_out[OUT_HEIGHT_7*OUT_WIDTH_7*N_FILT_7];
    #pragma HLS ARRAY_PARTITION variable=layer7_out complete dim=0
    nnet::pooling2d_cl<layer6_t, layer7_t, config7>(layer6_out, layer7_out); // max_pooling2d_1

    layer8_t layer8_out[OUT_HEIGHT_8*OUT_WIDTH_8*N_FILT_8];
    #pragma HLS ARRAY_PARTITION variable=layer8_out complete dim=0
    nnet::conv_2d_cl<layer7_t, layer8_t, config8>(layer7_out, layer8_out, w8, b8); // conv2d_2

    layer9_t layer9_out[OUT_HEIGHT_8*OUT_WIDTH_8*N_FILT_8];
    #pragma HLS ARRAY_PARTITION variable=layer9_out complete dim=0
    nnet::relu<layer8_t, layer9_t, relu_config9>(layer8_out, layer9_out); // conv2d_2_relu

    layer10_t layer10_out[OUT_HEIGHT_10*OUT_WIDTH_10*N_FILT_10];
    #pragma HLS ARRAY_PARTITION variable=layer10_out complete dim=0
    nnet::pooling2d_cl<layer9_t, layer10_t, config10>(layer9_out, layer10_out); // max_pooling2d_2

    layer11_t layer11_out[OUT_HEIGHT_11*OUT_WIDTH_11*N_FILT_11];
    #pragma HLS ARRAY_PARTITION variable=layer11_out complete dim=0
    nnet::conv_2d_cl<layer10_t, layer11_t, config11>(layer10_out, layer11_out, w11, b11); // conv2d_3

    layer12_t layer12_out[OUT_HEIGHT_11*OUT_WIDTH_11*N_FILT_11];
    #pragma HLS ARRAY_PARTITION variable=layer12_out complete dim=0
    nnet::relu<layer11_t, layer12_t, relu_config12>(layer11_out, layer12_out); // conv2d_3_relu

    layer13_t layer13_out[OUT_HEIGHT_13*OUT_WIDTH_13*N_FILT_13];
    #pragma HLS ARRAY_PARTITION variable=layer13_out complete dim=0
    nnet::pooling2d_cl<layer12_t, layer13_t, config13>(layer12_out, layer13_out); // max_pooling2d_3

    auto& layer14_out = layer13_out;
    layer15_t layer15_out[N_LAYER_15];
    #pragma HLS ARRAY_PARTITION variable=layer15_out complete dim=0
    nnet::dense<layer13_t, layer15_t, config15>(layer14_out, layer15_out, w15, b15); // dense

    layer16_t layer16_out[N_LAYER_15];
    #pragma HLS ARRAY_PARTITION variable=layer16_out complete dim=0
    nnet::relu<layer15_t, layer16_t, relu_config16>(layer15_out, layer16_out); // dense_relu

    layer17_t layer17_out[N_LAYER_17];
    #pragma HLS ARRAY_PARTITION variable=layer17_out complete dim=0
    nnet::dense<layer16_t, layer17_t, config17>(layer16_out, layer17_out, w17, b17); // dense_1

    layer18_t layer18_out[N_LAYER_17];
    #pragma HLS ARRAY_PARTITION variable=layer18_out complete dim=0
    nnet::relu<layer17_t, layer18_t, relu_config18>(layer17_out, layer18_out); // dense_1_relu

    layer19_t layer19_out[N_LAYER_19];
    #pragma HLS ARRAY_PARTITION variable=layer19_out complete dim=0
    nnet::dense<layer18_t, layer19_t, config19>(layer18_out, layer19_out, w19, b19); // dense_2

    nnet::sigmoid<layer19_t, result_t, sigmoid_config20>(layer19_out, layer20_out); // dense_2_sigmoid

}
