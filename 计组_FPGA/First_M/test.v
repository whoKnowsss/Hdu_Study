`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:15:23 04/11/2017
// Design Name:   First_M
// Module Name:   D:/programing/FPGA/First_M/test.v
// Project Name:  First_M
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: First_M
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
	reg A;
	reg B;
	reg C;
	reg D;
	reg E;

	// Outputs
	wire F;

	// Instantiate the Unit Under Test (UUT)
	First_M uut (
		.A(A), 
		.B(B), 
		.C(C), 
		.D(D), 
		.E(E), 
		.F(F)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 0;

		// Wait 100 ns for global reset to finish
		#200;
        
		// Add stimulus here
      #200;
		A = 0;
		B = 1;
		C = 0;
		D = 1;
		E = 0;
		
		
		#200;
		A = 1;
		B = 1;
		C = 0;
		D = 0;
		E = 1;
	end
      
endmodule

