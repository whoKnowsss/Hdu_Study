`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:46:01 04/11/2017
// Design Name:   test1
// Module Name:   D:/programing/FPGA/test1/test1_test.v
// Project Name:  test1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: test1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test1_test;

	// Inputs
	reg A;
	reg B;
	reg C;

	// Outputs
	wire F;
	wire Ci;

	// Instantiate the Unit Under Test (UUT)
	test1 uut (
		.A(A), 
		.B(B), 
		.C(C), 
		.F(F), 
		.Ci(Ci)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		C = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
      #100
		A=0;B=0;C=0;
		
		#100
		A=0;B=0;C=1;
		
		#100
		A=0;B=1;C=0;
		
		#100
		A=1;B=1;C=1;
		
		#100
		A=1;B=0;C=0;
		
		#100
		A=1;B=0;C=1;
		
		#100
		A=1;B=1;C=0;
		
		#100
		A=1;B=1;C=1;
		
	end
      
endmodule

