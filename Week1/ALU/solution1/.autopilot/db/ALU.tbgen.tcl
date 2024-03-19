set C_TypeInfoList {{ 
"ALU" : [[], {"return": [[], {"scalar": "int"}] }, [{"ExternC" : 0}], [ {"inA": [[], {"array": [ {"scalar": "int"}, [1000]]}] }, {"inB": [[], {"array": [ {"scalar": "int"}, [1000]]}] }, {"op": [[], {"scalar": "int"}] }],[],""]
}}
set moduleName ALU
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
set C_modelName {ALU}
set C_modelType { int 32 }
set C_modelArgList {
	{ inA int 32 regular {array 1000 { 1 3 } 1 1 }  }
	{ inB int 32 regular {array 1000 { 1 3 } 1 1 }  }
	{ op int 32 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "inA", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "inA","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 999,"step" : 1}]}]}]} , 
 	{ "Name" : "inB", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "inB","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 999,"step" : 1}]}]}]} , 
 	{ "Name" : "op", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "op","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "ap_return", "interface" : "wire", "bitwidth" : 32,"bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "return","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 1,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 14
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ inA_address0 sc_out sc_lv 10 signal 0 } 
	{ inA_ce0 sc_out sc_logic 1 signal 0 } 
	{ inA_q0 sc_in sc_lv 32 signal 0 } 
	{ inB_address0 sc_out sc_lv 10 signal 1 } 
	{ inB_ce0 sc_out sc_logic 1 signal 1 } 
	{ inB_q0 sc_in sc_lv 32 signal 1 } 
	{ op sc_in sc_lv 32 signal 2 } 
	{ ap_return sc_out sc_lv 32 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "inA_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "inA", "role": "address0" }} , 
 	{ "name": "inA_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "inA", "role": "ce0" }} , 
 	{ "name": "inA_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inA", "role": "q0" }} , 
 	{ "name": "inB_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "inB", "role": "address0" }} , 
 	{ "name": "inB_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "inB", "role": "ce0" }} , 
 	{ "name": "inB_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inB", "role": "q0" }} , 
 	{ "name": "op", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "op", "role": "default" }} , 
 	{ "name": "ap_return", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ap_return", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "ALU",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1002", "EstimateLatencyMax" : "1002",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "inA", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "inB", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "op", "Type" : "None", "Direction" : "I"}]}]}


set ArgLastReadFirstWriteLatency {
	ALU {
		inA {Type I LastRead 2 FirstWrite -1}
		inB {Type I LastRead 2 FirstWrite -1}
		op {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "1002", "Max" : "1002"}
	, {"Name" : "Interval", "Min" : "1003", "Max" : "1003"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	inA { ap_memory {  { inA_address0 mem_address 1 10 }  { inA_ce0 mem_ce 1 1 }  { inA_q0 mem_dout 0 32 } } }
	inB { ap_memory {  { inB_address0 mem_address 1 10 }  { inB_ce0 mem_ce 1 1 }  { inB_q0 mem_dout 0 32 } } }
	op { ap_none {  { op in_data 0 32 } } }
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
