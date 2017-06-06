`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:08:41 04/18/2017 
// Design Name: 
// Module Name:    Test_2 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Test_2(A,B,C0,C4,F);
    input[3:0] A,B;   
	 input      C0;   
	 output[3:0] F;   
	 output      C4;   
	 wire[3:0]   A,B,F;   
	 wire        C0,C4;    
	 assign      G0=A[0]&B[0];   
	 assign      G1=A[1]&B[1];   
	 assign      G2=A[2]&B[2];   
	 assign      G3=A[3]&B[3];     
	 assign      P0=A[0]|B[0];   
	 assign      P1=A[1]|B[1];   
	 assign      P2=A[2]|B[2]; 
    assign      P3=A[3]|B[3];     
	 assign      C1=G0|(P0&C0);   
	 assign      C2=G1|(P1&C1);   
	 assign      C3=G2|(P2&C2);   
	 assign      C4=G3|(P3&C3);     
	 assign      F[0]=A[0]^B[0]^C0;   
	 assign      F[1]=A[1]^B[1]^C1;   
	 assign      F[2]=A[2]^B[2]^C2;   
	 assign      F[3]=A[3]^B[3]^C3;   
	 

endmodule
