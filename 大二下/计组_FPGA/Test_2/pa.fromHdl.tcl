
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name Test_2 -dir "D:/programing/FPGA/Test_2/planAhead_run_2" -part xc6slx16csg324-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "Test_2.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {Test_2.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top Test_2 $srcset
add_files [list {Test_2.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc6slx16csg324-3
