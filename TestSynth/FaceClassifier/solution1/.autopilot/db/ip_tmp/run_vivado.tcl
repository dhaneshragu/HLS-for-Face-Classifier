create_project prj -part xcvu160-flgc2104-2-e -force
set_property target_language verilog [current_project]
set vivado_ver [version -short]
set COE_DIR "../../syn/verilog"
source "C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/syn/verilog/face_classifier_c_ap_dadd_2_full_dsp_64_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips face_classifier_c_ap_dadd_2_full_dsp_64]]
}
source "C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/syn/verilog/face_classifier_c_ap_faddfsub_2_full_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips face_classifier_c_ap_faddfsub_2_full_dsp_32]]
}
source "C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/syn/verilog/face_classifier_c_ap_fadd_2_full_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips face_classifier_c_ap_fadd_2_full_dsp_32]]
}
source "C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/syn/verilog/face_classifier_c_ap_fcmp_0_no_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips face_classifier_c_ap_fcmp_0_no_dsp_32]]
}
source "C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/syn/verilog/face_classifier_c_ap_fdiv_6_no_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips face_classifier_c_ap_fdiv_6_no_dsp_32]]
}
source "C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/syn/verilog/face_classifier_c_ap_fexp_4_full_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips face_classifier_c_ap_fexp_4_full_dsp_32]]
}
source "C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/syn/verilog/face_classifier_c_ap_fmul_0_max_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips face_classifier_c_ap_fmul_0_max_dsp_32]]
}
source "C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/syn/verilog/face_classifier_c_ap_fpext_0_no_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips face_classifier_c_ap_fpext_0_no_dsp_32]]
}
source "C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/syn/verilog/face_classifier_c_ap_fptrunc_0_no_dsp_64_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips face_classifier_c_ap_fptrunc_0_no_dsp_64]]
}
source "C:/Users/ketan/Desktop/college/CS-577-Course-Project/TestSynth/FaceClassifier/solution1/syn/verilog/face_classifier_c_ap_fsub_2_full_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips face_classifier_c_ap_fsub_2_full_dsp_32]]
}
