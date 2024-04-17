############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project FaceClassifier
set_top face_classifier_c
add_files ../C-Code-Original/include/k2c_tensor_include.h -cflags "-Wuninitialized -Wall"
add_files ../C-Code-Original/include/k2c_recurrent_layers.c
add_files ../C-Code-Original/include/k2c_pooling_layers.c
add_files ../C-Code-Original/include/k2c_normalization_layers.c
add_files ../C-Code-Original/include/k2c_merge_layers.c
add_files ../C-Code-Original/include/k2c_include.h
add_files ../C-Code-Original/include/k2c_helper_functions.c -cflags "-Wuninitialized -Wall"
add_files ../C-Code-Original/include/k2c_embedding_layers.c
add_files ../C-Code-Original/include/k2c_core_layers.c
add_files ../C-Code-Original/include/k2c_convolution_layers.c
add_files ../C-Code-Original/include/k2c_activations.c -cflags "-Wuninitialized -Wall"
add_files ../C-Code-Original/face_classifier_c.h -cflags "-Wuninitialized -Wall"
add_files ../C-Code-Original/face_classifier_c.c -cflags "-Wuninitialized -Wall"
add_files -tb ../C-Code-Original/face_classifier_c_test_suite.c -cflags "-Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas"
open_solution "solution1"
set_part {xcvu160-flgc2104-2-e}
create_clock -period 10 -name default
#source "./FaceClassifier/solution1/directives.tcl"
csim_design -ldflags {-Wl,--stack,16777216} -clean
csynth_design
cosim_design -ldflags {-Wl,--stack,16777216}
export_design -rtl verilog -format ip_catalog
