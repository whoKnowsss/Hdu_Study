`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:16:39 05/01/2017 
// Design Name: 
// Module Name:    test_3 
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
module test_3(ALU_OP,AB_SW,F_LED_SW,LED,OF,ZF,F);
  reg [31:0]A,B;  
input [2:0]ALU_OP; 
input [2:0]AB_SW;  
input [2:0]F_LED_SW; 
reg [31:0]F; 
output reg[7:0]LED;
 wire OF;  
 reg ZF;  
reg C32; 
output OF; 
output ZF; 
output F; 
//output LED; 
always@(*) 
begin   
   case(AB_SW)
   3'b000: begin A=32'h0000_0000; B=32'h0000_0000; end
   3'b001: begin A=32'h0000_0003; B=32'h0000_0607; end   
	3'b010: begin A=32'h8000_0000; B=32'h8000_0000; end   
	3'b011: begin A=32'h7FFF_FFFF; B=32'h7FFF_FFFF; end   
	3'b100: begin A=32'hFFFF_FFFF; B=32'hFFFF_FFFF; end   
	3'b101: begin A=32'h8000_0000; B=32'hFFFF_FFFF; end   
	3'b110: begin A=32'hFFFF_FFFF; B=32'h8000_0000; end   
	3'b111: begin A=32'h1234_5678; B=32'h3333_2222; end   
	default: begin A=32'h9ABC_DEF0;B=32'h1111_2222; end   
	endcase
end

always@(*) 
begin  
   case(ALU_OP)  
	3'b000: F<=A&B;  
	3'b001: F<=A|B;  
	3'b010: F<=A^B;  
	3'b011: F<=A~^B;  
	3'b100: {C32,F}<=A+B;  
	3'b101: {C32,F}<=A-B;  
	3'b110: begin if(A<B) F<=32'h0000_0001; else F<=32'h0000_0000; end  
	3'b111: begin   F<=B<<A; end  
	default: F<=32'h0000_0000;   
	endcase 
end   

always@(*) 
begin  
   if(F===32'h0000_0000)  
	ZF<=1;  
	else  
	ZF<=0; 
end  

assign OF=C32^F[31]^A[31]^B[31]; 

always@(*)
begin
case(F_LED_SW)
3'b000: LED[7:0]=F[7:0]; 
3'b001: LED[7:0]=F[15:8]; 
3'b010: LED[7:0]=F[23:16]; 
3'b011: LED[7:0]=F[31:24]; 
default:begin LED[7]=ZF;LED[0]=OF;LED[6:1]=6'b0;end
endcase
end
endmodule
