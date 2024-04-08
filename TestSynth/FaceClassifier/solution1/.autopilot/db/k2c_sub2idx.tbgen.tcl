set moduleName k2c_sub2idx
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
set C_modelName {k2c_sub2idx}
set C_modelType { int 64 }
set C_modelArgList {
	{ sub int 64 regular {array 5 { 1 3 } 1 1 }  }
	{ shape int 64 regular {array 5 { 1 3 } 1 1 }  }
	{ ndim int 64 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "sub", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "shape", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "ndim", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "ap_return", "interface" : "wire", "bitwidth" : 64} ]}
# RTL Port declarations: 
set portNum 14
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ sub_address0 sc_out sc_lv 3 signal 0 } 
	{ sub_ce0 sc_out sc_logic 1 signal 0 } 
	{ sub_q0 sc_in sc_lv 64 signal 0 } 
	{ shape_address0 sc_out sc_lv 3 signal 1 } 
	{ shape_ce0 sc_out sc_logic 1 signal 1 } 
	{ shape_q0 sc_in sc_lv 64 signal 1 } 
	{ ndim sc_in sc_lv 64 signal 2 } 
	{ ap_return sc_out sc_lv 64 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "sub_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "sub", "role": "address0" }} , 
 	{ "name": "sub_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "sub", "role": "ce0" }} , 
 	{ "name": "sub_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "sub", "role": "q0" }} , 
 	{ "name": "shape_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "shape", "role": "address0" }} , 
 	{ "name": "shape_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "shape", "role": "ce0" }} , 
 	{ "name": "shape_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "shape", "role": "q0" }} , 
 	{ "name": "ndim", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "ndim", "role": "default" }} , 
 	{ "name": "ap_return", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "ap_return", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
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
			{"Name" : "ndim", "Type" : "None", "Direction" : "I"}]}]}


set ArgLastReadFirstWriteLatency {
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
	sub { ap_memory {  { sub_address0 mem_address 1 3 }  { sub_ce0 mem_ce 1 1 }  { sub_q0 mem_dout 0 64 } } }
	shape { ap_memory {  { shape_address0 mem_address 1 3 }  { shape_ce0 mem_ce 1 1 }  { shape_q0 mem_dout 0 64 } } }
	ndim { ap_none {  { ndim in_data 0 64 } } }
}
