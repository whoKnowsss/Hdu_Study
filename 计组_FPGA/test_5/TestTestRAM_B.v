`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:48:47 05/14/2017
// Design Name:   TestRAM_B
// Module Name:   C:/Documents and Settings/job5/TestTestRAM_B.v
// Project Name:  job5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: TestRAM_B
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TestTestRAM_B;

	// Inputs
	reg [7:2] Mem_Addr;
	reg [1:0] C;
	reg Mem_Write;
	reg Clk;

	// Outputs
	wire [7:0] LED;

	// Instantiate the Unit Under Test (UUT)
	TestRAM_B uut (
		.Mem_Addr(Mem_Addr), 
		.C(C), 
		.Mem_Write(Mem_Write), 
		.Clk(Clk), 
		.LED(LED)
	);

	initial begin
		// Initialize Inputs
		Mem_Addr = 0;
		C = 0;
		Mem_Write = 0; 
		Clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
      Mem_Addr = 6'b100000;
		Mem_Write = 1;
		//write h1234_5678
		//00010010 00110100 01010110 01111000
		C = 2'b10;
		#100;
		Clk = 1;
		#100;
		Clk = 0;
		#100;
		Mem_Write = 0;
		C = 2'b01;
		#100;
		C = 2'b10;
		// Add stimulus here

	end
      
endmodule

