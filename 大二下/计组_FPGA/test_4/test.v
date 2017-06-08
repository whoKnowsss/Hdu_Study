`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:05:15 04/19/2017
// Design Name:   shiyan4
// Module Name:   F:/Xilinx_ISE/FPGA/shiyan4/test.v
// Project Name:  shiyan4
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: shiyan4
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test;

	// Inputs
	reg [4:0] W_Addr;
	reg Write_Reg;
	reg Clk;
	reg Reset;
	reg [1:0] C1;
	reg C2;

	// Outputs
	wire [31:0] R_Data_A;
	wire [31:0] R_Data_B;
	wire [7:0] LED;

	// Instantiate the Unit Under Test (UUT)
	shiyan4 uut (
		.W_Addr(W_Addr), 
		.Write_Reg(Write_Reg), 
		.R_Data_A(R_Data_A), 
		.R_Data_B(R_Data_B), 
		.Clk(Clk), 
		.Reset(Reset), 
		.LED(LED), 
		.C1(C1), 
		.C2(C2)
	);

	initial begin
		// Initialize Inputs
		W_Addr = 0;
		Write_Reg = 0;
		Clk = 0;
		Reset = 0;
		C1 = 0;
		C2 = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		W_Addr = 5'b00001;;
		Write_Reg = 1;
		Clk = 1;
		Reset = 0;
		C1 = 0;
		C2 = 0;
		
		#100
		W_Addr = 1;
		Write_Reg = 1;
		Clk = 0;
		Reset = 0;
		C1 = 0;
		C2 = 0;
		
		#100
		W_Addr = 5'b00010;
		Write_Reg = 1;
		Clk = 1;
		Reset = 0;
		C1 = 2'b01;
		C2 = 1;
		
		#100
		W_Addr = 5'b00010; 
		Write_Reg = 0;
		Clk = 0;
		Reset = 0;
		C1 = 2'b01;
		C2 = 1;
		
		#100
		W_Addr = 5'b00010; 
		Write_Reg = 1;
		Clk = 1;
		Reset = 0;
		C1 = 2'b10;
		C2 = 1;
		
		#100
		W_Addr = 5'b00010; 
		Write_Reg = 1;
		Clk = 0;
		Reset = 0;
		C1 = 2'b10;
		C2 = 1;
		
		#100
		W_Addr = 5'b00010; 
		Write_Reg = 0;
		Clk = 1;
		Reset = 0;
		C1 = 2'b10;
		C2 = 1;
		
		#100
		W_Addr = 5'b00010; 
		Write_Reg = 0;
		Clk = 1;
		Reset = 1;
		C1 = 2'b10;
		C2 = 1;
	end
      
endmodule

