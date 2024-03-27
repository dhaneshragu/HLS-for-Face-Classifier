############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project FaceClassifier
set_top face_classifier_c
add_files ../C-Code-Original/face_classifier_c.c
add_files ../C-Code-Original/face_classifier_c.h
add_files ../C-Code-Original/include/k2c_activations.c
add_files ../C-Code-Original/include/k2c_activations.o
add_files ../C-Code-Original/include/k2c_convolution_layers.c
add_files ../C-Code-Original/include/k2c_convolution_layers.o
add_files ../C-Code-Original/include/k2c_core_layers.c
add_files ../C-Code-Original/include/k2c_core_layers.o
add_files ../C-Code-Original/include/k2c_embedding_layers.c
add_files ../C-Code-Original/include/k2c_embedding_layers.o
add_files ../C-Code-Original/include/k2c_helper_functions.c
add_files ../C-Code-Original/include/k2c_helper_functions.o
add_files ../C-Code-Original/include/k2c_include.h
add_files ../C-Code-Original/include/k2c_merge_layers.c
add_files ../C-Code-Original/include/k2c_merge_layers.o
add_files ../C-Code-Original/include/k2c_normalization_layers.c
add_files ../C-Code-Original/include/k2c_normalization_layers.o
add_files ../C-Code-Original/include/k2c_pooling_layers.c
add_files ../C-Code-Original/include/k2c_pooling_layers.o
add_files ../C-Code-Original/include/k2c_recurrent_layers.c
add_files ../C-Code-Original/include/k2c_recurrent_layers.o
add_files ../C-Code-Original/include/k2c_tensor_include.h
add_files ../C-Code-Original/include/libkeras2c.a
add_files ../C-Code-Original/face_classifier_c.c
add_files ../C-Code-Original/face_classifier_c.h
add_files ../C-Code-Original/include/k2c_activations.c
add_files ../C-Code-Original/include/k2c_activations.o
add_files ../C-Code-Original/include/k2c_convolution_layers.c
add_files ../C-Code-Original/include/k2c_convolution_layers.o
add_files ../C-Code-Original/include/k2c_core_layers.c
add_files ../C-Code-Original/include/k2c_core_layers.o
add_files ../C-Code-Original/include/k2c_embedding_layers.c
add_files ../C-Code-Original/include/k2c_embedding_layers.o
add_files ../C-Code-Original/include/k2c_helper_functions.c
add_files ../C-Code-Original/include/k2c_helper_functions.o
add_files ../C-Code-Original/include/k2c_include.h
add_files ../C-Code-Original/include/k2c_merge_layers.c
add_files ../C-Code-Original/include/k2c_merge_layers.o
add_files ../C-Code-Original/include/k2c_normalization_layers.c
add_files ../C-Code-Original/include/k2c_normalization_layers.o
add_files ../C-Code-Original/include/k2c_pooling_layers.c
add_files ../C-Code-Original/include/k2c_pooling_layers.o
add_files ../C-Code-Original/include/k2c_recurrent_layers.c
add_files ../C-Code-Original/include/k2c_recurrent_layers.o
add_files ../C-Code-Original/include/k2c_tensor_include.h
add_files ../C-Code-Original/include/libkeras2c.a
add_files -tb ../C-Code-Original/face_classifier_c_test_suite.c
add_files -tb ../C-Code-Original/face_classifier_c_test_suite.c
open_solution "solution1"
set_part {xa7a12tcsg325-1q}
create_clock -period 10 -name default
#source "./FaceClassifier/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
