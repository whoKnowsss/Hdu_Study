`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:59:58 04/19/2017 
// Design Name: 
// Module Name:    shiyan4 
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
module shiyan4(W_Addr,Write_Reg,R_Data_A,R_Data_B,Clk,Reset,LED,C1,C2);
input Clk,Reset,C2;   //C2选择读A端口或B端口  =0读A =1读B
input[1:0]C1;         //复用控制
input wire Write_Reg;
reg[4:0]R_Addr_A,R_Addr_B;
input wire[4:0]W_Addr;
reg[31:0]W_Data;
output wire[31:0]R_Data_A,R_Data_B;
output reg[7:0]LED;
reg[31:0]REG_Files[0:31];

always@(R_Data_A or R_Data_B or W_Addr or Write_Reg or C1 or C2)
begin
	R_Addr_A=0;R_Addr_B=0;LED=0;
	if(!Write_Reg)
	begin
		if(!C2)
		begin
			R_Addr_A=W_Addr;
			case(C1)
				2'b00:LED=R_Data_A[7:0];
				2'b01:LED=R_Data_A[15:8];
				2'b10:LED=R_Data_A[23:16];
				2'b11:LED=R_Data_A[31:24];
			endcase
		end
		else
		begin
			R_Addr_B=W_Addr;
			case(C1)
				2'b00:LED=R_Data_B[7:0];
				2'b01:LED=R_Data_B[15:8];
				2'b10:LED=R_Data_B[23:16];
				2'b11:LED=R_Data_B[31:24];
			endcase
		end
end
end 

integer i;
always @(posedge Clk or posedge Reset)
begin
	if(Reset)
		begin
			for(i=0;i<32;i=i+1)
			REG_Files[i]=32'b0;
		end
	else
		begin
			if(Write_Reg)
				begin
				case(C1)
					2'b00:W_Data=32'h1234_5678;
					2'b01:W_Data=32'h0000_0607;
					2'b10:W_Data=32'h3333_2222;
					2'b11:W_Data=32'h9ABC_DEF0;
				endcase
				REG_Files[W_Addr]=W_Data;
				end
		end
end

assign R_Data_A = REG_Files[R_Addr_A];
assign R_Data_B = REG_Files[R_Addr_B];

endmodule
