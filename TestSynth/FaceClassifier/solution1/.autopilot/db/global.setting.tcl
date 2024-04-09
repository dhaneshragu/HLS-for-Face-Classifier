
set TopModule "face_classifier_c"
set ClockPeriod "100.000000"
set ClockList {ap_clk}
set multiClockList {}
set PortClockMap {}
set CombLogicFlag 0
set PipelineFlag 0
set DataflowTaskPipelineFlag  1
set TrivialPipelineFlag 0
set noPortSwitchingFlag 0
set FloatingPointFlag 1
set FftOrFirFlag 0
set NbRWValue 0
set intNbAccess 0
set NewDSPMapping 1
set HasDSPModule 1
set ResetLevelFlag 1
set ResetStyle "control"
set ResetSyncFlag 1
set ResetRegisterFlag 0
set ResetVariableFlag 0
set fsmEncStyle "onehot"
set maxFanout "0"
set RtlPrefix ""
set ExtraCCFlags ""
set ExtraCLdFlags ""
set SynCheckOptions ""
set PresynOptions ""
set PreprocOptions ""
set SchedOptions ""
set BindOptions ""
set RtlGenOptions ""
set RtlWriterOptions ""
set CbcGenFlag ""
set CasGenFlag ""
set CasMonitorFlag ""
set AutoSimOptions {}
set ExportMCPathFlag "0"
set SCTraceFileName "mytrace"
set SCTraceFileFormat "vcd"
set SCTraceOption "all"
set TargetInfo "xa7a12t:csg325:-1q"
set SourceFiles {sc {} c {../../../C-Code-Original/include/k2c_recurrent_layers.c ../../../C-Code-Original/include/k2c_pooling_layers.c ../../../C-Code-Original/include/k2c_normalization_layers.c ../../../C-Code-Original/include/k2c_merge_layers.c ../../../C-Code-Original/include/k2c_helper_functions.c ../../../C-Code-Original/include/k2c_embedding_layers.c ../../../C-Code-Original/include/k2c_core_layers.c ../../../C-Code-Original/include/k2c_convolution_layers.c ../../../C-Code-Original/include/k2c_activations.c ../../../C-Code-Original/face_classifier_c.c}}
set SourceFlags {sc {} c {{} {} {} {} {} {} {} {} {} {}}}
set DirectiveFile {C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/solution1.directive}
set TBFiles {verilog ../../../C-Code-Original/face_classifier_c_test_suite.c bc ../../../C-Code-Original/face_classifier_c_test_suite.c vhdl ../../../C-Code-Original/face_classifier_c_test_suite.c sc ../../../C-Code-Original/face_classifier_c_test_suite.c cas ../../../C-Code-Original/face_classifier_c_test_suite.c c {}}
set SpecLanguage "C"
set TVInFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TVOutFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TBTops {verilog {} bc {} vhdl {} sc {} cas {} c {}}
set TBInstNames {verilog {} bc {} vhdl {} sc {} cas {} c {}}
set XDCFiles {}
set ExtraGlobalOptions {"area_timing" 1 "clock_gate" 1 "impl_flow" map "power_gate" 0}
set PlatformFiles {{DefaultPlatform {xilinx/aartix7/aartix7 xilinx/aartix7/aartix7_fpv6}}}
set DefaultPlatform "DefaultPlatform"
set TBTVFileNotFound ""
set AppFile "../vivado_hls.app"
set ApsFile "solution1.aps"
set AvePath "../.."
set HPFPO "0"
