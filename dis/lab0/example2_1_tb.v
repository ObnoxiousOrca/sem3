`timescale 1ns/1ns
`include "example2_1.v"

module example2_1_tb();
	reg x1, x2, x3, x4;
	wire f, g, h;

	example2_1 ex2_1(x1, x2, x3, x4, f, g, h);
	initial begin

		$dumpfile("example2_1_tb.vcd");
		$dumpvars(0, example2_1_tb);
		
		x1 = 1'b0; x2 = 1'b0; x3 = 1'b0; x4 = 1'b0;
		#20
		
		x1 = 1'b0; x2 = 1'b0; x3 = 1'b0; x4 = 1'b1;
		#20
		
		x1 = 1'b0; x2 = 1'b0; x3 = 1'b1; x4 = 1'b0;
		#20
		
		x1 = 1'b0; x2 = 1'b0; x3 = 1'b1; x4 = 1'b1;
		#20
		
		x1 = 1'b0; x2 = 1'b1; x3 = 1'b0; x4 = 1'b0;
		#20
		
		x1 = 1'b0; x2 = 1'b1; x3 = 1'b0; x4 = 1'b1;
		#20
		
		x1 = 1'b0; x2 = 1'b1; x3 = 1'b1; x4 = 1'b0;
		#20
		
		x1 = 1'b0; x2 = 1'b1; x3 = 1'b1; x4 = 1'b1;
		#20
		
		x1 = 1'b1; x2 = 1'b0; x3 = 1'b0; x4 = 1'b0;
		#20
		
		x1 = 1'b1; x2 = 1'b0; x3 = 1'b0; x4 = 1'b1;
		#20
		
		x1 = 1'b1; x2 = 1'b0; x3 = 1'b1; x4 = 1'b0;
		#20
		
		x1 = 1'b1; x2 = 1'b0; x3 = 1'b1; x4 = 1'b1;
		#20
		
		x1 = 1'b1; x2 = 1'b1; x3 = 1'b0; x4 = 1'b0;
		#20
		
		x1 = 1'b1; x2 = 1'b1; x3 = 1'b0; x4 = 1'b1;
		#20
		
		x1 = 1'b1; x2 = 1'b1; x3 = 1'b1; x4 = 1'b0;
		#20
		
		x1 = 1'b1; x2 = 1'b1; x3 = 1'b1; x4 = 1'b1;
		#20
		
		$display("Test complete");
	
end endmodule