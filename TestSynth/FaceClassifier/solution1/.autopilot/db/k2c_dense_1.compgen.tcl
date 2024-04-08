# This script segment is generated automatically by AutoPilot

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
    id 140 \
    name output_array \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename output_array \
    op interface \
    ports { output_array_address0 { O 19 vector } output_array_ce0 { O 1 bit } output_array_we0 { O 1 bit } output_array_d0 { O 32 vector } output_array_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'output_array'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 142 \
    name input_array \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename input_array \
    op interface \
    ports { input_array_address0 { O 19 vector } input_array_ce0 { O 1 bit } input_array_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'input_array'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 145 \
    name input_shape \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename input_shape \
    op interface \
    ports { input_shape_address0 { O 3 vector } input_shape_ce0 { O 1 bit } input_shape_q0 { I 64 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'input_shape'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 146 \
    name kernel_array \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename kernel_array \
    op interface \
    ports { kernel_array_address0 { O 19 vector } kernel_array_ce0 { O 1 bit } kernel_array_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'kernel_array'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 149 \
    name kernel_shape \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename kernel_shape \
    op interface \
    ports { kernel_shape_address0 { O 3 vector } kernel_shape_ce0 { O 1 bit } kernel_shape_q0 { I 64 vector } kernel_shape_address1 { O 3 vector } kernel_shape_ce1 { O 1 bit } kernel_shape_q1 { I 64 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'kernel_shape'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 150 \
    name bias_array \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename bias_array \
    op interface \
    ports { bias_array_address0 { O 19 vector } bias_array_ce0 { O 1 bit } bias_array_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'bias_array'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 152 \
    name fwork \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename fwork \
    op interface \
    ports { fwork_address0 { O 7 vector } fwork_ce0 { O 1 bit } fwork_we0 { O 1 bit } fwork_d0 { O 32 vector } fwork_q0 { I 32 vector } fwork_address1 { O 7 vector } fwork_ce1 { O 1 bit } fwork_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'fwork'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 141 \
    name output_numel_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_output_numel_read \
    op interface \
    ports { output_numel_read { I 64 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 143 \
    name input_ndim_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_input_ndim_read \
    op interface \
    ports { input_ndim_read { I 64 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 144 \
    name input_numel_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_input_numel_read \
    op interface \
    ports { input_numel_read { I 64 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 147 \
    name kernel_ndim_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_kernel_ndim_read \
    op interface \
    ports { kernel_ndim_read { I 64 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 148 \
    name kernel_numel_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_kernel_numel_read \
    op interface \
    ports { kernel_numel_read { I 64 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 151 \
    name bias_numel_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_bias_numel_read \
    op interface \
    ports { bias_numel_read { I 64 vector } } \
} "
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


