////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: TestRAM_B_synthesis.v
// /___/   /\     Timestamp: Sun May 14 14:10:22 2017
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim TestRAM_B.ngc TestRAM_B_synthesis.v 
// Device	: xc6slx16-3-csg324
// Input file	: TestRAM_B.ngc
// Output file	: C:\Users\Administrator\Desktop\job5\netgen\synthesis\TestRAM_B_synthesis.v
// # of Modules	: 1
// Design Name	: TestRAM_B
// Xilinx        : F:\computerclass\14.7\ISE_DS\ISE\
//             
// Purpose:    
//     This verilog netlist is a verification model and uses simulation 
//     primitives which may not represent the true implementation of the 
//     device, however the netlist is functionally correct and should not 
//     be modified. This file cannot be synthesized and should only be used 
//     with supported simulation tools.
//             
// Reference:  
//     Command Line Tools User Guide, Chapter 23 and Synthesis and Simulation Design Guide, Chapter 6
//             
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns/1 ps

module TestRAM_B (
  Mem_Write, Clk, Mem_Addr, C, LED
)/* synthesis syn_black_box syn_noprune=1 */;
  input Mem_Write;
  input Clk;
  input [7 : 2] Mem_Addr;
  input [1 : 0] C;
  output [7 : 0] LED;
  
  // synthesis translate_off
  
  wire Mem_Addr_7_IBUF_0;
  wire Mem_Addr_6_IBUF_1;
  wire Mem_Addr_5_IBUF_2;
  wire Mem_Addr_4_IBUF_3;
  wire Mem_Addr_3_IBUF_4;
  wire Mem_Addr_2_IBUF_5;
  wire C_1_IBUF_6;
  wire C_0_IBUF_7;
  wire Mem_Write_IBUF_8;
  wire Clk_BUFGP_9;
  wire LED_7_OBUF_42;
  wire LED_6_OBUF_43;
  wire LED_5_OBUF_44;
  wire LED_4_OBUF_45;
  wire LED_3_OBUF_46;
  wire LED_2_OBUF_47;
  wire LED_1_OBUF_48;
  wire LED_0_OBUF_49;
  wire \M_W_Data[12] ;
  wire \M_W_Data[11] ;
  wire \M_W_Data[10] ;
  wire \M_W_Data[0] ;
  wire N2;
  wire N4;
  wire N6;
  wire N8;
  wire N10;
  wire N12;
  wire N14;
  wire N16;
  wire [31 : 0] M_R_Data;
  LUT3 #(
    .INIT ( 8'h80 ))
  \M_W_Data<11>1  (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .I2(C_0_IBUF_7),
    .O(\M_W_Data[11] )
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  \M_W_Data<12>1  (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .O(\M_W_Data[12] )
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \M_W_Data<10>1  (
    .I0(Mem_Write_IBUF_8),
    .I1(C_0_IBUF_7),
    .I2(C_1_IBUF_6),
    .O(\M_W_Data[10] )
  );
  LUT3 #(
    .INIT ( 8'hA2 ))
  \M_W_Data<0>1  (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .I2(C_0_IBUF_7),
    .O(\M_W_Data[0] )
  );
  LUT3 #(
    .INIT ( 8'h47 ))
  Mmux_LED1_SW0 (
    .I0(M_R_Data[8]),
    .I1(C_0_IBUF_7),
    .I2(M_R_Data[0]),
    .O(N2)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED1 (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .I2(M_R_Data[16]),
    .I3(C_0_IBUF_7),
    .I4(M_R_Data[24]),
    .I5(N2),
    .O(LED_0_OBUF_49)
  );
  LUT3 #(
    .INIT ( 8'h47 ))
  Mmux_LED8_SW0 (
    .I0(M_R_Data[15]),
    .I1(C_0_IBUF_7),
    .I2(M_R_Data[7]),
    .O(N4)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED8 (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .I2(M_R_Data[23]),
    .I3(C_0_IBUF_7),
    .I4(M_R_Data[31]),
    .I5(N4),
    .O(LED_7_OBUF_42)
  );
  LUT3 #(
    .INIT ( 8'h47 ))
  Mmux_LED7_SW0 (
    .I0(M_R_Data[14]),
    .I1(C_0_IBUF_7),
    .I2(M_R_Data[6]),
    .O(N6)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED7 (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .I2(M_R_Data[22]),
    .I3(C_0_IBUF_7),
    .I4(M_R_Data[30]),
    .I5(N6),
    .O(LED_6_OBUF_43)
  );
  LUT3 #(
    .INIT ( 8'h47 ))
  Mmux_LED6_SW0 (
    .I0(M_R_Data[13]),
    .I1(C_0_IBUF_7),
    .I2(M_R_Data[5]),
    .O(N8)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED6 (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .I2(M_R_Data[21]),
    .I3(C_0_IBUF_7),
    .I4(M_R_Data[29]),
    .I5(N8),
    .O(LED_5_OBUF_44)
  );
  LUT3 #(
    .INIT ( 8'h47 ))
  Mmux_LED5_SW0 (
    .I0(M_R_Data[12]),
    .I1(C_0_IBUF_7),
    .I2(M_R_Data[4]),
    .O(N10)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED5 (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .I2(M_R_Data[20]),
    .I3(C_0_IBUF_7),
    .I4(M_R_Data[28]),
    .I5(N10),
    .O(LED_4_OBUF_45)
  );
  LUT3 #(
    .INIT ( 8'h47 ))
  Mmux_LED4_SW0 (
    .I0(M_R_Data[11]),
    .I1(C_0_IBUF_7),
    .I2(M_R_Data[3]),
    .O(N12)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED4 (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .I2(M_R_Data[19]),
    .I3(C_0_IBUF_7),
    .I4(M_R_Data[27]),
    .I5(N12),
    .O(LED_3_OBUF_46)
  );
  LUT3 #(
    .INIT ( 8'h47 ))
  Mmux_LED3_SW0 (
    .I0(M_R_Data[10]),
    .I1(C_0_IBUF_7),
    .I2(M_R_Data[2]),
    .O(N14)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED3 (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .I2(M_R_Data[18]),
    .I3(C_0_IBUF_7),
    .I4(M_R_Data[26]),
    .I5(N14),
    .O(LED_2_OBUF_47)
  );
  LUT3 #(
    .INIT ( 8'h47 ))
  Mmux_LED2_SW0 (
    .I0(M_R_Data[9]),
    .I1(C_0_IBUF_7),
    .I2(M_R_Data[1]),
    .O(N16)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED2 (
    .I0(Mem_Write_IBUF_8),
    .I1(C_1_IBUF_6),
    .I2(M_R_Data[17]),
    .I3(C_0_IBUF_7),
    .I4(M_R_Data[25]),
    .I5(N16),
    .O(LED_1_OBUF_48)
  );
  IBUF   Mem_Addr_7_IBUF (
    .I(Mem_Addr[7]),
    .O(Mem_Addr_7_IBUF_0)
  );
  IBUF   Mem_Addr_6_IBUF (
    .I(Mem_Addr[6]),
    .O(Mem_Addr_6_IBUF_1)
  );
  IBUF   Mem_Addr_5_IBUF (
    .I(Mem_Addr[5]),
    .O(Mem_Addr_5_IBUF_2)
  );
  IBUF   Mem_Addr_4_IBUF (
    .I(Mem_Addr[4]),
    .O(Mem_Addr_4_IBUF_3)
  );
  IBUF   Mem_Addr_3_IBUF (
    .I(Mem_Addr[3]),
    .O(Mem_Addr_3_IBUF_4)
  );
  IBUF   Mem_Addr_2_IBUF (
    .I(Mem_Addr[2]),
    .O(Mem_Addr_2_IBUF_5)
  );
  IBUF   C_1_IBUF (
    .I(C[1]),
    .O(C_1_IBUF_6)
  );
  IBUF   C_0_IBUF (
    .I(C[0]),
    .O(C_0_IBUF_7)
  );
  IBUF   Mem_Write_IBUF (
    .I(Mem_Write),
    .O(Mem_Write_IBUF_8)
  );
  OBUF   LED_7_OBUF (
    .I(LED_7_OBUF_42),
    .O(LED[7])
  );
  OBUF   LED_6_OBUF (
    .I(LED_6_OBUF_43),
    .O(LED[6])
  );
  OBUF   LED_5_OBUF (
    .I(LED_5_OBUF_44),
    .O(LED[5])
  );
  OBUF   LED_4_OBUF (
    .I(LED_4_OBUF_45),
    .O(LED[4])
  );
  OBUF   LED_3_OBUF (
    .I(LED_3_OBUF_46),
    .O(LED[3])
  );
  OBUF   LED_2_OBUF (
    .I(LED_2_OBUF_47),
    .O(LED[2])
  );
  OBUF   LED_1_OBUF (
    .I(LED_1_OBUF_48),
    .O(LED[1])
  );
  OBUF   LED_0_OBUF (
    .I(LED_0_OBUF_49),
    .O(LED[0])
  );
  BUFGP   Clk_BUFGP (
    .I(Clk),
    .O(Clk_BUFGP_9)
  );
  RAM_B   ram (
    .clka(Clk_BUFGP_9),
    .wea({Mem_Write_IBUF_8}),
    .addra({Mem_Addr_7_IBUF_0, Mem_Addr_6_IBUF_1, Mem_Addr_5_IBUF_2, Mem_Addr_4_IBUF_3, Mem_Addr_3_IBUF_4, Mem_Addr_2_IBUF_5}),
    .dina({\M_W_Data[11] , \M_W_Data[11] , \M_W_Data[11] , \M_W_Data[12] , \M_W_Data[11] , \M_W_Data[11] , \M_W_Data[12] , \M_W_Data[11] , 
\M_W_Data[11] , \M_W_Data[11] , \M_W_Data[12] , \M_W_Data[12] , \M_W_Data[11] , \M_W_Data[12] , \M_W_Data[0] , \M_W_Data[11] , \M_W_Data[11] , 
\M_W_Data[12] , \M_W_Data[11] , \M_W_Data[12] , \M_W_Data[11] , \M_W_Data[10] , \M_W_Data[10] , \M_W_Data[11] , \M_W_Data[11] , \M_W_Data[12] , 
\M_W_Data[12] , \M_W_Data[12] , \M_W_Data[12] , \M_W_Data[11] , \M_W_Data[0] , \M_W_Data[0] }),
    .douta({M_R_Data[31], M_R_Data[30], M_R_Data[29], M_R_Data[28], M_R_Data[27], M_R_Data[26], M_R_Data[25], M_R_Data[24], M_R_Data[23], M_R_Data[22]
, M_R_Data[21], M_R_Data[20], M_R_Data[19], M_R_Data[18], M_R_Data[17], M_R_Data[16], M_R_Data[15], M_R_Data[14], M_R_Data[13], M_R_Data[12], 
M_R_Data[11], M_R_Data[10], M_R_Data[9], M_R_Data[8], M_R_Data[7], M_R_Data[6], M_R_Data[5], M_R_Data[4], M_R_Data[3], M_R_Data[2], M_R_Data[1], 
M_R_Data[0]})
  );

// synthesis translate_on

endmodule

// synthesis translate_off

`ifndef GLBL
`define GLBL

`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;

    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule

`endif

// synthesis translate_on
