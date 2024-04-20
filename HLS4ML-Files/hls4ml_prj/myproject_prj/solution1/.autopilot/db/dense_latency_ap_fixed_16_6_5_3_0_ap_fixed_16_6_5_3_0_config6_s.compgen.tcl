# This script segment is generated automatically by AutoPilot

set id 12
set name myproject_mul_mul_9s_11s_25_1_1
set corename simcore_mul
set op mul
set stage_num 1
set max_latency -1
set registered_input 1
set in0_width 9
set in0_signed 1
set in1_width 11
set in1_signed 1
set out_width 25
set exp i0*i1
set arg_lists {i0 {9 1 +} i1 {11 1 +} p {25 1 +} acc {0} }
set TrueReset 0
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mul] == "ap_gen_simcore_mul"} {
eval "ap_gen_simcore_mul { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    true_reset ${TrueReset} \
    stage_num ${stage_num} \
    max_latency ${max_latency} \
    registered_input ${registered_input} \
    in0_width ${in0_width} \
    in0_signed ${in0_signed} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    out_width ${out_width} \
    exp ${exp} \
    arg_lists {${arg_lists}} \
}"
} else {
puts "@W \[IMPL-100\] Cannot find ap_gen_simcore_mul, check your AutoPilot builtin lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler ${name}
}


set op mul
set corename DSP48
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_dsp48] == "::AESL_LIB_VIRTEX::xil_gen_dsp48"} {
eval "::AESL_LIB_VIRTEX::xil_gen_dsp48 { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    true_reset ${TrueReset} \
    stage_num ${stage_num} \
    max_latency ${max_latency} \
    registered_input ${registered_input} \
    in0_width ${in0_width} \
    in0_signed ${in0_signed} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    out_width ${out_width} \
    exp ${exp} \
    arg_lists {${arg_lists}} \
}"
} else {
puts "@W \[IMPL-101\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_dsp48, check your platform lib"
}
}


# Memory (RAM/ROM)  definition:
set ID 14
set hasByteEnable 0
set MemName dense_latency_ap_fixed_16_6_5_3_0_ap_fixed_16_6_5_3_0_config6_s_w6_V
set CoreName ap_simcore_mem
set PortList { 1 }
set DataWd 9
set AddrRange 1000
set AddrWd 10
set TrueReset 0
set IsROM 1
set ROMData { "110111011" "000101010" "000110100" "110100000" "000110111" "110010110" "000011010" "111110100" "110010110" "000001001" "110101001" "110011011" "001000101" "110110110" "111000111" "111000010" "111001110" "000100000" "111101011" "000000111" "111000000" "110110010" "000110001" "111010011" "000000101" "000110011" "000011101" "111001000" "110001110" "110110111" "001000000" "111100000" "000010001" "111100100" "110101111" "001000110" "000010001" "110101000" "111010100" "000011000" "111101000" "000000111" "000000100" "111101001" "001010111" "001001101" "000010100" "110100011" "110010110" "110110110" "111101111" "111001111" "111000011" "001100110" "111111110" "000000011" "110100111" "110110010" "111000101" "110010111" "001010111" "001110000" "110101001" "000110010" "110100100" "111010000" "111001101" "001010110" "110111100" "000001010" "111001011" "001110100" "111110010" "110111101" "001011110" "001011000" "110101101" "000111111" "000000100" "000100000" "110110100" "001011011" "000010110" "111110100" "000001011" "110110001" "000101100" "111001111" "000100101" "111001101" "001011001" "111100100" "111001110" "110111101" "110100000" "001001010" "110001001" "110111111" "111001100" "001010100" "001101011" "000011101" "111010001" "000011000" "001010100" "000111010" "111101010" "000011110" "111011000" "000111110" "110110000" "110011101" "111110010" "111110000" "111100001" "000011010" "001000110" "000001011" "000100000" "000111100" "111010000" "111101001" "111110001" "110111000" "001001000" "111001101" "001000111" "110011100" "000000000" "001010110" "000110110" "000000100" "110010010" "001011111" "001100001" "111001111" "110000101" "111001011" "000010101" "000110011" "001100110" "000101110" "000101101" "111011110" "111011101" "110111001" "000010001" "110101010" "001001101" "000000101" "001011001" "110011001" "000011100" "111011011" "110011111" "110111001" "111111100" "001011101" "110110000" "000110111" "111001111" "001110010" "110100010" "110100101" "000011011" "110011010" "111111110" "000000010" "111100100" "000000111" "001101101" "111001001" "110110111" "000001111" "000111010" "110101010" "001100111" "111000110" "000011111" "111011000" "001100101" "001101001" "000010000" "111110111" "110101011" "110100001" "001101101" "000100010" "001101101" "000101001" "000101101" "111001000" "110110001" "111111110" "110100100" "110110110" "111111111" "111010001" "111100001" "110101000" "000101110" "001100110" "111101011" "001011001" "001101000" "110100101" "001000010" "110110011" "110110111" "111110100" "000101011" "111011110" "110100111" "110110001" "000000111" "110010101" "001011011" "111111011" "000100101" "111000000" "111110111" "110010010" "000011001" "001011111" "110100110" "110100001" "001001110" "111111011" "111101111" "111000100" "111111100" "111010101" "111111011" "110011111" "111110000" "111000110" "111001000" "001010011" "001101000" "001010101" "110011000" "000011000" "111010100" "111001001" "110100000" "001010010" "000000110" "110101011" "111101111" "000000001" "110111100" "111111000" "110110010" "000001111" "111101000" "000111010" "010000110" "111010000" "111000010" "000000101" "111000101" "111110110" "000011000" "110100011" "001001101" "111010010" "001010010" "000110110" "110101010" "110011111" "111000000" "110101000" "000101011" "001000101" "111000010" "111011011" "111101001" "111011011" "000100110" "111111100" "001110111" "110110011" "111100110" "111000111" "111111011" "111011101" "111100001" "111011010" "000000100" "110011001" "000001111" "110011001" "110010000" "110101010" "000010100" "111110101" "000100101" "111101010" "111010100" "000110000" "111000000" "000000101" "001100101" "000111111" "111101100" "111010000" "001100110" "111011010" "000001101" "111001111" "110011101" "111100101" "111010110" "111101100" "110111001" "001010110" "110101111" "111110101" "111011100" "001110011" "000100010" "000011000" "111001100" "001000010" "001100111" "001001001" "111000000" "110101110" "000100011" "001001000" "000011111" "110111010" "111001001" "110100001" "000101001" "111010010" "001100011" "110111011" "000011101" "001011111" "001100111" "001110010" "110110100" "000001111" "111100010" "110101010" "000101000" "000010100" "111110110" "111011101" "001011011" "111101101" "001101010" "001011101" "000000001" "000010001" "110101011" "110111000" "001101000" "001100011" "001001110" "000100110" "111101100" "001011011" "001011111" "000111100" "000011111" "001011001" "110110111" "001011010" "110100110" "111000001" "001011011" "111100001" "111101111" "111110011" "111001010" "001000001" "110010110" "000101101" "001000111" "110001011" "000011000" "110110000" "001000010" "000001011" "001000110" "111000100" "110111000" "111001000" "110010110" "000001000" "001000111" "111101001" "000011011" "001001000" "110110110" "000010000" "111001111" "110110100" "000000101" "110111111" "001011110" "111101011" "001010110" "110100111" "110001111" "001000111" "000001100" "110011001" "110101101" "001001010" "111111000" "000001001" "110110101" "110100010" "001111000" "110110100" "111111101" "001010101" "111111101" "001101111" "001001000" "110010110" "000111000" "001100011" "000111000" "001010001" "000000001" "001101110" "000111110" "001011001" "111010011" "000010010" "000011011" "001010110" "000001001" "110101011" "001110101" "111001000" "111010101" "001010010" "110111111" "000100011" "000011100" "000100101" "000111010" "110101100" "000011011" "001010000" "001011110" "000100001" "111011111" "111101000" "000111100" "001100010" "000000101" "000110000" "110111010" "000000011" "111000000" "110111000" "111101111" "110110010" "110101100" "110010011" "001101010" "110011110" "001000101" "110111111" "000000100" "111010111" "111111001" "000111111" "000110011" "000111011" "111000010" "000100101" "111111101" "001001011" "000000010" "001011011" "000100111" "110011111" "000010100" "111000101" "001000011" "001000010" "001100000" "110110010" "111110000" "000100101" "111110110" "000110111" "110011111" "000000111" "110011001" "001100010" "000111101" "001010000" "111001110" "111100110" "111101100" "000001001" "000100000" "000101001" "001000111" "111000100" "000100010" "001011010" "001011010" "000000011" "111011100" "000101010" "110011111" "000100101" "000100101" "000110010" "001110001" "111000110" "000011101" "111011101" "110010100" "000111101" "111001010" "111111110" "111011000" "110110000" "111100110" "000000101" "111010101" "111101010" "110100010" "001010111" "000000010" "001001111" "000111101" "001001111" "110101000" "111101001" "111000110" "001000011" "111110110" "111100110" "111000101" "000010010" "001010111" "110110000" "001000101" "001001100" "001011010" "001011011" "111000101" "000101110" "000111001" "110110000" "000000101" "111001100" "111010111" "000111000" "111110000" "110010111" "110000111" "111110011" "110111001" "111110011" "110101000" "000101000" "111001101" "001000100" "000100100" "110011101" "001000110" "111010001" "110011010" "110011111" "110110010" "001001010" "000001010" "110111101" "000011011" "111011011" "000010111" "110011011" "110101011" "001001001" "000101110" "111110000" "000010101" "111111011" "000110101" "001001111" "001011001" "110100101" "001010110" "001001111" "001000010" "000110101" "110101010" "111100001" "001000011" "111000100" "111101001" "110111000" "111111110" "111110101" "000110100" "110101110" "001000110" "001000101" "001011011" "111110001" "001000000" "000011100" "000100101" "001000001" "001011100" "110011111" "111011000" "110111001" "001001000" "000101010" "110011010" "110100100" "110011111" "111110010" "001100110" "001011100" "111011001" "000110010" "110110111" "001001110" "000111111" "111010110" "110111111" "111000001" "001101000" "001011100" "111000111" "111001011" "001100011" "110101001" "001000011" "111101101" "111110000" "000101100" "111001101" "000110010" "111000101" "111001111" "001110000" "000011110" "111001100" "001000000" "110110111" "000100110" "001001001" "110101000" "110001111" "111111011" "001100101" "111010010" "000000111" "111010000" "111011111" "111000100" "000010010" "000011110" "001011000" "110101100" "000001000" "111000111" "001100010" "111010110" "001000100" "000100001" "111111000" "111001101" "110010011" "000001100" "000001000" "111000011" "111010011" "111010010" "000001001" "110011111" "001010000" "000000110" "110111000" "000001110" "000110100" "111111111" "000110000" "110101101" "000011110" "000100011" "000100101" "110011011" "111101110" "111011000" "110100101" "000011111" "111101011" "110011111" "000010010" "111000101" "110111000" "110110011" "001101110" "001011111" "111001101" "110010110" "111110110" "001011010" "001011100" "111101101" "111001010" "000100000" "111101011" "111000001" "001100100" "001101100" "000011011" "000001101" "000011100" "111100001" "110110111" "111011110" "110101111" "000010001" "000010000" "000000100" "110110001" "000110001" "000011010" "000100011" "111010011" "111000010" "001000100" "111111111" "001101001" "111011010" "111101110" "001011101" "001100110" "110111010" "000100000" "000011001" "111110011" "001000000" "111101010" "000010111" "110101110" "000000001" "001100110" "000010011" "111001101" "000010100" "110110111" "111001001" "110100011" "000110010" "110101000" "000100100" "110100101" "000001000" "110101101" "110101011" "000011001" "110111010" "110101100" "110011000" "111111111" "001010011" "000111000" "001100101" "111010001" "000100000" "000110011" "111101001" "111101011" "110011110" "111111010" "001100110" "000010110" "001100010" "110011100" "000110111" "110101011" "110100101" "000111101" "000101000" "110011101" "000001111" "000001000" "110010111" "001101111" "111110000" "000001110" "110011011" "001011001" "000111010" "111101011" "111001100" "001000111" "110110100" "001011100" "110101000" "111010011" "110111100" "110001110" "110100100" "111101011" "111111010" "000111000" "001000101" "111000010" "110101001" "001000001" "111100101" "111100101" "110100110" "001000110" "000001001" "000010011" "001101011" "110111101" "000001000" "000100000" "001100010" "111011011" "001100001" "110101000" "000100110" "000111001" "000111001" "000000111" "111000100" "001010010" "111010101" "000101100" "111101001" "110011101" "111101010" "111111000" "001010001" "000111010" "000110011" "000011001" "000000011" "110010100" "110101110" "000101110" "001001100" "001001010" "110100100" "001111010" "110011000" "111110000" "111001000" "001001011" "111111100" "001100100" "001011011" "001100101" "001100010" "001010110" "001010101" "110100011" "001000100" "111101010" "110001011" "111100110" "000100101" "111101001" "111010100" "111111001" "000111100" "001010111" "000110110" "111010000" "000011000" "110101000" "001001011" "000100001" "000110011" "110111010" "001000000" "111000010" "110100000" "001100111" "111000111" "000010001" "001101010" "000101011" "000010100" "001011011" "111101100" "000101100" "110101110" "111011010" "111110110" "001011010" "000000100" "000001010" "001011001" "110111111" "001100010" "110011110" "110010111" "001001001" "000000100" "111110101" "000101011" "001101001" "110101010" "000101100" "000111011" "001100100" "110011010" "111101011" "000111011" "001011000" "001000010" "111011101" "111001101" "001110001" "110011101" "000001001" "001001000" "001101011" "001101101" "111100001" "000110111" "111110110" "000111001" "000101100" "110111011" "001010011" "111000001" "110011000" "000101100" "111111011" "111101010" "111100001" "001000010" "111011001" "111100110" "001000001" "110111011" "001101101" "001011011" "000101110" "110111010" "110010001" "111000000" "000101000" "000100000" "111000111" "001000000" "111001001" "001010011" "110111100" "111110000" "001000011" "111111011" "000011011" "000101011" "110110101" "110100011" "111110111" "111000100" "001011010" "000111011" "001000010" "000010100" "000001100" "110100000" "000100100" "001010000" "001000110" "000001110" "111100100" "111101110" "001011100" "000101011" "000000011" "111101110" "000101010" "110100000" "111101111" "000101010" "000111000" "000101010" "000010001" "001011110" "001000011" "110101101" "001001001" "000100100" }
set HasInitializer 1
set Initializer $ROMData
set NumOfStage 2
set MaxLatency -1
set DelayBudget 2.033
set ClkPeriod 10
set RegisteredInput 0
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mem] == "ap_gen_simcore_mem"} {
    eval "ap_gen_simcore_mem { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    registered_input ${RegisteredInput} \
    port_num 1 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
} else {
    puts "@W \[IMPL-102\] Cannot find ap_gen_simcore_mem, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
  ::AP::rtl_comp_handler $MemName
}


set CoreName ROM_nP
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_ROM] == "::AESL_LIB_VIRTEX::xil_gen_ROM"} {
    eval "::AESL_LIB_VIRTEX::xil_gen_ROM { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    registered_input ${RegisteredInput} \
    port_num 1 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
  } else {
    puts "@W \[IMPL-104\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_ROM, check your platform lib"
  }
}


# Memory (RAM/ROM)  definition:
set ID 15
set hasByteEnable 0
set MemName dense_latency_ap_fixed_16_6_5_3_0_ap_fixed_16_6_5_3_0_config6_s_b6_V
set CoreName ap_simcore_mem
set PortList { 1 }
set DataWd 8
set AddrRange 10
set AddrWd 4
set TrueReset 0
set IsROM 1
set ROMData { "11101110" "11100011" "00000010" "00011100" "10010100" "10101001" "00011100" "00100001" "11111000" "11011000" }
set HasInitializer 1
set Initializer $ROMData
set NumOfStage 2
set MaxLatency -1
set DelayBudget 2.033
set ClkPeriod 10
set RegisteredInput 0
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mem] == "ap_gen_simcore_mem"} {
    eval "ap_gen_simcore_mem { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    registered_input ${RegisteredInput} \
    port_num 1 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
} else {
    puts "@W \[IMPL-102\] Cannot find ap_gen_simcore_mem, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
  ::AP::rtl_comp_handler $MemName
}


set CoreName ROM_nP
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_ROM] == "::AESL_LIB_VIRTEX::xil_gen_ROM"} {
    eval "::AESL_LIB_VIRTEX::xil_gen_ROM { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    registered_input ${RegisteredInput} \
    port_num 1 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
  } else {
    puts "@W \[IMPL-104\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_ROM, check your platform lib"
  }
}


# Memory (RAM/ROM)  definition:
set ID 16
set hasByteEnable 0
set MemName dense_latency_ap_fixed_16_6_5_3_0_ap_fixed_16_6_5_3_0_config6_s_mult_V
set CoreName ap_simcore_mem
set PortList { 2 3 }
set DataWd 16
set AddrRange 1000
set AddrWd 10
set impl_style block
set TrueReset 0
set HasInitializer 0
set IsROM 0
set ROMData {}
set NumOfStage 2
set MaxLatency -1
set DelayBudget 2.033
set ClkPeriod 10
set RegisteredInput 0
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mem] == "ap_gen_simcore_mem"} {
    eval "ap_gen_simcore_mem { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    registered_input ${RegisteredInput} \
    port_num 2 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
} else {
    puts "@W \[IMPL-102\] Cannot find ap_gen_simcore_mem, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
  ::AP::rtl_comp_handler $MemName
}


set CoreName RAM
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_RAM] == "::AESL_LIB_VIRTEX::xil_gen_RAM"} {
    eval "::AESL_LIB_VIRTEX::xil_gen_RAM { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    registered_input ${RegisteredInput} \
    port_num 2 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
  } else {
    puts "@W \[IMPL-104\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_RAM, check your platform lib"
  }
}


# Memory (RAM/ROM)  definition:
set ID 17
set hasByteEnable 0
set MemName dense_latency_ap_fixed_16_6_5_3_0_ap_fixed_16_6_5_3_0_config6_s_acc_V
set CoreName ap_simcore_mem
set PortList { 2 3 }
set DataWd 16
set AddrRange 10
set AddrWd 4
set impl_style block
set TrueReset 0
set HasInitializer 0
set IsROM 0
set ROMData {}
set NumOfStage 2
set MaxLatency -1
set DelayBudget 0.867
set ClkPeriod 10
set RegisteredInput 0
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mem] == "ap_gen_simcore_mem"} {
    eval "ap_gen_simcore_mem { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    registered_input ${RegisteredInput} \
    port_num 2 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
} else {
    puts "@W \[IMPL-102\] Cannot find ap_gen_simcore_mem, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
  ::AP::rtl_comp_handler $MemName
}


set CoreName RAM
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_RAM] == "::AESL_LIB_VIRTEX::xil_gen_RAM"} {
    eval "::AESL_LIB_VIRTEX::xil_gen_RAM { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    registered_input ${RegisteredInput} \
    port_num 2 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
  } else {
    puts "@W \[IMPL-104\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_RAM, check your platform lib"
  }
}


# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 18 \
    name data_V \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename data_V \
    op interface \
    ports { data_V_address0 { O 7 vector } data_V_ce0 { O 1 bit } data_V_q0 { I 11 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'data_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 19 \
    name res_V \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename res_V \
    op interface \
    ports { res_V_address0 { O 4 vector } res_V_ce0 { O 1 bit } res_V_we0 { O 1 bit } res_V_d0 { O 16 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'res_V'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -2 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


