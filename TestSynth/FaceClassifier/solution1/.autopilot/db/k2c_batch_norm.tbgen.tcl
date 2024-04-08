set moduleName k2c_batch_norm
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
set C_modelName {k2c_batch_norm}
set C_modelType { void 0 }
set C_modelArgList {
	{ outputs_array float 32 regular {array 300000 { 0 3 } 0 1 }  }
	{ inputs_array float 32 regular {array 300000 { 1 3 } 1 1 }  }
	{ inputs_ndim_read int 64 regular  }
	{ inputs_numel_read int 64 regular  }
	{ inputs_shape int 64 regular {array 5 { 1 3 } 1 1 }  }
	{ mean_array float 32 regular {array 300000 { 1 3 } 1 1 }  }
	{ stdev_array float 32 regular {array 300000 { 1 3 } 1 1 }  }
	{ gamma_array float 32 regular {array 300000 { 1 3 } 1 1 }  }
	{ beta_array float 32 regular {array 300000 { 1 3 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "outputs_array", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "inputs_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "inputs_ndim_read", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "inputs_numel_read", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "inputs_shape", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "mean_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "stdev_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "gamma_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "beta_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 30
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ outputs_array_address0 sc_out sc_lv 19 signal 0 } 
	{ outputs_array_ce0 sc_out sc_logic 1 signal 0 } 
	{ outputs_array_we0 sc_out sc_logic 1 signal 0 } 
	{ outputs_array_d0 sc_out sc_lv 32 signal 0 } 
	{ inputs_array_address0 sc_out sc_lv 19 signal 1 } 
	{ inputs_array_ce0 sc_out sc_logic 1 signal 1 } 
	{ inputs_array_q0 sc_in sc_lv 32 signal 1 } 
	{ inputs_ndim_read sc_in sc_lv 64 signal 2 } 
	{ inputs_numel_read sc_in sc_lv 64 signal 3 } 
	{ inputs_shape_address0 sc_out sc_lv 3 signal 4 } 
	{ inputs_shape_ce0 sc_out sc_logic 1 signal 4 } 
	{ inputs_shape_q0 sc_in sc_lv 64 signal 4 } 
	{ mean_array_address0 sc_out sc_lv 19 signal 5 } 
	{ mean_array_ce0 sc_out sc_logic 1 signal 5 } 
	{ mean_array_q0 sc_in sc_lv 32 signal 5 } 
	{ stdev_array_address0 sc_out sc_lv 19 signal 6 } 
	{ stdev_array_ce0 sc_out sc_logic 1 signal 6 } 
	{ stdev_array_q0 sc_in sc_lv 32 signal 6 } 
	{ gamma_array_address0 sc_out sc_lv 19 signal 7 } 
	{ gamma_array_ce0 sc_out sc_logic 1 signal 7 } 
	{ gamma_array_q0 sc_in sc_lv 32 signal 7 } 
	{ beta_array_address0 sc_out sc_lv 19 signal 8 } 
	{ beta_array_ce0 sc_out sc_logic 1 signal 8 } 
	{ beta_array_q0 sc_in sc_lv 32 signal 8 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "outputs_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "outputs_array", "role": "address0" }} , 
 	{ "name": "outputs_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "outputs_array", "role": "ce0" }} , 
 	{ "name": "outputs_array_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "outputs_array", "role": "we0" }} , 
 	{ "name": "outputs_array_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outputs_array", "role": "d0" }} , 
 	{ "name": "inputs_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "inputs_array", "role": "address0" }} , 
 	{ "name": "inputs_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "inputs_array", "role": "ce0" }} , 
 	{ "name": "inputs_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inputs_array", "role": "q0" }} , 
 	{ "name": "inputs_ndim_read", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "inputs_ndim_read", "role": "default" }} , 
 	{ "name": "inputs_numel_read", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "inputs_numel_read", "role": "default" }} , 
 	{ "name": "inputs_shape_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "inputs_shape", "role": "address0" }} , 
 	{ "name": "inputs_shape_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "inputs_shape", "role": "ce0" }} , 
 	{ "name": "inputs_shape_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "inputs_shape", "role": "q0" }} , 
 	{ "name": "mean_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "mean_array", "role": "address0" }} , 
 	{ "name": "mean_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mean_array", "role": "ce0" }} , 
 	{ "name": "mean_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mean_array", "role": "q0" }} , 
 	{ "name": "stdev_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "stdev_array", "role": "address0" }} , 
 	{ "name": "stdev_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stdev_array", "role": "ce0" }} , 
 	{ "name": "stdev_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "stdev_array", "role": "q0" }} , 
 	{ "name": "gamma_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "gamma_array", "role": "address0" }} , 
 	{ "name": "gamma_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gamma_array", "role": "ce0" }} , 
 	{ "name": "gamma_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "gamma_array", "role": "q0" }} , 
 	{ "name": "beta_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "beta_array", "role": "address0" }} , 
 	{ "name": "beta_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "beta_array", "role": "ce0" }} , 
 	{ "name": "beta_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "beta_array", "role": "q0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5"],
		"CDFG" : "k2c_batch_norm",
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
			{"Name" : "outputs_array", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "inputs_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "inputs_ndim_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "inputs_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "inputs_shape", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "mean_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "stdev_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "gamma_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "beta_array", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cg8j_U39", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_ccud_U40", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_chbi_U41", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cibs_U42", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cfYi_U43", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	k2c_batch_norm {
		outputs_array {Type O LastRead -1 FirstWrite 96}
		inputs_array {Type I LastRead 92 FirstWrite -1}
		inputs_ndim_read {Type I LastRead 0 FirstWrite -1}
		inputs_numel_read {Type I LastRead 0 FirstWrite -1}
		inputs_shape {Type I LastRead 2 FirstWrite -1}
		mean_array {Type I LastRead 92 FirstWrite -1}
		stdev_array {Type I LastRead 93 FirstWrite -1}
		gamma_array {Type I LastRead 95 FirstWrite -1}
		beta_array {Type I LastRead 95 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	outputs_array { ap_memory {  { outputs_array_address0 mem_address 1 19 }  { outputs_array_ce0 mem_ce 1 1 }  { outputs_array_we0 mem_we 1 1 }  { outputs_array_d0 mem_din 1 32 } } }
	inputs_array { ap_memory {  { inputs_array_address0 mem_address 1 19 }  { inputs_array_ce0 mem_ce 1 1 }  { inputs_array_q0 mem_dout 0 32 } } }
	inputs_ndim_read { ap_none {  { inputs_ndim_read in_data 0 64 } } }
	inputs_numel_read { ap_none {  { inputs_numel_read in_data 0 64 } } }
	inputs_shape { ap_memory {  { inputs_shape_address0 mem_address 1 3 }  { inputs_shape_ce0 mem_ce 1 1 }  { inputs_shape_q0 mem_dout 0 64 } } }
	mean_array { ap_memory {  { mean_array_address0 mem_address 1 19 }  { mean_array_ce0 mem_ce 1 1 }  { mean_array_q0 mem_dout 0 32 } } }
	stdev_array { ap_memory {  { stdev_array_address0 mem_address 1 19 }  { stdev_array_ce0 mem_ce 1 1 }  { stdev_array_q0 mem_dout 0 32 } } }
	gamma_array { ap_memory {  { gamma_array_address0 mem_address 1 19 }  { gamma_array_ce0 mem_ce 1 1 }  { gamma_array_q0 mem_dout 0 32 } } }
	beta_array { ap_memory {  { beta_array_address0 mem_address 1 19 }  { beta_array_ce0 mem_ce 1 1 }  { beta_array_q0 mem_dout 0 32 } } }
}