set moduleName k2c_dot
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
set C_modelName {k2c_dot}
set C_modelType { void 0 }
set C_modelArgList {
	{ C_array float 32 regular {array 2622 { 0 3 } 0 1 }  }
	{ Ar_array float 32 regular {array 2622 { 1 3 } 1 1 }  }
	{ Ar_ndim_read int 64 regular  }
	{ Ar_numel_read int 12 regular  }
	{ Ar_shape int 64 regular {array 5 { 1 3 } 1 1 }  }
	{ B_array float 32 regular {array 262200 { 1 3 } 1 1 }  }
	{ B_ndim_read int 64 regular  }
	{ B_numel_read int 64 regular  }
	{ B_shape int 64 regular {array 5 { 1 3 } 1 1 }  }
	{ axesA_0_read int 64 regular  }
	{ fwork float 32 regular {array 1100 { 2 1 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "C_array", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "Ar_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "Ar_ndim_read", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "Ar_numel_read", "interface" : "wire", "bitwidth" : 12, "direction" : "READONLY"} , 
 	{ "Name" : "Ar_shape", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "B_array", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "B_ndim_read", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "B_numel_read", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "B_shape", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "axesA_0_read", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "fwork", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 35
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ C_array_address0 sc_out sc_lv 12 signal 0 } 
	{ C_array_ce0 sc_out sc_logic 1 signal 0 } 
	{ C_array_we0 sc_out sc_logic 1 signal 0 } 
	{ C_array_d0 sc_out sc_lv 32 signal 0 } 
	{ Ar_array_address0 sc_out sc_lv 12 signal 1 } 
	{ Ar_array_ce0 sc_out sc_logic 1 signal 1 } 
	{ Ar_array_q0 sc_in sc_lv 32 signal 1 } 
	{ Ar_ndim_read sc_in sc_lv 64 signal 2 } 
	{ Ar_numel_read sc_in sc_lv 12 signal 3 } 
	{ Ar_shape_address0 sc_out sc_lv 3 signal 4 } 
	{ Ar_shape_ce0 sc_out sc_logic 1 signal 4 } 
	{ Ar_shape_q0 sc_in sc_lv 64 signal 4 } 
	{ B_array_address0 sc_out sc_lv 19 signal 5 } 
	{ B_array_ce0 sc_out sc_logic 1 signal 5 } 
	{ B_array_q0 sc_in sc_lv 32 signal 5 } 
	{ B_ndim_read sc_in sc_lv 64 signal 6 } 
	{ B_numel_read sc_in sc_lv 64 signal 7 } 
	{ B_shape_address0 sc_out sc_lv 3 signal 8 } 
	{ B_shape_ce0 sc_out sc_logic 1 signal 8 } 
	{ B_shape_q0 sc_in sc_lv 64 signal 8 } 
	{ axesA_0_read sc_in sc_lv 64 signal 9 } 
	{ fwork_address0 sc_out sc_lv 11 signal 10 } 
	{ fwork_ce0 sc_out sc_logic 1 signal 10 } 
	{ fwork_we0 sc_out sc_logic 1 signal 10 } 
	{ fwork_d0 sc_out sc_lv 32 signal 10 } 
	{ fwork_q0 sc_in sc_lv 32 signal 10 } 
	{ fwork_address1 sc_out sc_lv 11 signal 10 } 
	{ fwork_ce1 sc_out sc_logic 1 signal 10 } 
	{ fwork_q1 sc_in sc_lv 32 signal 10 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "C_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "C_array", "role": "address0" }} , 
 	{ "name": "C_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_array", "role": "ce0" }} , 
 	{ "name": "C_array_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_array", "role": "we0" }} , 
 	{ "name": "C_array_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_array", "role": "d0" }} , 
 	{ "name": "Ar_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "Ar_array", "role": "address0" }} , 
 	{ "name": "Ar_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "Ar_array", "role": "ce0" }} , 
 	{ "name": "Ar_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "Ar_array", "role": "q0" }} , 
 	{ "name": "Ar_ndim_read", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "Ar_ndim_read", "role": "default" }} , 
 	{ "name": "Ar_numel_read", "direction": "in", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "Ar_numel_read", "role": "default" }} , 
 	{ "name": "Ar_shape_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "Ar_shape", "role": "address0" }} , 
 	{ "name": "Ar_shape_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "Ar_shape", "role": "ce0" }} , 
 	{ "name": "Ar_shape_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "Ar_shape", "role": "q0" }} , 
 	{ "name": "B_array_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "B_array", "role": "address0" }} , 
 	{ "name": "B_array_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_array", "role": "ce0" }} , 
 	{ "name": "B_array_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_array", "role": "q0" }} , 
 	{ "name": "B_ndim_read", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "B_ndim_read", "role": "default" }} , 
 	{ "name": "B_numel_read", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "B_numel_read", "role": "default" }} , 
 	{ "name": "B_shape_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "B_shape", "role": "address0" }} , 
 	{ "name": "B_shape_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_shape", "role": "ce0" }} , 
 	{ "name": "B_shape_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "B_shape", "role": "q0" }} , 
 	{ "name": "axesA_0_read", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "axesA_0_read", "role": "default" }} , 
 	{ "name": "fwork_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "fwork", "role": "address0" }} , 
 	{ "name": "fwork_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fwork", "role": "ce0" }} , 
 	{ "name": "fwork_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fwork", "role": "we0" }} , 
 	{ "name": "fwork_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fwork", "role": "d0" }} , 
 	{ "name": "fwork_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fwork", "role": "q0" }} , 
 	{ "name": "fwork_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "fwork", "role": "address1" }} , 
 	{ "name": "fwork_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fwork", "role": "ce1" }} , 
 	{ "name": "fwork_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fwork", "role": "q1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "12", "13", "14", "15", "16", "17", "18", "19"],
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
					{"ID" : "9", "SubInstance" : "grp_k2c_idx2sub_fu_647", "Port" : "shape"}]},
			{"Name" : "B_array", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_ndim_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "B_numel_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "B_shape", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "9", "SubInstance" : "grp_k2c_idx2sub_fu_647", "Port" : "shape"}]},
			{"Name" : "axesA_0_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "fwork", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.permA_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.permB_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.freeA_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.freeB_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.newshpA_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.newshpB_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.Asub_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.Bsub_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_k2c_idx2sub_fu_647", "Parent" : "0", "Child" : ["10", "11"],
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
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_idx2sub_fu_647.face_classifier_cbkb_U1", "Parent" : "9"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_k2c_idx2sub_fu_647.face_classifier_ccud_U2", "Parent" : "9"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_k2c_sub2idx_fu_658", "Parent" : "0",
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
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cdEe_U90", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_ceOg_U91", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cfYi_U92", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cvdy_U93", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_chbi_U94", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cwdI_U95", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.face_classifier_cxdS_U96", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
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
		ndim {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
	{"Pipeline" : "5", "EnableSignal" : "ap_enable_pp5"}
	{"Pipeline" : "6", "EnableSignal" : "ap_enable_pp6"}
	{"Pipeline" : "7", "EnableSignal" : "ap_enable_pp7"}
]}

set Spec2ImplPortList { 
	C_array { ap_memory {  { C_array_address0 mem_address 1 12 }  { C_array_ce0 mem_ce 1 1 }  { C_array_we0 mem_we 1 1 }  { C_array_d0 mem_din 1 32 } } }
	Ar_array { ap_memory {  { Ar_array_address0 mem_address 1 12 }  { Ar_array_ce0 mem_ce 1 1 }  { Ar_array_q0 mem_dout 0 32 } } }
	Ar_ndim_read { ap_none {  { Ar_ndim_read in_data 0 64 } } }
	Ar_numel_read { ap_none {  { Ar_numel_read in_data 0 12 } } }
	Ar_shape { ap_memory {  { Ar_shape_address0 mem_address 1 3 }  { Ar_shape_ce0 mem_ce 1 1 }  { Ar_shape_q0 mem_dout 0 64 } } }
	B_array { ap_memory {  { B_array_address0 mem_address 1 19 }  { B_array_ce0 mem_ce 1 1 }  { B_array_q0 mem_dout 0 32 } } }
	B_ndim_read { ap_none {  { B_ndim_read in_data 0 64 } } }
	B_numel_read { ap_none {  { B_numel_read in_data 0 64 } } }
	B_shape { ap_memory {  { B_shape_address0 mem_address 1 3 }  { B_shape_ce0 mem_ce 1 1 }  { B_shape_q0 mem_dout 0 64 } } }
	axesA_0_read { ap_none {  { axesA_0_read in_data 0 64 } } }
	fwork { ap_memory {  { fwork_address0 mem_address 1 11 }  { fwork_ce0 mem_ce 1 1 }  { fwork_we0 mem_we 1 1 }  { fwork_d0 mem_din 1 32 }  { fwork_q0 mem_dout 0 32 }  { fwork_address1 mem_address 1 11 }  { fwork_ce1 mem_ce 1 1 }  { fwork_q1 mem_dout 0 32 } } }
}
