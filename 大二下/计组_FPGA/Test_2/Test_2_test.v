`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:09:23 04/18/2017
// Design Name:   Test_2
// Module Name:   D:/programing/FPGA/Test_2/Test_2_test.v
// Project Name:  Test_2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Test_2
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Test_2_test;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;
	reg C0;

	// Outputs
	wire C4;
	wire [3:0] F;

	// Instantiate the Unit Under Test (UUT)
	Test_2 uut (
		.A(A), 
		.B(B), 
		.C0(C0), 
		.C4(C4), 
		.F(F)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		C0 = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
      A=1100;B=1011;C0=0;
		#100;
		
		A=1011;B=0010;C0=1;
		#100;
		
		A=1011;B=1101;C0=0;
		#100;
		
		A=1010;B=0010;C0=1;
		#100;
		
		A=0111;B=1000;C0=0;
		#100;
		
		A=0011;B=0100;C0=1;
		#100;
		
		A=1001;B=0001;C0=0;
		#100;
	end
      
endmodule

