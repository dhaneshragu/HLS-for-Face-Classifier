set C_TypeInfoList {{ 
"face_classifier_c" : [[], { "return": [[], "void"]} , [{"ExternC" : 0}], [ {"dense_input_input": [["const"],"0"] }, {"activation_3_output": [[],{ "pointer": "1"}] }],["2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24"],""],
 "2": [ "dropout_3_output", [[],"1"],""],
 "3": [ "dropout_2_output", [[],"1"],""],
 "4": [ "dense_output", [[],"1"],""],
 "5": [ "dense_kernel", [[],"25"],""],
 "6": [ "dense_bias", [[],"1"],""],
 "7": [ "dense_2_output", [[],"1"],""],
 "8": [ "dense_2_kernel", [[],"1"],""],
 "9": [ "dense_2_bias", [[],"1"],""],
 "10": [ "dense_1_output", [[],"1"],""],
 "11": [ "dense_1_kernel", [[],"25"],""],
 "12": [ "dense_1_bias", [[],"1"],""],
 "13": [ "batch_normalization_stdev", [[],"1"],""],
 "14": [ "batch_normalization_output", [[],"1"],""],
 "15": [ "batch_normalization_mean", [[],"1"],""],
 "16": [ "batch_normalization_gamma", [[],"1"],""],
 "17": [ "batch_normalization_beta", [[],"1"],""],
 "18": [ "batch_normalization_1_stdev", [[],"1"],""],
 "19": [ "batch_normalization_1_output", [[],"1"],""],
 "20": [ "batch_normalization_1_mean", [[],"1"],""],
 "21": [ "batch_normalization_1_gamma", [[],"1"],""],
 "22": [ "batch_normalization_1_beta", [[],"1"],""],
 "23": [ "activation_2_output", [[],"1"],""],
 "24": [ "activation_1_output", [[],"1"],""], 
"25": [ "k2c_tensor", {"typedef": [[[],"26"],""]}], 
"26": [ "k2c_tensor", {"struct": [[],[],[{ "array": [[],  {"array": [ {"scalar": "float"}, [262200]]}]},{ "ndim": [[64], "27"]},{ "numel": [[64], "27"]},{ "shape": [[],  {"array": ["27", [5]]}]}],""]}], 
"27": [ "size_t", {"typedef": [[[], {"scalar": "long long unsigned int"}],""]}], 
"1": [ "k2c_tensor2", {"typedef": [[[],"28"],""]}], 
"28": [ "k2c_tensor2", {"struct": [[],[],[{ "array": [[],  {"array": [ {"scalar": "float"}, [2622]]}]},{ "ndim": [[64], "27"]},{ "numel": [[64], "27"]},{ "shape": [[],  {"array": ["27", [5]]}]}],""]}], 
"0": [ "k2c_tensor2", {"typedef": [[[],"28"],""]}]
}}
set moduleName face_classifier_c
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {face_classifier_c}
set C_modelType { void 0 }
set C_modelArgList {
	{ dense_input_input_array float 32 regular {array 2622 { 1 3 } 1 1 }  }
	{ dense_input_input_ndim int 64 regular  }
	{ dense_input_input_numel int 64 regular  }
	{ dense_input_input_shape int 64 regular {array 5 { 1 3 } 1 1 }  }
	{ activation_3_output_array float 32 regular {array 2622 { 0 3 } 0 1 }  }
	{ activation_3_output_ndim int 64 regular {pointer 1}  }
	{ activation_3_output_numel int 64 regular {pointer 1}  }
	{ activation_3_output_shape int 64 regular {array 5 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "dense_input_input_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "dense_input_input.array","cData": "float","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 2621,"step" : 1}]}]}]} , 
 	{ "Name" : "dense_input_input_ndim", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY", "bitSlice":[{"low":0,"up":63,"cElement": [{"cName": "dense_input_input.ndim","cData": "long long unsigned int","bit_use": { "low": 0,"up": 63},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "dense_input_input_numel", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY", "bitSlice":[{"low":0,"up":63,"cElement": [{"cName": "dense_input_input.numel","cData": "long long unsigned int","bit_use": { "low": 0,"up": 63},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "dense_input_input_shape", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY", "bitSlice":[{"low":0,"up":63,"cElement": [{"cName": "dense_input_input.shape","cData": "long long unsigned int","bit_use": { "low": 0,"up": 63},"cArray": [{"low" : 0,"up" : 4,"step" : 1}]}]}]} , 
 	{ "Name" : "activation_3_output_array", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "activation_3_output.array","cData": "float","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 2621,"step" : 1}]}]}]} , 
 	{ "Name" : "activation_3_output_ndim", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":63,"cElement": [{"cName": "activation_3_output.ndim","cData": "long long unsigned int","bit_use": { "low": 0,"up": 63},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "activation_3_output_numel", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":63,"cElement": [{"cName": "activation_3_output.numel","cData": "long long unsigned int","bit_use": { "low": 0,"up": 63},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "activation_3_output_shape", "interface" : "memory", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":63,"cElement": [{"cName": "activation_3_output.shape","cData": "long long unsigned int","bit_use": { "low": 0,"up": 63},"cArray": [{"low" : 0,"up" : 4,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 26
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ dense_input_input_array_address0 sc_out sc_lv 12 signal 0 } 
	{ dense_input_input_array_ce0 sc_out sc_logic 1 signal 0 } 
	{ dense_input_input_array_q0 sc_in sc_lv 32 signal 0 } 
	{ dense_input_input_ndim sc_in sc_lv 64 signal 1 } 
	{ dense_input_input_numel sc_in sc_lv 64 signal 2 } 
	{ dense_input_input_shape_address0 sc_out sc_lv 3 signal 3 } 
	{ dense_input_input_shape_ce0 sc_out sc_logic 1 signal 3 } 
	{ dense_input_input_shape_q0 sc_in sc_lv 64 signal 3 } 
	{ activation_3_output_array_address0 sc_out sc_lv 12 signal 4 } 
	{ activation_3_output_array_ce0 sc_out sc_logic 1 signal 4 } 
	{ activation_3_output_array_we0 sc_out sc_logic 1 signal 4 } 
	{ activation_3_output_array_d0 sc_out sc_lv 32 signal 4 } 
	{ activation_3_output_ndim sc_out sc_lv 64 signal 5 } 
	{ activation_3_output_ndim_ap_vld sc_out sc_logic 1 outvld 5 } 
	{ activation_3_output_numel sc_out sc_lv 64 signal 6 } 
	{ activation_3_output_numel_ap_vld sc_out sc_logic 1 outvld 6 } 
	{ activation_3_output_shape_address0 sc_out sc_lv 3 signal 7 } 
	{ activation_3_output_shape_ce0 sc_out sc_logic 1 signal 7 } 
	{ activation_3_output_shape_we0 sc_out sc_logic 1 signal 7 } 
	{ activation_3_output_shape_d0 sc_out sc_lv 64 signal 7 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "dense_input_input_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "dense_input_input_array", "role": "address0" }} , 
 	{ "name": "dense_input_input_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dense_input_input_array", "role": "ce0" }} , 
 	{ "name": "dense_input_input_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dense_input_input_array", "role": "q0" }} , 
 	{ "name": "dense_input_input_ndim", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "dense_input_input_ndim", "role": "default" }} , 
 	{ "name": "dense_input_input_numel", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "dense_input_input_numel", "role": "default" }} , 
 	{ "name": "dense_input_input_shape_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "dense_input_input_shape", "role": "address0" }} , 
 	{ "name": "dense_input_input_shape_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dense_input_input_shape", "role": "ce0" }} , 
 	{ "name": "dense_input_input_shape_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "dense_input_input_shape", "role": "q0" }} , 
 	{ "name": "activation_3_output_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "activation_3_output_array", "role": "address0" }} , 
 	{ "name": "activation_3_output_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "activation_3_output_array", "role": "ce0" }} , 
 	{ "name": "activation_3_output_array_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "activation_3_output_array", "role": "we0" }} , 
 	{ "name": "activation_3_output_array_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "activation_3_output_array", "role": "d0" }} , 
 	{ "name": "activation_3_output_ndim", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "activation_3_output_ndim", "role": "default" }} , 
 	{ "name": "activation_3_output_ndim_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "activation_3_output_ndim", "role": "ap_vld" }} , 
 	{ "name": "activation_3_output_numel", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "activation_3_output_numel", "role": "default" }} , 
 	{ "name": "activation_3_output_numel_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "activation_3_output_numel", "role": "ap_vld" }} , 
 	{ "name": "activation_3_output_shape_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "activation_3_output_shape", "role": "address0" }} , 
 	{ "name": "activation_3_output_shape_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "activation_3_output_shape", "role": "ce0" }} , 
 	{ "name": "activation_3_output_shape_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "activation_3_output_shape", "role": "we0" }} , 
 	{ "name": "activation_3_output_shape_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "activation_3_output_shape", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "80", "105", "132", "138", "154", "155", "156", "157", "158"],
		"CDFG" : "face_classifier_c",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state126", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_dense_1_fu_1846"},
			{"State" : "ap_ST_fsm_state75", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_dense_fu_1869"},
			{"State" : "ap_ST_fsm_state177", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_dense2_fu_1888"},
			{"State" : "ap_ST_fsm_state77", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_batch_norm_fu_1917"},
			{"State" : "ap_ST_fsm_state128", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_batch_norm_fu_1917"}],
		"Port" : [
			{"Name" : "dense_input_input_array", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "80", "SubInstance" : "grp_k2c_dense_fu_1869", "Port" : "input_array"}]},
			{"Name" : "dense_input_input_ndim", "Type" : "None", "Direction" : "I"},
			{"Name" : "dense_input_input_numel", "Type" : "None", "Direction" : "I"},
			{"Name" : "dense_input_input_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "80", "SubInstance" : "grp_k2c_dense_fu_1869", "Port" : "input_shape"}]},
			{"Name" : "activation_3_output_array", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "activation_3_output_ndim", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "activation_3_output_numel", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "activation_3_output_shape", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "dense_output_numel", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "dense_output_array", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "inputs_array"},
					{"ID" : "80", "SubInstance" : "grp_k2c_dense_fu_1869", "Port" : "output_array"}]},
			{"Name" : "face_classifier_c_de", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dense_kernel_array", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "80", "SubInstance" : "grp_k2c_dense_fu_1869", "Port" : "kernel_array"}]},
			{"Name" : "dense_bias_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dense_bias_array_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "80", "SubInstance" : "grp_k2c_dense_fu_1869", "Port" : "bias_array"}]},
			{"Name" : "batch_normalization_1", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "batch_normalization_3", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "batch_normalization_23", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "outputs_array"}]},
			{"Name" : "batch_normalization_11", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "batch_normalization_22", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "mean_array"}]},
			{"Name" : "batch_normalization_s", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "batch_normalization_18", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "stdev_array"}]},
			{"Name" : "batch_normalization_14", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "batch_normalization_21", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "gamma_array"}]},
			{"Name" : "batch_normalization_17", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "batch_normalization_19", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "beta_array"}]},
			{"Name" : "dense_1_output_numel", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "dense_1_output_array", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "53", "SubInstance" : "grp_k2c_dense_1_fu_1846", "Port" : "output_array"},
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "inputs_array"}]},
			{"Name" : "dense_1_kernel_ndim", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "dense_1_kernel_numel", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "dense_1_kernel_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dense_1_kernel_array_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "53", "SubInstance" : "grp_k2c_dense_1_fu_1846", "Port" : "kernel_array"}]},
			{"Name" : "dense_1_bias_numel", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "dense_1_bias_array2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dense_1_bias_array", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "53", "SubInstance" : "grp_k2c_dense_1_fu_1846", "Port" : "bias_array"}]},
			{"Name" : "batch_normalization_9", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "batch_normalization_8", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "outputs_array"}]},
			{"Name" : "batch_normalization_29", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "batch_normalization_7", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "mean_array"}]},
			{"Name" : "batch_normalization_20", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "batch_normalization_15", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "stdev_array"}]},
			{"Name" : "batch_normalization_32", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "batch_normalization_6", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "gamma_array"}]},
			{"Name" : "batch_normalization_35", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "batch_normalization_5", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "beta_array"}]},
			{"Name" : "dense_2_output_ndim", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "dense_2_output_numel", "Type" : "OVld", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dense_2_output_numel"}]},
			{"Name" : "dense_2_output_array", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dense_2_output_array"}]},
			{"Name" : "dense_2_kernel_ndim", "Type" : "OVld", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dense_2_kernel_ndim"}]},
			{"Name" : "dense_2_kernel_numel", "Type" : "OVld", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dense_2_kernel_numel"}]},
			{"Name" : "dense_2_kernel_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dense_2_kernel_array_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dense_2_kernel_array_2"}]},
			{"Name" : "dense_2_bias_numel", "Type" : "OVld", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dense_2_bias_numel"}]},
			{"Name" : "dense_2_bias_array7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dense_2_bias_array", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dense_2_bias_array"}]},
			{"Name" : "dense_kernel_shape", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "80", "SubInstance" : "grp_k2c_dense_fu_1869", "Port" : "kernel_shape"}]},
			{"Name" : "dense_output_shape", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "inputs_shape"}]},
			{"Name" : "table_exp_Z1_array_s", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "138", "SubInstance" : "grp_generic_tanh_float_s_fu_1943", "Port" : "table_exp_Z1_array_s"}]},
			{"Name" : "table_f_Z3_array_V", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "138", "SubInstance" : "grp_generic_tanh_float_s_fu_1943", "Port" : "table_f_Z3_array_V"}]},
			{"Name" : "table_f_Z2_array_V", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "138", "SubInstance" : "grp_generic_tanh_float_s_fu_1943", "Port" : "table_f_Z2_array_V"}]},
			{"Name" : "batch_normalization_4", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "activation_1_output_s", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "activation_1_output_1", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "dropout_2_output_sha", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "53", "SubInstance" : "grp_k2c_dense_1_fu_1846", "Port" : "input_shape"}]},
			{"Name" : "dropout_2_output_arr", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "53", "SubInstance" : "grp_k2c_dense_1_fu_1846", "Port" : "input_array"}]},
			{"Name" : "dense_1_kernel_shape", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "53", "SubInstance" : "grp_k2c_dense_1_fu_1846", "Port" : "kernel_shape"}]},
			{"Name" : "dense_1_output_shape", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "132", "SubInstance" : "grp_k2c_batch_norm_fu_1917", "Port" : "inputs_shape"}]},
			{"Name" : "batch_normalization_12", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "activation_2_output_s", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "activation_2_output_1", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "dropout_3_output_ndi", "Type" : "OVld", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dropout_3_output_ndi"}]},
			{"Name" : "dropout_3_output_num", "Type" : "OVld", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dropout_3_output_num"}]},
			{"Name" : "dropout_3_output_sha", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dropout_3_output_sha"}]},
			{"Name" : "dropout_3_output_arr", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dropout_3_output_arr"}]},
			{"Name" : "dense_2_kernel_shape", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "105", "SubInstance" : "grp_k2c_dense2_fu_1888", "Port" : "dense_2_kernel_shape"}]},
			{"Name" : "dense_2_output_shape", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_output_array_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_c_de_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_kernel_array_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_bias_array_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_bias_array_0_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_23_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_11_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_22_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_s_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_18_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_14_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_21_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_17_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_19_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_1_output_array_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_1_kernel_array_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_1_kernel_array_1_U", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_1_bias_array2_U", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_1_bias_array_U", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_8_U", "Parent" : "0"},
	{"ID" : "21", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_29_U", "Parent" : "0"},
	{"ID" : "22", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_7_U", "Parent" : "0"},
	{"ID" : "23", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_20_U", "Parent" : "0"},
	{"ID" : "24", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_15_U", "Parent" : "0"},
	{"ID" : "25", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_32_U", "Parent" : "0"},
	{"ID" : "26", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_6_U", "Parent" : "0"},
	{"ID" : "27", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_35_U", "Parent" : "0"},
	{"ID" : "28", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_5_U", "Parent" : "0"},
	{"ID" : "29", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_2_output_array_U", "Parent" : "0"},
	{"ID" : "30", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_2_kernel_array_U", "Parent" : "0"},
	{"ID" : "31", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_2_kernel_array_2_U", "Parent" : "0"},
	{"ID" : "32", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_2_bias_array7_U", "Parent" : "0"},
	{"ID" : "33", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_2_bias_array_U", "Parent" : "0"},
	{"ID" : "34", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_kernel_shape_U", "Parent" : "0"},
	{"ID" : "35", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_output_shape_U", "Parent" : "0"},
	{"ID" : "36", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_4_U", "Parent" : "0"},
	{"ID" : "37", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.activation_1_output_s_U", "Parent" : "0"},
	{"ID" : "38", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.activation_1_output_1_U", "Parent" : "0"},
	{"ID" : "39", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dropout_2_output_sha_U", "Parent" : "0"},
	{"ID" : "40", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dropout_2_output_arr_U", "Parent" : "0"},
	{"ID" : "41", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_1_kernel_shape_U", "Parent" : "0"},
	{"ID" : "42", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_1_output_shape_U", "Parent" : "0"},
	{"ID" : "43", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.batch_normalization_12_U", "Parent" : "0"},
	{"ID" : "44", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.activation_2_output_s_U", "Parent" : "0"},
	{"ID" : "45", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.activation_2_output_1_U", "Parent" : "0"},
	{"ID" : "46", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dropout_3_output_sha_U", "Parent" : "0"},
	{"ID" : "47", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dropout_3_output_arr_U", "Parent" : "0"},
	{"ID" : "48", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_2_kernel_shape_U", "Parent" : "0"},
	{"ID" : "49", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_2_output_shape_U", "Parent" : "0"},
	{"ID" : "50", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_fwork_U", "Parent" : "0"},
	{"ID" : "51", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_1_fwork_U", "Parent" : "0"},
	{"ID" : "52", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dense_2_fwork_U", "Parent" : "0"},
	{"ID" : "53", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846", "Parent" : "0", "Child" : ["54", "74", "76", "77", "78", "79"],
		"CDFG" : "k2c_dense_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state2", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_dot_fu_255"},
			{"State" : "ap_ST_fsm_state4", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_bias_add_fu_279"}],
		"Port" : [
			{"Name" : "output_array", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "54", "SubInstance" : "grp_k2c_dot_fu_255", "Port" : "C_array"},
					{"ID" : "74", "SubInstance" : "grp_k2c_bias_add_fu_279", "Port" : "A_array"}]},
			{"Name" : "output_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "input_array", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "54", "SubInstance" : "grp_k2c_dot_fu_255", "Port" : "Ar_array"}]},
			{"Name" : "input_ndim_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "input_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "input_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "54", "SubInstance" : "grp_k2c_dot_fu_255", "Port" : "Ar_shape"}]},
			{"Name" : "kernel_array", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "54", "SubInstance" : "grp_k2c_dot_fu_255", "Port" : "B_array"}]},
			{"Name" : "kernel_ndim_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "54", "SubInstance" : "grp_k2c_dot_fu_255", "Port" : "B_shape"}]},
			{"Name" : "bias_array", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "74", "SubInstance" : "grp_k2c_bias_add_fu_279", "Port" : "b_array"}]},
			{"Name" : "bias_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "fwork", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "54", "SubInstance" : "grp_k2c_dot_fu_255", "Port" : "fwork"}]}]},
	{"ID" : "54", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255", "Parent" : "53", "Child" : ["55", "56", "57", "58", "59", "60", "61", "62", "63", "66", "67", "68", "69", "70", "71", "72", "73"],
		"CDFG" : "k2c_dot",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state89", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_idx2sub_fu_647"},
			{"State" : "ap_ST_fsm_state96", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_idx2sub_fu_647"},
			{"State" : "ap_ST_fsm_state94", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_sub2idx_fu_658"},
			{"State" : "ap_ST_fsm_state101", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_sub2idx_fu_658"}],
		"Port" : [
			{"Name" : "C_array", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "Ar_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "Ar_ndim_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Ar_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Ar_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "63", "SubInstance" : "grp_k2c_idx2sub_fu_647", "Port" : "shape"}]},
			{"Name" : "B_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_ndim_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "B_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "B_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "63", "SubInstance" : "grp_k2c_idx2sub_fu_647", "Port" : "shape"}]},
			{"Name" : "axesA_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "fwork", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "55", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.permA_U", "Parent" : "54"},
	{"ID" : "56", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.permB_U", "Parent" : "54"},
	{"ID" : "57", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.freeA_U", "Parent" : "54"},
	{"ID" : "58", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.freeB_U", "Parent" : "54"},
	{"ID" : "59", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.newshpA_U", "Parent" : "54"},
	{"ID" : "60", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.newshpB_U", "Parent" : "54"},
	{"ID" : "61", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.Asub_U", "Parent" : "54"},
	{"ID" : "62", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.Bsub_U", "Parent" : "54"},
	{"ID" : "63", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.grp_k2c_idx2sub_fu_647", "Parent" : "54", "Child" : ["64", "65"],
		"CDFG" : "k2c_idx2sub",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "idx", "Type" : "None", "Direction" : "I"},
			{"Name" : "sub", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "shape", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "ndim", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "64", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.grp_k2c_idx2sub_fu_647.face_classifier_cbkb_U1", "Parent" : "63"},
	{"ID" : "65", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.grp_k2c_idx2sub_fu_647.face_classifier_ccud_U2", "Parent" : "63"},
	{"ID" : "66", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.grp_k2c_sub2idx_fu_658", "Parent" : "54",
		"CDFG" : "k2c_sub2idx",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "sub", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "shape", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "ndim", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "67", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.face_classifier_cdEe_U90", "Parent" : "54"},
	{"ID" : "68", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.face_classifier_ceOg_U91", "Parent" : "54"},
	{"ID" : "69", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.face_classifier_cfYi_U92", "Parent" : "54"},
	{"ID" : "70", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.face_classifier_cvdy_U93", "Parent" : "54"},
	{"ID" : "71", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.face_classifier_chbi_U94", "Parent" : "54"},
	{"ID" : "72", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.face_classifier_cwdI_U95", "Parent" : "54"},
	{"ID" : "73", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_dot_fu_255.face_classifier_cxdS_U96", "Parent" : "54"},
	{"ID" : "74", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_bias_add_fu_279", "Parent" : "53", "Child" : ["75"],
		"CDFG" : "k2c_bias_add",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "A_array", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "A_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "b_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "b_numel_read", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "75", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.grp_k2c_bias_add_fu_279.face_classifier_cdEe_U33", "Parent" : "74"},
	{"ID" : "76", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.face_classifier_cdEe_U111", "Parent" : "53"},
	{"ID" : "77", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.face_classifier_ceOg_U112", "Parent" : "53"},
	{"ID" : "78", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.face_classifier_chbi_U113", "Parent" : "53"},
	{"ID" : "79", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_1_fu_1846.face_classifier_cibs_U114", "Parent" : "53"},
	{"ID" : "80", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869", "Parent" : "0", "Child" : ["81", "99", "101", "102", "103", "104"],
		"CDFG" : "k2c_dense",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state2", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_dot_1_fu_225"},
			{"State" : "ap_ST_fsm_state4", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_bias_add_fu_246"}],
		"Port" : [
			{"Name" : "output_array", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "81", "SubInstance" : "grp_k2c_dot_1_fu_225", "Port" : "C_array"},
					{"ID" : "99", "SubInstance" : "grp_k2c_bias_add_fu_246", "Port" : "A_array"}]},
			{"Name" : "input_array", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "81", "SubInstance" : "grp_k2c_dot_1_fu_225", "Port" : "Ar_array"}]},
			{"Name" : "input_ndim_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "input_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "input_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "81", "SubInstance" : "grp_k2c_dot_1_fu_225", "Port" : "Ar_shape"}]},
			{"Name" : "kernel_array", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "81", "SubInstance" : "grp_k2c_dot_1_fu_225", "Port" : "B_array"}]},
			{"Name" : "kernel_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "81", "SubInstance" : "grp_k2c_dot_1_fu_225", "Port" : "B_shape"}]},
			{"Name" : "bias_array", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "99", "SubInstance" : "grp_k2c_bias_add_fu_246", "Port" : "b_array"}]},
			{"Name" : "fwork", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "81", "SubInstance" : "grp_k2c_dot_1_fu_225", "Port" : "fwork"}]}]},
	{"ID" : "81", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225", "Parent" : "80", "Child" : ["82", "83", "84", "85", "86", "87", "88", "89", "90", "93", "94", "95", "96", "97", "98"],
		"CDFG" : "k2c_dot_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state89", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_idx2sub_fu_644"},
			{"State" : "ap_ST_fsm_state96", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_idx2sub_fu_644"},
			{"State" : "ap_ST_fsm_state94", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_sub2idx_fu_656"},
			{"State" : "ap_ST_fsm_state101", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_sub2idx_fu_656"}],
		"Port" : [
			{"Name" : "C_array", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "Ar_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "Ar_ndim_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Ar_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Ar_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "90", "SubInstance" : "grp_k2c_idx2sub_fu_644", "Port" : "shape"}]},
			{"Name" : "B_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "90", "SubInstance" : "grp_k2c_idx2sub_fu_644", "Port" : "shape"}]},
			{"Name" : "p_read4", "Type" : "None", "Direction" : "I"},
			{"Name" : "fwork", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "82", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.permA_U", "Parent" : "81"},
	{"ID" : "83", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.permB_U", "Parent" : "81"},
	{"ID" : "84", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.freeA_U", "Parent" : "81"},
	{"ID" : "85", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.freeB_U", "Parent" : "81"},
	{"ID" : "86", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.newshpA_U", "Parent" : "81"},
	{"ID" : "87", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.newshpB_U", "Parent" : "81"},
	{"ID" : "88", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.Asub_U", "Parent" : "81"},
	{"ID" : "89", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.Bsub_U", "Parent" : "81"},
	{"ID" : "90", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.grp_k2c_idx2sub_fu_644", "Parent" : "81", "Child" : ["91", "92"],
		"CDFG" : "k2c_idx2sub",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "idx", "Type" : "None", "Direction" : "I"},
			{"Name" : "sub", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "shape", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "ndim", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "91", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.grp_k2c_idx2sub_fu_644.face_classifier_cbkb_U1", "Parent" : "90"},
	{"ID" : "92", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.grp_k2c_idx2sub_fu_644.face_classifier_ccud_U2", "Parent" : "90"},
	{"ID" : "93", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.grp_k2c_sub2idx_fu_656", "Parent" : "81",
		"CDFG" : "k2c_sub2idx",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "sub", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "shape", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "ndim", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "94", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.face_classifier_cdEe_U12", "Parent" : "81"},
	{"ID" : "95", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.face_classifier_ceOg_U13", "Parent" : "81"},
	{"ID" : "96", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.face_classifier_cfYi_U14", "Parent" : "81"},
	{"ID" : "97", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.face_classifier_cg8j_U15", "Parent" : "81"},
	{"ID" : "98", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_dot_1_fu_225.face_classifier_chbi_U16", "Parent" : "81"},
	{"ID" : "99", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_bias_add_fu_246", "Parent" : "80", "Child" : ["100"],
		"CDFG" : "k2c_bias_add",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "A_array", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "A_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "b_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "b_numel_read", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "100", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.grp_k2c_bias_add_fu_246.face_classifier_cdEe_U33", "Parent" : "99"},
	{"ID" : "101", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.face_classifier_cdEe_U38", "Parent" : "80"},
	{"ID" : "102", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.face_classifier_ceOg_U39", "Parent" : "80"},
	{"ID" : "103", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.face_classifier_chbi_U40", "Parent" : "80"},
	{"ID" : "104", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense_fu_1869.face_classifier_cibs_U41", "Parent" : "80"},
	{"ID" : "105", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888", "Parent" : "0", "Child" : ["106", "125", "127", "128", "129", "130", "131"],
		"CDFG" : "k2c_dense2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state2", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_dot2_fu_165"},
			{"State" : "ap_ST_fsm_state4", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_bias_add_fu_190"}],
		"Port" : [
			{"Name" : "fwork", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "106", "SubInstance" : "grp_k2c_dot2_fu_165", "Port" : "fwork"}]},
			{"Name" : "dropout_3_output_ndi", "Type" : "None", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "106", "SubInstance" : "grp_k2c_dot2_fu_165", "Port" : "dropout_3_output_ndi"}]},
			{"Name" : "dense_2_bias_array", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "125", "SubInstance" : "grp_k2c_bias_add_fu_190", "Port" : "b_array"}]},
			{"Name" : "dense_2_output_array", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "106", "SubInstance" : "grp_k2c_dot2_fu_165", "Port" : "dense_2_output_array"},
					{"ID" : "125", "SubInstance" : "grp_k2c_bias_add_fu_190", "Port" : "A_array"}]},
			{"Name" : "dropout_3_output_arr", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "106", "SubInstance" : "grp_k2c_dot2_fu_165", "Port" : "dropout_3_output_arr"}]},
			{"Name" : "dense_2_kernel_array_2", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "106", "SubInstance" : "grp_k2c_dot2_fu_165", "Port" : "dense_2_kernel_array_2"}]},
			{"Name" : "dense_2_kernel_ndim", "Type" : "None", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "106", "SubInstance" : "grp_k2c_dot2_fu_165", "Port" : "dense_2_kernel_ndim"}]},
			{"Name" : "dropout_3_output_num", "Type" : "None", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "106", "SubInstance" : "grp_k2c_dot2_fu_165", "Port" : "dropout_3_output_num"}]},
			{"Name" : "dropout_3_output_sha", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "106", "SubInstance" : "grp_k2c_dot2_fu_165", "Port" : "dropout_3_output_sha"}]},
			{"Name" : "dense_2_kernel_numel", "Type" : "None", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "106", "SubInstance" : "grp_k2c_dot2_fu_165", "Port" : "dense_2_kernel_numel"}]},
			{"Name" : "dense_2_kernel_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "106", "SubInstance" : "grp_k2c_dot2_fu_165", "Port" : "dense_2_kernel_shape"}]},
			{"Name" : "dense_2_output_numel", "Type" : "None", "Direction" : "I"},
			{"Name" : "dense_2_bias_numel", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "106", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165", "Parent" : "105", "Child" : ["107", "108", "109", "110", "111", "112", "113", "114", "115", "118", "119", "120", "121", "122", "123", "124"],
		"CDFG" : "k2c_dot2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state29", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_idx2sub_fu_569"},
			{"State" : "ap_ST_fsm_state35", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_idx2sub_fu_569"},
			{"State" : "ap_ST_fsm_state33", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_sub2idx_fu_581"},
			{"State" : "ap_ST_fsm_state39", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_sub2idx_fu_581"}],
		"Port" : [
			{"Name" : "axesA_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "fwork", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "dropout_3_output_ndi", "Type" : "None", "Direction" : "I"},
			{"Name" : "dense_2_kernel_ndim", "Type" : "None", "Direction" : "I"},
			{"Name" : "dropout_3_output_num", "Type" : "None", "Direction" : "I"},
			{"Name" : "dropout_3_output_sha", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "115", "SubInstance" : "grp_k2c_idx2sub_fu_569", "Port" : "shape"}]},
			{"Name" : "dense_2_kernel_numel", "Type" : "None", "Direction" : "I"},
			{"Name" : "dense_2_kernel_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "115", "SubInstance" : "grp_k2c_idx2sub_fu_569", "Port" : "shape"}]},
			{"Name" : "dropout_3_output_arr", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dense_2_kernel_array_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dense_2_output_array", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "107", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.permA_U", "Parent" : "106"},
	{"ID" : "108", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.permB_U", "Parent" : "106"},
	{"ID" : "109", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.freeA_U", "Parent" : "106"},
	{"ID" : "110", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.freeB_U", "Parent" : "106"},
	{"ID" : "111", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.newshpA_U", "Parent" : "106"},
	{"ID" : "112", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.newshpB_U", "Parent" : "106"},
	{"ID" : "113", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.Asub_U", "Parent" : "106"},
	{"ID" : "114", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.Bsub_U", "Parent" : "106"},
	{"ID" : "115", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.grp_k2c_idx2sub_fu_569", "Parent" : "106", "Child" : ["116", "117"],
		"CDFG" : "k2c_idx2sub",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "idx", "Type" : "None", "Direction" : "I"},
			{"Name" : "sub", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "shape", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "ndim", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "116", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.grp_k2c_idx2sub_fu_569.face_classifier_cbkb_U1", "Parent" : "115"},
	{"ID" : "117", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.grp_k2c_idx2sub_fu_569.face_classifier_ccud_U2", "Parent" : "115"},
	{"ID" : "118", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.grp_k2c_sub2idx_fu_581", "Parent" : "106",
		"CDFG" : "k2c_sub2idx",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "sub", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "shape", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "ndim", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "119", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.face_classifier_cdEe_U128", "Parent" : "106"},
	{"ID" : "120", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.face_classifier_ceOg_U129", "Parent" : "106"},
	{"ID" : "121", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.face_classifier_cyd2_U130", "Parent" : "106"},
	{"ID" : "122", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.face_classifier_czec_U131", "Parent" : "106"},
	{"ID" : "123", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.face_classifier_cibs_U132", "Parent" : "106"},
	{"ID" : "124", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_dot2_fu_165.face_classifier_cAem_U133", "Parent" : "106"},
	{"ID" : "125", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_bias_add_fu_190", "Parent" : "105", "Child" : ["126"],
		"CDFG" : "k2c_bias_add",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "A_array", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "A_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "b_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "b_numel_read", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "126", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.grp_k2c_bias_add_fu_190.face_classifier_cdEe_U33", "Parent" : "125"},
	{"ID" : "127", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.face_classifier_cdEe_U148", "Parent" : "105"},
	{"ID" : "128", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.face_classifier_ceOg_U149", "Parent" : "105"},
	{"ID" : "129", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.face_classifier_cibs_U150", "Parent" : "105"},
	{"ID" : "130", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.face_classifier_cibs_U151", "Parent" : "105"},
	{"ID" : "131", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dense2_fu_1888.face_classifier_chbi_U152", "Parent" : "105"},
	{"ID" : "132", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_k2c_batch_norm_fu_1917", "Parent" : "0", "Child" : ["133", "134", "135", "136", "137"],
		"CDFG" : "k2c_batch_norm",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "45", "EstimateLatencyMax" : "135",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "outputs_array", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "inputs_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "inputs_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "inputs_shape", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "mean_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "stdev_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "gamma_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "beta_array", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "133", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_batch_norm_fu_1917.face_classifier_cjbC_U52", "Parent" : "132"},
	{"ID" : "134", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_batch_norm_fu_1917.face_classifier_cdEe_U53", "Parent" : "132"},
	{"ID" : "135", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_batch_norm_fu_1917.face_classifier_ceOg_U54", "Parent" : "132"},
	{"ID" : "136", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_batch_norm_fu_1917.face_classifier_ckbM_U55", "Parent" : "132"},
	{"ID" : "137", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_batch_norm_fu_1917.face_classifier_clbW_U56", "Parent" : "132"},
	{"ID" : "138", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943", "Parent" : "0", "Child" : ["139", "144", "145", "146", "147", "148", "149", "150", "151", "152", "153"],
		"CDFG" : "generic_tanh_float_s",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "32", "EstimateLatencyMin" : "32", "EstimateLatencyMax" : "32",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "1",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "t_in", "Type" : "None", "Direction" : "I"},
			{"Name" : "table_exp_Z1_array_s", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "139", "SubInstance" : "grp_exp_generic_double_s_fu_89", "Port" : "table_exp_Z1_array_s"}]},
			{"Name" : "table_f_Z3_array_V", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "139", "SubInstance" : "grp_exp_generic_double_s_fu_89", "Port" : "table_f_Z3_array_V"}]},
			{"Name" : "table_f_Z2_array_V", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "139", "SubInstance" : "grp_exp_generic_double_s_fu_89", "Port" : "table_f_Z2_array_V"}]}]},
	{"ID" : "139", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.grp_exp_generic_double_s_fu_89", "Parent" : "138", "Child" : ["140", "141", "142", "143"],
		"CDFG" : "exp_generic_double_s",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "6", "EstimateLatencyMin" : "6", "EstimateLatencyMax" : "6",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "1",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "x", "Type" : "None", "Direction" : "I"},
			{"Name" : "table_exp_Z1_array_s", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "table_f_Z3_array_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "table_f_Z2_array_V", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "140", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.grp_exp_generic_double_s_fu_89.table_exp_Z1_array_s_U", "Parent" : "139"},
	{"ID" : "141", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.grp_exp_generic_double_s_fu_89.table_f_Z3_array_V_U", "Parent" : "139"},
	{"ID" : "142", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.grp_exp_generic_double_s_fu_89.table_f_Z2_array_V_U", "Parent" : "139"},
	{"ID" : "143", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.grp_exp_generic_double_s_fu_89.face_classifier_cpcA_U68", "Parent" : "139"},
	{"ID" : "144", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.face_classifier_cqcK_U74", "Parent" : "138"},
	{"ID" : "145", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.face_classifier_cdEe_U75", "Parent" : "138"},
	{"ID" : "146", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.face_classifier_cdEe_U76", "Parent" : "138"},
	{"ID" : "147", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.face_classifier_cjbC_U77", "Parent" : "138"},
	{"ID" : "148", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.face_classifier_ceOg_U78", "Parent" : "138"},
	{"ID" : "149", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.face_classifier_ckbM_U79", "Parent" : "138"},
	{"ID" : "150", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.face_classifier_crcU_U80", "Parent" : "138"},
	{"ID" : "151", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.face_classifier_csc4_U81", "Parent" : "138"},
	{"ID" : "152", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.face_classifier_ctde_U82", "Parent" : "138"},
	{"ID" : "153", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_generic_tanh_float_s_fu_1943.face_classifier_cudo_U83", "Parent" : "138"},
	{"ID" : "154", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cqcK_U166", "Parent" : "0"},
	{"ID" : "155", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_ceOg_U167", "Parent" : "0"},
	{"ID" : "156", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_ckbM_U168", "Parent" : "0"},
	{"ID" : "157", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_ctde_U169", "Parent" : "0"},
	{"ID" : "158", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cbrm_U170", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	face_classifier_c {
		dense_input_input_array {Type I LastRead 84 FirstWrite -1}
		dense_input_input_ndim {Type I LastRead 2 FirstWrite -1}
		dense_input_input_numel {Type I LastRead 2 FirstWrite -1}
		dense_input_input_shape {Type I LastRead 78 FirstWrite -1}
		activation_3_output_array {Type O LastRead -1 FirstWrite 101}
		activation_3_output_ndim {Type O LastRead -1 FirstWrite 98}
		activation_3_output_numel {Type O LastRead -1 FirstWrite 98}
		activation_3_output_shape {Type O LastRead -1 FirstWrite 100}
		dense_output_numel {Type IO LastRead -1 FirstWrite -1}
		dense_output_array {Type IO LastRead -1 FirstWrite -1}
		face_classifier_c_de {Type I LastRead -1 FirstWrite -1}
		dense_kernel_array {Type IO LastRead -1 FirstWrite -1}
		dense_bias_array {Type I LastRead -1 FirstWrite -1}
		dense_bias_array_0 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_1 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_3 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_23 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_11 {Type I LastRead -1 FirstWrite -1}
		batch_normalization_22 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_s {Type I LastRead -1 FirstWrite -1}
		batch_normalization_18 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_14 {Type I LastRead -1 FirstWrite -1}
		batch_normalization_21 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_17 {Type I LastRead -1 FirstWrite -1}
		batch_normalization_19 {Type IO LastRead -1 FirstWrite -1}
		dense_1_output_numel {Type IO LastRead -1 FirstWrite -1}
		dense_1_output_array {Type IO LastRead -1 FirstWrite -1}
		dense_1_kernel_ndim {Type IO LastRead -1 FirstWrite -1}
		dense_1_kernel_numel {Type IO LastRead -1 FirstWrite -1}
		dense_1_kernel_array {Type I LastRead -1 FirstWrite -1}
		dense_1_kernel_array_1 {Type IO LastRead -1 FirstWrite -1}
		dense_1_bias_numel {Type IO LastRead -1 FirstWrite -1}
		dense_1_bias_array2 {Type I LastRead -1 FirstWrite -1}
		dense_1_bias_array {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_9 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_8 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_29 {Type I LastRead -1 FirstWrite -1}
		batch_normalization_7 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_20 {Type I LastRead -1 FirstWrite -1}
		batch_normalization_15 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_32 {Type I LastRead -1 FirstWrite -1}
		batch_normalization_6 {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_35 {Type I LastRead -1 FirstWrite -1}
		batch_normalization_5 {Type IO LastRead -1 FirstWrite -1}
		dense_2_output_ndim {Type IO LastRead -1 FirstWrite -1}
		dense_2_output_numel {Type IO LastRead -1 FirstWrite -1}
		dense_2_output_array {Type IO LastRead -1 FirstWrite -1}
		dense_2_kernel_ndim {Type IO LastRead -1 FirstWrite -1}
		dense_2_kernel_numel {Type IO LastRead -1 FirstWrite -1}
		dense_2_kernel_array {Type I LastRead -1 FirstWrite -1}
		dense_2_kernel_array_2 {Type IO LastRead -1 FirstWrite -1}
		dense_2_bias_numel {Type IO LastRead -1 FirstWrite -1}
		dense_2_bias_array7 {Type I LastRead -1 FirstWrite -1}
		dense_2_bias_array {Type IO LastRead -1 FirstWrite -1}
		dense_kernel_shape {Type IO LastRead -1 FirstWrite -1}
		dense_output_shape {Type IO LastRead -1 FirstWrite -1}
		table_exp_Z1_array_s {Type I LastRead -1 FirstWrite -1}
		table_f_Z3_array_V {Type I LastRead -1 FirstWrite -1}
		table_f_Z2_array_V {Type I LastRead -1 FirstWrite -1}
		batch_normalization_4 {Type IO LastRead -1 FirstWrite -1}
		activation_1_output_s {Type IO LastRead -1 FirstWrite -1}
		activation_1_output_1 {Type IO LastRead -1 FirstWrite -1}
		dropout_2_output_sha {Type IO LastRead -1 FirstWrite -1}
		dropout_2_output_arr {Type IO LastRead -1 FirstWrite -1}
		dense_1_kernel_shape {Type IO LastRead -1 FirstWrite -1}
		dense_1_output_shape {Type IO LastRead -1 FirstWrite -1}
		batch_normalization_12 {Type IO LastRead -1 FirstWrite -1}
		activation_2_output_s {Type IO LastRead -1 FirstWrite -1}
		activation_2_output_1 {Type IO LastRead -1 FirstWrite -1}
		dropout_3_output_ndi {Type IO LastRead -1 FirstWrite -1}
		dropout_3_output_num {Type IO LastRead -1 FirstWrite -1}
		dropout_3_output_sha {Type IO LastRead -1 FirstWrite -1}
		dropout_3_output_arr {Type IO LastRead -1 FirstWrite -1}
		dense_2_kernel_shape {Type IO LastRead -1 FirstWrite -1}
		dense_2_output_shape {Type IO LastRead -1 FirstWrite -1}}
	k2c_dense_1 {
		output_array {Type IO LastRead 2 FirstWrite 3}
		output_numel_read {Type I LastRead 0 FirstWrite -1}
		input_array {Type I LastRead 84 FirstWrite -1}
		input_ndim_read {Type I LastRead 0 FirstWrite -1}
		input_numel_read {Type I LastRead 0 FirstWrite -1}
		input_shape {Type I LastRead 78 FirstWrite -1}
		kernel_array {Type I LastRead 85 FirstWrite -1}
		kernel_ndim_read {Type I LastRead 0 FirstWrite -1}
		kernel_numel_read {Type I LastRead 0 FirstWrite -1}
		kernel_shape {Type I LastRead 80 FirstWrite -1}
		bias_array {Type I LastRead 2 FirstWrite -1}
		bias_numel_read {Type I LastRead 0 FirstWrite -1}
		fwork {Type IO LastRead 85 FirstWrite 85}}
	k2c_dot {
		C_array {Type O LastRead -1 FirstWrite 83}
		Ar_array {Type I LastRead 84 FirstWrite -1}
		Ar_ndim_read {Type I LastRead 0 FirstWrite -1}
		Ar_numel_read {Type I LastRead 0 FirstWrite -1}
		Ar_shape {Type I LastRead 78 FirstWrite -1}
		B_array {Type I LastRead 85 FirstWrite -1}
		B_ndim_read {Type I LastRead 0 FirstWrite -1}
		B_numel_read {Type I LastRead 0 FirstWrite -1}
		B_shape {Type I LastRead 80 FirstWrite -1}
		axesA_0_read {Type I LastRead 0 FirstWrite -1}
		fwork {Type IO LastRead 85 FirstWrite 85}}
	k2c_idx2sub {
		idx {Type I LastRead 0 FirstWrite -1}
		sub {Type O LastRead -1 FirstWrite 69}
		shape {Type I LastRead 1 FirstWrite -1}
		ndim {Type I LastRead 0 FirstWrite -1}}
	k2c_sub2idx {
		sub {Type I LastRead 1 FirstWrite -1}
		shape {Type I LastRead 3 FirstWrite -1}
		ndim {Type I LastRead 0 FirstWrite -1}}
	k2c_bias_add {
		A_array {Type IO LastRead 2 FirstWrite 6}
		A_numel_read {Type I LastRead 0 FirstWrite -1}
		b_array {Type I LastRead 2 FirstWrite -1}
		b_numel_read {Type I LastRead 0 FirstWrite -1}}
	k2c_dense {
		output_array {Type IO LastRead 2 FirstWrite 3}
		input_array {Type I LastRead 84 FirstWrite -1}
		input_ndim_read {Type I LastRead 0 FirstWrite -1}
		input_numel_read {Type I LastRead 0 FirstWrite -1}
		input_shape {Type I LastRead 78 FirstWrite -1}
		kernel_array {Type I LastRead 87 FirstWrite -1}
		kernel_shape {Type I LastRead 80 FirstWrite -1}
		bias_array {Type I LastRead 2 FirstWrite -1}
		fwork {Type IO LastRead 85 FirstWrite 85}}
	k2c_dot_1 {
		C_array {Type O LastRead -1 FirstWrite 83}
		Ar_array {Type I LastRead 84 FirstWrite -1}
		Ar_ndim_read {Type I LastRead 0 FirstWrite -1}
		Ar_numel_read {Type I LastRead 0 FirstWrite -1}
		Ar_shape {Type I LastRead 78 FirstWrite -1}
		B_array {Type I LastRead 87 FirstWrite -1}
		B_shape {Type I LastRead 80 FirstWrite -1}
		p_read4 {Type I LastRead 0 FirstWrite -1}
		fwork {Type IO LastRead 85 FirstWrite 85}}
	k2c_idx2sub {
		idx {Type I LastRead 0 FirstWrite -1}
		sub {Type O LastRead -1 FirstWrite 69}
		shape {Type I LastRead 1 FirstWrite -1}
		ndim {Type I LastRead 0 FirstWrite -1}}
	k2c_sub2idx {
		sub {Type I LastRead 1 FirstWrite -1}
		shape {Type I LastRead 3 FirstWrite -1}
		ndim {Type I LastRead 0 FirstWrite -1}}
	k2c_bias_add {
		A_array {Type IO LastRead 2 FirstWrite 6}
		A_numel_read {Type I LastRead 0 FirstWrite -1}
		b_array {Type I LastRead 2 FirstWrite -1}
		b_numel_read {Type I LastRead 0 FirstWrite -1}}
	k2c_dense2 {
		fwork {Type IO LastRead 26 FirstWrite 24}
		dropout_3_output_ndi {Type I LastRead 0 FirstWrite -1}
		dense_2_bias_array {Type I LastRead 3 FirstWrite -1}
		dense_2_output_array {Type IO LastRead 2 FirstWrite 5}
		dropout_3_output_arr {Type I LastRead 23 FirstWrite -1}
		dense_2_kernel_array_2 {Type I LastRead 24 FirstWrite -1}
		dense_2_kernel_ndim {Type I LastRead 0 FirstWrite -1}
		dropout_3_output_num {Type I LastRead 0 FirstWrite -1}
		dropout_3_output_sha {Type I LastRead 20 FirstWrite -1}
		dense_2_kernel_numel {Type I LastRead 3 FirstWrite -1}
		dense_2_kernel_shape {Type I LastRead 21 FirstWrite -1}
		dense_2_output_numel {Type I LastRead 2 FirstWrite -1}
		dense_2_bias_numel {Type I LastRead 2 FirstWrite -1}}
	k2c_dot2 {
		axesA_0_read {Type I LastRead 0 FirstWrite -1}
		fwork {Type IO LastRead 26 FirstWrite 24}
		dropout_3_output_ndi {Type I LastRead 0 FirstWrite -1}
		dense_2_kernel_ndim {Type I LastRead 0 FirstWrite -1}
		dropout_3_output_num {Type I LastRead 0 FirstWrite -1}
		dropout_3_output_sha {Type I LastRead 20 FirstWrite -1}
		dense_2_kernel_numel {Type I LastRead 3 FirstWrite -1}
		dense_2_kernel_shape {Type I LastRead 21 FirstWrite -1}
		dropout_3_output_arr {Type I LastRead 23 FirstWrite -1}
		dense_2_kernel_array_2 {Type I LastRead 24 FirstWrite -1}
		dense_2_output_array {Type O LastRead -1 FirstWrite 25}}
	k2c_idx2sub {
		idx {Type I LastRead 0 FirstWrite -1}
		sub {Type O LastRead -1 FirstWrite 69}
		shape {Type I LastRead 1 FirstWrite -1}
		ndim {Type I LastRead 0 FirstWrite -1}}
	k2c_sub2idx {
		sub {Type I LastRead 1 FirstWrite -1}
		shape {Type I LastRead 3 FirstWrite -1}
		ndim {Type I LastRead 0 FirstWrite -1}}
	k2c_bias_add {
		A_array {Type IO LastRead 2 FirstWrite 6}
		A_numel_read {Type I LastRead 0 FirstWrite -1}
		b_array {Type I LastRead 2 FirstWrite -1}
		b_numel_read {Type I LastRead 0 FirstWrite -1}}
	k2c_batch_norm {
		outputs_array {Type O LastRead -1 FirstWrite 35}
		inputs_array {Type I LastRead 17 FirstWrite -1}
		inputs_numel_read {Type I LastRead 1 FirstWrite -1}
		inputs_shape {Type I LastRead 0 FirstWrite -1}
		mean_array {Type I LastRead 17 FirstWrite -1}
		stdev_array {Type I LastRead 20 FirstWrite -1}
		gamma_array {Type I LastRead 28 FirstWrite -1}
		beta_array {Type I LastRead 28 FirstWrite -1}}
	generic_tanh_float_s {
		t_in {Type I LastRead 0 FirstWrite -1}
		table_exp_Z1_array_s {Type I LastRead -1 FirstWrite -1}
		table_f_Z3_array_V {Type I LastRead -1 FirstWrite -1}
		table_f_Z2_array_V {Type I LastRead -1 FirstWrite -1}}
	exp_generic_double_s {
		x {Type I LastRead 0 FirstWrite -1}
		table_exp_Z1_array_s {Type I LastRead -1 FirstWrite -1}
		table_f_Z3_array_V {Type I LastRead -1 FirstWrite -1}
		table_f_Z2_array_V {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
	{"Pipeline" : "5", "EnableSignal" : "ap_enable_pp5"}
	{"Pipeline" : "6", "EnableSignal" : "ap_enable_pp6"}
	{"Pipeline" : "7", "EnableSignal" : "ap_enable_pp7"}
	{"Pipeline" : "9", "EnableSignal" : "ap_enable_pp9"}
	{"Pipeline" : "10", "EnableSignal" : "ap_enable_pp10"}
	{"Pipeline" : "12", "EnableSignal" : "ap_enable_pp12"}
	{"Pipeline" : "13", "EnableSignal" : "ap_enable_pp13"}
	{"Pipeline" : "14", "EnableSignal" : "ap_enable_pp14"}
	{"Pipeline" : "15", "EnableSignal" : "ap_enable_pp15"}
	{"Pipeline" : "17", "EnableSignal" : "ap_enable_pp17"}
	{"Pipeline" : "18", "EnableSignal" : "ap_enable_pp18"}
	{"Pipeline" : "19", "EnableSignal" : "ap_enable_pp19"}
	{"Pipeline" : "20", "EnableSignal" : "ap_enable_pp20"}
	{"Pipeline" : "21", "EnableSignal" : "ap_enable_pp21"}
	{"Pipeline" : "22", "EnableSignal" : "ap_enable_pp22"}
	{"Pipeline" : "23", "EnableSignal" : "ap_enable_pp23"}
	{"Pipeline" : "24", "EnableSignal" : "ap_enable_pp24"}
	{"Pipeline" : "25", "EnableSignal" : "ap_enable_pp25"}
	{"Pipeline" : "26", "EnableSignal" : "ap_enable_pp26"}
	{"Pipeline" : "27", "EnableSignal" : "ap_enable_pp27"}
	{"Pipeline" : "28", "EnableSignal" : "ap_enable_pp28"}
]}

set Spec2ImplPortList { 
	dense_input_input_array { ap_memory {  { dense_input_input_array_address0 mem_address 1 12 }  { dense_input_input_array_ce0 mem_ce 1 1 }  { dense_input_input_array_q0 mem_dout 0 32 } } }
	dense_input_input_ndim { ap_none {  { dense_input_input_ndim in_data 0 64 } } }
	dense_input_input_numel { ap_none {  { dense_input_input_numel in_data 0 64 } } }
	dense_input_input_shape { ap_memory {  { dense_input_input_shape_address0 mem_address 1 3 }  { dense_input_input_shape_ce0 mem_ce 1 1 }  { dense_input_input_shape_q0 mem_dout 0 64 } } }
	activation_3_output_array { ap_memory {  { activation_3_output_array_address0 mem_address 1 12 }  { activation_3_output_array_ce0 mem_ce 1 1 }  { activation_3_output_array_we0 mem_we 1 1 }  { activation_3_output_array_d0 mem_din 1 32 } } }
	activation_3_output_ndim { ap_vld {  { activation_3_output_ndim out_data 1 64 }  { activation_3_output_ndim_ap_vld out_vld 1 1 } } }
	activation_3_output_numel { ap_vld {  { activation_3_output_numel out_data 1 64 }  { activation_3_output_numel_ap_vld out_vld 1 1 } } }
	activation_3_output_shape { ap_memory {  { activation_3_output_shape_address0 mem_address 1 3 }  { activation_3_output_shape_ce0 mem_ce 1 1 }  { activation_3_output_shape_we0 mem_we 1 1 }  { activation_3_output_shape_d0 mem_din 1 64 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
