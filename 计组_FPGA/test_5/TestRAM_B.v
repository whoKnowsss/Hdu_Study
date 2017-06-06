`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:31:54 05/14/2017 
// Design Name: 
// Module Name:    TestRAM_B 
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
module TestRAM_B(Mem_Addr,C,Mem_Write,Clk,LED
    );
	 
	 
	input [7:2]Mem_Addr;
	input [1:0]C;
	input Mem_Write,Clk;
   output reg [7:0]LED;
	wire [31:0]M_R_Data;
	reg [31:0]M_W_Data; 
	RAM_B ram (//调用模块
	  .clka(Clk), // input clka
	  .wea(Mem_Write), // input [0 : 0] wea
	  .addra(Mem_Addr[7:2]), // input [5 : 0] addra
	  .dina(M_W_Data), // input [31 : 0] dina
	  .douta(M_R_Data) // output [31 : 0] douta
	);
	always@(*)
		begin
			LED=0;
			M_W_Data=0;
			if(!Mem_Write)//为0
				begin
					case(C)
						2'b00:LED=M_R_Data[7:0]; 
						2'b01:LED=M_R_Data[15:8];
						2'b10:LED=M_R_Data[23:16];
						2'b11:LED=M_R_Data[31:24];
					endcase
				end
			else
				begin
					case(C)
						2'b00:M_W_Data=32'h0002_0003;
						2'b01:M_W_Data=32'h0002_0603; 
						2'b10:M_W_Data=32'h1234_5678; 
						2'b11:M_W_Data=32'hffff_ffff; 
					endcase
				end 
		end
endmodule
