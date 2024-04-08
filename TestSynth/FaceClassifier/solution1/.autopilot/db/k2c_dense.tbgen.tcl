set moduleName k2c_dense
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
set C_modelName {k2c_dense}
set C_modelType { void 0 }
set C_modelArgList {
	{ output_array float 32 regular {array 300000 { 2 3 } 1 1 }  }
	{ input_array float 32 regular {array 300000 { 1 3 } 1 1 }  }
	{ input_ndim_read int 64 regular  }
	{ input_numel_read int 64 regular  }
	{ input_shape int 64 regular {array 5 { 1 3 } 1 1 }  }
	{ kernel_array float 32 regular {array 300000 { 1 3 } 1 1 }  }
	{ kernel_shape int 64 regular {array 5 { 1 1 } 1 1 }  }
	{ bias_array float 32 regular {array 300000 { 1 3 } 1 1 }  }
	{ fwork float 32 regular {array 264822 { 2 1 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "output_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} , 
 	{ "Name" : "input_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "input_ndim_read", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "input_numel_read", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "input_shape", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "kernel_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "kernel_shape", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bias_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "fwork", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 39
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ output_array_address0 sc_out sc_lv 19 signal 0 } 
	{ output_array_ce0 sc_out sc_logic 1 signal 0 } 
	{ output_array_we0 sc_out sc_logic 1 signal 0 } 
	{ output_array_d0 sc_out sc_lv 32 signal 0 } 
	{ output_array_q0 sc_in sc_lv 32 signal 0 } 
	{ input_array_address0 sc_out sc_lv 19 signal 1 } 
	{ input_array_ce0 sc_out sc_logic 1 signal 1 } 
	{ input_array_q0 sc_in sc_lv 32 signal 1 } 
	{ input_ndim_read sc_in sc_lv 64 signal 2 } 
	{ input_numel_read sc_in sc_lv 64 signal 3 } 
	{ input_shape_address0 sc_out sc_lv 3 signal 4 } 
	{ input_shape_ce0 sc_out sc_logic 1 signal 4 } 
	{ input_shape_q0 sc_in sc_lv 64 signal 4 } 
	{ kernel_array_address0 sc_out sc_lv 19 signal 5 } 
	{ kernel_array_ce0 sc_out sc_logic 1 signal 5 } 
	{ kernel_array_q0 sc_in sc_lv 32 signal 5 } 
	{ kernel_shape_address0 sc_out sc_lv 3 signal 6 } 
	{ kernel_shape_ce0 sc_out sc_logic 1 signal 6 } 
	{ kernel_shape_q0 sc_in sc_lv 64 signal 6 } 
	{ kernel_shape_address1 sc_out sc_lv 3 signal 6 } 
	{ kernel_shape_ce1 sc_out sc_logic 1 signal 6 } 
	{ kernel_shape_q1 sc_in sc_lv 64 signal 6 } 
	{ bias_array_address0 sc_out sc_lv 19 signal 7 } 
	{ bias_array_ce0 sc_out sc_logic 1 signal 7 } 
	{ bias_array_q0 sc_in sc_lv 32 signal 7 } 
	{ fwork_address0 sc_out sc_lv 19 signal 8 } 
	{ fwork_ce0 sc_out sc_logic 1 signal 8 } 
	{ fwork_we0 sc_out sc_logic 1 signal 8 } 
	{ fwork_d0 sc_out sc_lv 32 signal 8 } 
	{ fwork_q0 sc_in sc_lv 32 signal 8 } 
	{ fwork_address1 sc_out sc_lv 19 signal 8 } 
	{ fwork_ce1 sc_out sc_logic 1 signal 8 } 
	{ fwork_q1 sc_in sc_lv 32 signal 8 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "output_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "output_array", "role": "address0" }} , 
 	{ "name": "output_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "output_array", "role": "ce0" }} , 
 	{ "name": "output_array_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "output_array", "role": "we0" }} , 
 	{ "name": "output_array_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "output_array", "role": "d0" }} , 
 	{ "name": "output_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "output_array", "role": "q0" }} , 
 	{ "name": "input_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "input_array", "role": "address0" }} , 
 	{ "name": "input_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_array", "role": "ce0" }} , 
 	{ "name": "input_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_array", "role": "q0" }} , 
 	{ "name": "input_ndim_read", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "input_ndim_read", "role": "default" }} , 
 	{ "name": "input_numel_read", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "input_numel_read", "role": "default" }} , 
 	{ "name": "input_shape_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "input_shape", "role": "address0" }} , 
 	{ "name": "input_shape_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_shape", "role": "ce0" }} , 
 	{ "name": "input_shape_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "input_shape", "role": "q0" }} , 
 	{ "name": "kernel_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "kernel_array", "role": "address0" }} , 
 	{ "name": "kernel_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "kernel_array", "role": "ce0" }} , 
 	{ "name": "kernel_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel_array", "role": "q0" }} , 
 	{ "name": "kernel_shape_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "kernel_shape", "role": "address0" }} , 
 	{ "name": "kernel_shape_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "kernel_shape", "role": "ce0" }} , 
 	{ "name": "kernel_shape_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "kernel_shape", "role": "q0" }} , 
 	{ "name": "kernel_shape_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "kernel_shape", "role": "address1" }} , 
 	{ "name": "kernel_shape_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "kernel_shape", "role": "ce1" }} , 
 	{ "name": "kernel_shape_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "kernel_shape", "role": "q1" }} , 
 	{ "name": "bias_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "bias_array", "role": "address0" }} , 
 	{ "name": "bias_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "bias_array", "role": "ce0" }} , 
 	{ "name": "bias_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "bias_array", "role": "q0" }} , 
 	{ "name": "fwork_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "fwork", "role": "address0" }} , 
 	{ "name": "fwork_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fwork", "role": "ce0" }} , 
 	{ "name": "fwork_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fwork", "role": "we0" }} , 
 	{ "name": "fwork_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fwork", "role": "d0" }} , 
 	{ "name": "fwork_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fwork", "role": "q0" }} , 
 	{ "name": "fwork_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "fwork", "role": "address1" }} , 
 	{ "name": "fwork_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fwork", "role": "ce1" }} , 
 	{ "name": "fwork_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fwork", "role": "q1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "19", "20"],
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
			{"State" : "ap_ST_fsm_state2", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_dot_2_fu_240"}],
		"Port" : [
			{"Name" : "output_array", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_k2c_dot_2_fu_240", "Port" : "C_array"}]},
			{"Name" : "input_array", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_k2c_dot_2_fu_240", "Port" : "Ar_array"}]},
			{"Name" : "input_ndim_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "input_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "input_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_k2c_dot_2_fu_240", "Port" : "Ar_shape"}]},
			{"Name" : "kernel_array", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_k2c_dot_2_fu_240", "Port" : "B_array"}]},
			{"Name" : "kernel_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_k2c_dot_2_fu_240", "Port" : "B_shape"}]},
			{"Name" : "bias_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fwork", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_k2c_dot_2_fu_240", "Port" : "fwork"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240", "Parent" : "0", "Child" : ["2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18"],
		"CDFG" : "k2c_dot_2",
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
			{"State" : "ap_ST_fsm_state156", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_sub2idx_fu_679"},
			{"State" : "ap_ST_fsm_state230", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_k2c_sub2idx_fu_679"}],
		"Port" : [
			{"Name" : "C_array", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "Ar_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "Ar_ndim_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Ar_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "Ar_shape", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_shape", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "p_read4", "Type" : "None", "Direction" : "I"},
			{"Name" : "fwork", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "2", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.permA_U", "Parent" : "1"},
	{"ID" : "3", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.permB_U", "Parent" : "1"},
	{"ID" : "4", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.freeA_U", "Parent" : "1"},
	{"ID" : "5", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.freeB_U", "Parent" : "1"},
	{"ID" : "6", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.newshpA_U", "Parent" : "1"},
	{"ID" : "7", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.newshpB_U", "Parent" : "1"},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.Asub_U", "Parent" : "1"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.Bsub_U", "Parent" : "1"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.grp_k2c_sub2idx_fu_679", "Parent" : "1",
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
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.face_classifier_cbkb_U4", "Parent" : "1"},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.face_classifier_ccud_U5", "Parent" : "1"},
	{"ID" : "13", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.face_classifier_cdEe_U6", "Parent" : "1"},
	{"ID" : "14", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.face_classifier_ceOg_U7", "Parent" : "1"},
	{"ID" : "15", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.face_classifier_cfYi_U8", "Parent" : "1"},
	{"ID" : "16", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.face_classifier_cdEe_U9", "Parent" : "1"},
	{"ID" : "17", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.face_classifier_cfYi_U10", "Parent" : "1"},
	{"ID" : "18", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_dot_2_fu_240.face_classifier_cdEe_U11", "Parent" : "1"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cbkb_U28", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_ccud_U29", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	k2c_dense {
		output_array {Type IO LastRead 3 FirstWrite 4}
		input_array {Type I LastRead 78 FirstWrite -1}
		input_ndim_read {Type I LastRead 0 FirstWrite -1}
		input_numel_read {Type I LastRead 0 FirstWrite -1}
		input_shape {Type I LastRead 77 FirstWrite -1}
		kernel_array {Type I LastRead 79 FirstWrite -1}
		kernel_shape {Type I LastRead 78 FirstWrite -1}
		bias_array {Type I LastRead 4 FirstWrite -1}
		fwork {Type IO LastRead 81 FirstWrite 79}}
	k2c_dot_2 {
		C_array {Type O LastRead -1 FirstWrite 80}
		Ar_array {Type I LastRead 78 FirstWrite -1}
		Ar_ndim_read {Type I LastRead 0 FirstWrite -1}
		Ar_numel_read {Type I LastRead 0 FirstWrite -1}
		Ar_shape {Type I LastRead 77 FirstWrite -1}
		B_array {Type I LastRead 79 FirstWrite -1}
		B_shape {Type I LastRead 78 FirstWrite -1}
		p_read4 {Type I LastRead 0 FirstWrite -1}
		fwork {Type IO LastRead 81 FirstWrite 79}}
	k2c_sub2idx {
		sub {Type I LastRead 1 FirstWrite -1}
		shape {Type I LastRead 3 FirstWrite -1}
		ndim {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	output_array { ap_memory {  { output_array_address0 mem_address 1 19 }  { output_array_ce0 mem_ce 1 1 }  { output_array_we0 mem_we 1 1 }  { output_array_d0 mem_din 1 32 }  { output_array_q0 mem_dout 0 32 } } }
	input_array { ap_memory {  { input_array_address0 mem_address 1 19 }  { input_array_ce0 mem_ce 1 1 }  { input_array_q0 mem_dout 0 32 } } }
	input_ndim_read { ap_none {  { input_ndim_read in_data 0 64 } } }
	input_numel_read { ap_none {  { input_numel_read in_data 0 64 } } }
	input_shape { ap_memory {  { input_shape_address0 mem_address 1 3 }  { input_shape_ce0 mem_ce 1 1 }  { input_shape_q0 mem_dout 0 64 } } }
	kernel_array { ap_memory {  { kernel_array_address0 mem_address 1 19 }  { kernel_array_ce0 mem_ce 1 1 }  { kernel_array_q0 mem_dout 0 32 } } }
	kernel_shape { ap_memory {  { kernel_shape_address0 mem_address 1 3 }  { kernel_shape_ce0 mem_ce 1 1 }  { kernel_shape_q0 mem_dout 0 64 }  { kernel_shape_address1 mem_address 1 3 }  { kernel_shape_ce1 mem_ce 1 1 }  { kernel_shape_q1 mem_dout 0 64 } } }
	bias_array { ap_memory {  { bias_array_address0 mem_address 1 19 }  { bias_array_ce0 mem_ce 1 1 }  { bias_array_q0 mem_dout 0 32 } } }
	fwork { ap_memory {  { fwork_address0 mem_address 1 19 }  { fwork_ce0 mem_ce 1 1 }  { fwork_we0 mem_we 1 1 }  { fwork_d0 mem_din 1 32 }  { fwork_q0 mem_dout 0 32 }  { fwork_address1 mem_address 1 19 }  { fwork_ce1 mem_ce 1 1 }  { fwork_q1 mem_dout 0 32 } } }
}
