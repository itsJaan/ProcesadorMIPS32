

module CompUnsigned #(
    parameter Bits = 1
)
(
    input [(Bits -1):0] a,
    input [(Bits -1):0] b,
    output \> ,
    output \= ,
    output \<
);
    assign \> = a > b;
    assign \= = a == b;
    assign \< = a < b;
endmodule

module PriorityEncoder3 (
    input in0,
    input in1,
    input in2,
    input in3,
    input in4,
    input in5,
    input in6,
    input in7,
    output reg [2:0] num,
    output any
);
    always @ (*) begin
        if (in7 == 1'b1)
            num = 3'h7;
        else if (in6 == 1'b1)
            num = 3'h6;
        else if (in5 == 1'b1)
            num = 3'h5;
        else if (in4 == 1'b1)
            num = 3'h4;
        else if (in3 == 1'b1)
            num = 3'h3;
        else if (in2 == 1'b1)
            num = 3'h2;
        else if (in1 == 1'b1)
            num = 3'h1;
        else 
            num = 3'h0;
    end

    assign any = in0 | in1 | in2 | in3 | in4 | in5 | in6 | in7;
endmodule


module Mux_8x1_NBits #(
    parameter Bits = 2
)
(
    input [2:0] sel,
    input [(Bits - 1):0] in_0,
    input [(Bits - 1):0] in_1,
    input [(Bits - 1):0] in_2,
    input [(Bits - 1):0] in_3,
    input [(Bits - 1):0] in_4,
    input [(Bits - 1):0] in_5,
    input [(Bits - 1):0] in_6,
    input [(Bits - 1):0] in_7,
    output reg [(Bits - 1):0] out
);
    always @ (*) begin
        case (sel)
            3'h0: out = in_0;
            3'h1: out = in_1;
            3'h2: out = in_2;
            3'h3: out = in_3;
            3'h4: out = in_4;
            3'h5: out = in_5;
            3'h6: out = in_6;
            3'h7: out = in_7;
            default:
                out = 'h0;
        endcase
    end
endmodule


module Mux_2x1_NBits #(
    parameter Bits = 2
)
(
    input [0:0] sel,
    input [(Bits - 1):0] in_0,
    input [(Bits - 1):0] in_1,
    output reg [(Bits - 1):0] out
);
    always @ (*) begin
        case (sel)
            1'h0: out = in_0;
            1'h1: out = in_1;
            default:
                out = 'h0;
        endcase
    end
endmodule


module ControlUnit (
  input [5:0] Opcode,
  input Reset, // RESET input
  output aluSrc,
  output RegDst,
  output [2:0] aluOp,
  output memToReg,
  output memRead,
  output memWrite,
  output RegWrite,
  output Branch,
  output Jump,
  output Bne
);
  wire s0;
  wire s1;
  wire s2;
  wire [2:0] s3;
  wire [11:0] s4;
  wire s5;
  wire s6;
  wire s7;
  wire s8;
  wire [11:0] s9;
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i0 (
    .a( Opcode ),
    .b( 6'b0 ),
    .\= ( s0 )
  );
  // SW
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i1 (
    .a( Opcode ),
    .b( 6'b101011 ),
    .\= ( s1 )
  );
  // LW
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i2 (
    .a( Opcode ),
    .b( 6'b100011 ),
    .\= ( s2 )
  );
  // beq
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i3 (
    .a( Opcode ),
    .b( 6'b100 ),
    .\= ( s5 )
  );
  // bne
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i4 (
    .a( Opcode ),
    .b( 6'b101 ),
    .\= ( s6 )
  );
  // jump
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i5 (
    .a( Opcode ),
    .b( 6'b10 ),
    .\= ( s7 )
  );
  // addi
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i6 (
    .a( Opcode ),
    .b( 6'b1000 ),
    .\= ( s8 )
  );
  PriorityEncoder3 PriorityEncoder3_i7 (
    .in0( s0 ),
    .in1( s1 ),
    .in2( s2 ),
    .in3( s5 ),
    .in4( s6 ),
    .in5( s7 ),
    .in6( s8 ),
    .in7( 1'b0 ),
    .num( s3 )
  );
  Mux_8x1_NBits #(
    .Bits(12)
  )
  Mux_8x1_NBits_i8 (
    .sel( s3 ),
    .in_0( 12'b101111000 ),
    .in_1( 12'b10010001 ),
    .in_2( 12'b110010110 ),
    .in_3( 12'b1000011000 ),
    .in_4( 12'b100000011000 ),
    .in_5( 12'b10000000000 ),
    .in_6( 12'b0 ),
    .in_7( 12'b0 ),
    .out( s4 )
  );
  Mux_2x1_NBits #(
    .Bits(12)
  )
  Mux_2x1_NBits_i9 (
    .sel( Reset ),
    .in_0( s4 ),
    .in_1( 12'b0 ),
    .out( s9 )
  );
  assign memWrite = s9[0];
  assign memRead = s9[1];
  assign memToReg = s9[2];
  assign aluOp = s9[5:3];
  assign RegDst = s9[6];
  assign aluSrc = s9[7];
  assign RegWrite = s9[8];
  assign Branch = s9[9];
  assign Jump = s9[10];
  assign Bne = s9[11];
endmodule

module DIG_Register_BUS #(
    parameter Bits = 1
)
(
    input C,
    input en,
    input [(Bits - 1):0]D,
    output [(Bits - 1):0]Q
);

    reg [(Bits - 1):0] state = 'h0;

    assign Q = state;

    always @ (posedge C) begin
        if (en)
            state <= D;
   end
endmodule
module DIG_Add
#(
    parameter Bits = 1
)
(
    input [(Bits-1):0] a,
    input [(Bits-1):0] b,
    input c_i,
    output [(Bits - 1):0] s,
    output c_o
);
   wire [Bits:0] temp;

   assign temp = a + b + c_i;
   assign s = temp [(Bits-1):0];
   assign c_o = temp[Bits];
endmodule



module pcdecoder (
  input [31:0] Pc,
  output [9:0] Physical,
  output Invalid_pc
);
  wire is_greater;
  wire is_less;
  wire Invalid_pc_temp;
  wire [9:0] s0;
  CompUnsigned #(
    .Bits(32)
  )
  CompUnsigned_i0 (
    .a( Pc ),
    .b( 32'b10000000000001111111111 ),
    .\> ( is_greater )
  );
  CompUnsigned #(
    .Bits(32)
  )
  CompUnsigned_i1 (
    .a( Pc ),
    .b( 32'b10000000000000000000000 ),
    .\< ( is_less )
  );
  assign s0 = Pc[9:0];
  assign Invalid_pc_temp = (is_greater | is_less);
  Mux_2x1_NBits #(
    .Bits(10)
  )
  Mux_2x1_NBits_i2 (
    .sel( Invalid_pc_temp ),
    .in_0( s0 ),
    .in_1( 10'b0 ),
    .out( Physical )
  );
  assign Invalid_pc = Invalid_pc_temp;
endmodule
module AsyncROM (
  input [7:0] addr,
  input en,
  output [31:0] read_data
);
  reg [31:0] memory[0:255] /*verilator public*/;

  assign read_data = en? memory[addr] : 32'hz;
  
  initial begin
`ifndef NO_INIT_MEM
    $readmemh("code.mif", memory, 0, 255);
`endif
  end
endmodule

module DIG_BitExtender #(
    parameter inputBits = 2,
    parameter outputBits = 4
)
(
    input [(inputBits-1):0] in,
    output [(outputBits - 1):0] out
);
    assign out = {{(outputBits - inputBits){in[inputBits - 1]}}, in};
endmodule




module ALUControl (
  input [2:0] aluOp,
  input [5:0] Func,
  output [2:0] aluFunc
);
  wire s0;
  wire s1;
  wire s2;
  wire s3;
  wire s4;
  wire [2:0] s5;
  wire s6;
  wire [2:0] s7;
  wire s8;
  // ADD
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i0 (
    .a( Func ),
    .b( 6'b100000 ),
    .\= ( s0 )
  );
  // AND
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i1 (
    .a( Func ),
    .b( 6'b100100 ),
    .\= ( s1 )
  );
  // OR
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i2 (
    .a( Func ),
    .b( 6'b100101 ),
    .\= ( s2 )
  );
  // SUB
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i3 (
    .a( Func ),
    .b( 6'b100010 ),
    .\= ( s3 )
  );
  // SLT
  CompUnsigned #(
    .Bits(6)
  )
  CompUnsigned_i4 (
    .a( Func ),
    .b( 6'b101010 ),
    .\= ( s4 )
  );
  CompUnsigned #(
    .Bits(3)
  )
  CompUnsigned_i5 (
    .a( aluOp ),
    .b( 3'b111 ),
    .\= ( s8 )
  );
  PriorityEncoder3 PriorityEncoder3_i6 (
    .in0( s1 ),
    .in1( s2 ),
    .in2( s0 ),
    .in3( s3 ),
    .in4( s4 ),
    .in5( 1'b0 ),
    .in6( 1'b0 ),
    .in7( 1'b0 ),
    .num( s5 ),
    .any( s6 )
  );
  Mux_2x1_NBits #(
    .Bits(3)
  )
  Mux_2x1_NBits_i7 (
    .sel( s6 ),
    .in_0( 3'b101 ),
    .in_1( s5 ),
    .out( s7 )
  );
  Mux_2x1_NBits #(
    .Bits(3)
  )
  Mux_2x1_NBits_i8 (
    .sel( s8 ),
    .in_0( aluOp ),
    .in_1( s7 ),
    .out( aluFunc )
  );
endmodule
module RegisterFile (
    input [4:0] read_addr1,
    input [4:0] read_addr2,
    input [4:0] write_addr,
    input [31:0] write_data,
    input write_en,
    input clk,
    output [31:0] read_data1,
    output [31:0] read_data2
);

    reg [31:0] memory[0:31] /*verilator public*/;
    
    assign read_data1 = memory[read_addr1];
    assign read_data2 = memory[read_addr2];
    
    always @(posedge clk)
    begin
        if (write_en)
            memory[write_addr] <= write_data;
    end

    initial begin
        memory[0] = 32'd0;
    end
endmodule


module DIG_Sub #(
    parameter Bits = 2
)
(
    input [(Bits-1):0] a,
    input [(Bits-1):0] b,
    input c_i,
    output [(Bits-1):0] s,
    output c_o
);
    wire [Bits:0] temp;

    assign temp = a - b - c_i;
    assign s = temp[(Bits-1):0];
    assign c_o = temp[Bits];
endmodule


module CompSigned #(
    parameter Bits = 1
)
(
    input [(Bits -1):0] a,
    input [(Bits -1):0] b,
    output \> ,
    output \= ,
    output \<
);
    assign \> = $signed(a) > $signed(b);
    assign \= = $signed(a) == $signed(b);
    assign \< = $signed(a) < $signed(b);
endmodule


module DIG_Mul_unsigned #(
    parameter Bits = 1
)
(
    
      input [(Bits-1):0] a,
      input [(Bits-1):0] b,
      output [(Bits*2-1):0] mul
    
);
    assign mul = a * b;
endmodule


module ALU (
  input [31:0] a,
  input [31:0] b,
  input [2:0] op,
  output [31:0] res,
  output isZero,
  output [31:0] low,
  output [31:0] high
);
  wire [31:0] s0;
  wire [31:0] s1;
  wire [31:0] s2;
  wire [31:0] s3;
  wire [31:0] s4;
  wire [31:0] s5;
  wire [31:0] res_temp;
  wire s6;
  wire [63:0] s7;
  DIG_Add #(
    .Bits(32)
  )
  DIG_Add_i0 (
    .a( a ),
    .b( b ),
    .c_i( 1'b0 ),
    .s( s0 )
  );
  DIG_Sub #(
    .Bits(32)
  )
  DIG_Sub_i1 (
    .a( a ),
    .b( b ),
    .c_i( 1'b0 ),
    .s( s1 )
  );
  assign s2 = (a & b);
  assign s3 = (a | b);
  CompSigned #(
    .Bits(32)
  )
  CompSigned_i2 (
    .a( a ),
    .b( b ),
    .\< ( s6 )
  );
  assign s5 = (a ^ b);
  DIG_Mul_unsigned #(
    .Bits(32)
  )
  DIG_Mul_unsigned_i3 (
    .a( a ),
    .b( b ),
    .mul( s7 )
  );
  assign s4[0] = s6;
  assign s4[31:1] = 31'b0;
  assign low = s7[31:0];
  assign high = s7[63:32];
  Mux_8x1_NBits #(
    .Bits(32)
  )
  Mux_8x1_NBits_i4 (
    .sel( op ),
    .in_0( s2 ),
    .in_1( s3 ),
    .in_2( s0 ),
    .in_3( s1 ),
    .in_4( s4 ),
    .in_5( s5 ),
    .in_6( 32'b0 ),
    .in_7( 32'b0 ),
    .out( res_temp )
  );
  CompUnsigned #(
    .Bits(32)
  )
  CompUnsigned_i5 (
    .a( res_temp ),
    .b( 32'b0 ),
    .\= ( isZero )
  );
  assign res = res_temp;
endmodule
module RAMDualPort (
  input [7:0] addr,
  input [31:0] write_data,
  input mem_write,
  input clk,
  input mem_read,
  output [31:0] read_data
);
  reg [31:0] memory[0:255] /*verilator public*/;

  assign read_data = mem_read? memory[addr] : 32'hz;

  always @ (posedge clk) begin
    if (mem_write)
      memory[addr] <= write_data;
  end

  initial begin
`ifndef NO_INIT_MEM
    $readmemh("data.mif", memory, 0, 255);
`endif
  end
endmodule


module Mux_2x1
(
    input [0:0] sel,
    input in_0,
    input in_1,
    output reg out
);
    always @ (*) begin
        case (sel)
            1'h0: out = in_0;
            1'h1: out = in_1;
            default:
                out = 'h0;
        endcase
    end
endmodule


module memdecoder (
  input Enable,
  input [31:0] VirtualAddres,
  output [10:0] Physical_Addres,
  output Invalid_Addres
);
  wire Invalid_Addres_temp;
  wire [3:0] s0;
  wire GlobalMemory;
  wire Stack;
  wire [31:0] s1;
  wire s2;
  wire s3;
  wire s4;
  wire [31:0] s5;
  wire [10:0] s6;
  wire [31:0] s7;
  wire [31:0] s8;
  wire [31:0] s9;
  wire [31:0] s10;
  wire [31:0] s11;
  wire [31:0] s12;
  assign s0 = VirtualAddres[31:28];
  CompUnsigned #(
    .Bits(4)
  )
  CompUnsigned_i0 (
    .a( s0 ),
    .b( 4'b1 ),
    .\= ( GlobalMemory )
  );
  CompUnsigned #(
    .Bits(4)
  )
  CompUnsigned_i1 (
    .a( s0 ),
    .b( 4'b111 ),
    .\= ( Stack )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i2 (
    .sel( Stack ),
    .in_0( 32'b10000000000000000000000000000 ),
    .in_1( 32'b1111111111111111110101111111100 ),
    .out( s1 )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i3 (
    .sel( Stack ),
    .in_0( 32'b10000000000000000001111111111 ),
    .in_1( 32'b1111111111111111110111111111011 ),
    .out( s5 )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i4 (
    .sel( Stack ),
    .in_0( 32'b10000000000000000000000000000 ),
    .in_1( 32'b1111111111111111110101111111100 ),
    .out( s7 )
  );
  CompUnsigned #(
    .Bits(32)
  )
  CompUnsigned_i5 (
    .a( VirtualAddres ),
    .b( s1 ),
    .\< ( s2 )
  );
  CompUnsigned #(
    .Bits(32)
  )
  CompUnsigned_i6 (
    .a( VirtualAddres ),
    .b( s5 ),
    .\> ( s3 )
  );
  DIG_Sub #(
    .Bits(32)
  )
  DIG_Sub_i7 (
    .a( VirtualAddres ),
    .b( s7 ),
    .c_i( 1'b0 ),
    .s( s8 )
  );
  assign s4 = (s2 | s3);
  DIG_Add #(
    .Bits(32)
  )
  DIG_Add_i8 (
    .a( s8 ),
    .b( 32'b10000000000 ),
    .c_i( 1'b0 ),
    .s( s9 )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i9 (
    .sel( GlobalMemory ),
    .in_0( 32'b0 ),
    .in_1( s8 ),
    .out( s11 )
  );
  Mux_2x1 Mux_2x1_i10 (
    .sel( Enable ),
    .in_0( 1'b0 ),
    .in_1( s4 ),
    .out( Invalid_Addres_temp )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i11 (
    .sel( Stack ),
    .in_0( 32'b0 ),
    .in_1( s9 ),
    .out( s10 )
  );
  assign s12 = (s11 | s10);
  assign s6 = s12[10:0];
  Mux_2x1_NBits #(
    .Bits(11)
  )
  Mux_2x1_NBits_i12 (
    .sel( Invalid_Addres_temp ),
    .in_0( s6 ),
    .in_1( 11'b0 ),
    .out( Physical_Addres )
  );
  assign Invalid_Addres = Invalid_Addres_temp;
endmodule

module MIPS32SOC(
  input rst,
  input clk,
  output invalid_opcode,
  output invalid_pc,
  output invalid_addr
);
  wire [31:0] s0;
  wire [31:0] s1;
  wire [7:0] s2;
  wire [31:0] s3;
  wire [31:0] \Pc+4 ;
  wire [31:0] s4;
  wire RegWrite;
  wire [4:0] s5;
  wire [4:0] s6;
  wire [4:0] s7;
  wire [31:0] s8;
  wire [31:0] s9;
  wire [5:0] Func;
  wire [4:0] s10;
  wire [5:0] Opcode;
  wire [31:0] s11;
  wire [2:0] aluFunc;
  wire [31:0] res;
  wire is_Zero;
  wire [31:0] low;
  wire [31:0] high;
  wire [15:0] s12;
  wire [31:0] s13;
  wire aluSrc;
  wire RegDst;
  wire [2:0] aluOp;
  wire memToReg;
  wire memRead;
  wire memWrite;
  wire Branch_Out;
  wire Jump;
  wire Bne;
  wire [10:0] s14;
  wire [31:0] s15;
  wire [31:0] shift2;
  wire [31:0] s16;
  wire bsh;
  wire [31:0] s17;
  wire [31:0] s18;
  wire [31:0] shift_Jump;
  wire [27:0] s19;
  wire [9:0] s20;
  wire s21;
  wire [10:0] A;
  wire [1:0] const2b0;
  wire [12:0] s22;
  wire [31:0] t1;
  wire [31:0] t;
  assign invalid_opcode = 1'b0;
  assign const2b0 = 2'b0;
  ControlUnit ControlUnit_i0 (
    .Opcode( Opcode ),
    .Reset( rst ),
    .aluSrc( aluSrc ),
    .RegDst( RegDst ),
    .aluOp( aluOp ),
    .memToReg( memToReg ),
    .memRead( memRead ),
    .memWrite( memWrite ),
    .RegWrite( RegWrite ),
    .Branch( Branch_Out ),
    .Jump( Jump ),
    .Bne( Bne )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i1 (
    .sel( rst ),
    .in_0( s18 ),
    .in_1( 32'b10000000000000000000000 ),
    .out( s0 )
  );
  assign s22[10:0] = A;
  assign s22[12:11] = const2b0;
  reg [31:0] PC /*verilator public*/;

  assign s1 = PC;

  always @ (posedge clk) begin
    if (1'b1)
      PC <= s0;
  end

  assign s21 = (memWrite | memRead);
  assign s14 = s22[12:2];
  DIG_Add #(
    .Bits(32)
  )
  DIG_Add_i3 (
    .a( s1 ),
    .b( 32'b100 ),
    .c_i( 1'b0 ),
    .s( \Pc+4  )
  );
  pcdecoder pcdecoder_i4 (
    .Pc( s1 ),
    .Physical( s20 ),
    .Invalid_pc( invalid_pc )
  );
  assign s2 = s20[9:2];
  // InstMem
  AsyncROM inst_mem (
    .addr( s2 ),
    .en( 1'b1 ),
    .read_data( s3 )
  );

  assign s19[1:0] = 2'b0;
  assign s19[27:2] = s3[25:0];
  assign Func = s3[5:0];
  assign s10 = s3[15:11];
  assign s7 = s3[20:16];
  assign s6 = s3[25:21];
  assign Opcode = s3[31:26];
  assign s12 = s3[15:0];
  DIG_BitExtender #(
    .inputBits(16),
    .outputBits(32)
  )
  DIG_BitExtender_i6 (
    .in( s12 ),
    .out( s13 )
  );
  Mux_2x1_NBits #(
    .Bits(5)
  )
  Mux_2x1_NBits_i7 (
    .sel( RegDst ),
    .in_0( s7 ),
    .in_1( s10 ),
    .out( s5 )
  );
  ALUControl ALUControl_i8 (
    .aluOp( aluOp ),
    .Func( Func ),
    .aluFunc( aluFunc )
  );
  assign shift_Jump[27:0] = s19;
  assign shift_Jump[31:28] = \Pc+4 [31:28];
  assign shift2[1:0] = 2'b0;
  assign shift2[31:2] = s13[29:0];
  DIG_Add #(
    .Bits(32)
  )
  DIG_Add_i9 (
    .a( \Pc+4  ),
    .b( shift2 ),
    .c_i( 1'b0 ),
    .s( s16 )
  );
  // Reg File
  RegisterFile reg_file (
    .clk( clk ),
    .read_addr1( s6 ),
    .read_addr2( s7 ),
    .write_addr( s5 ),
    .write_en( RegWrite ),
    .write_data( s4 ),
    .read_data1( s8 ),
    .read_data2( s9 )
  );

  ALU ALU_i11 (
    .a( s8 ),
    .b( s11 ),
    .op( aluFunc ),
    .res( res ),
    .isZero( is_Zero ),
    .low( low ),
    .high( high )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i12 (
    .sel( aluSrc ),
    .in_0( s9 ),
    .in_1( s13 ),
    .out( s11 )
  );
  // Data Mem
  RAMDualPort data_mem(
    .addr( s14 ),
    .mem_write( memWrite ),
    .write_data( s9 ),
    .clk( clk ),
    .mem_read( memRead ),
    .read_data( s15 )
  );

  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i14 (
    .sel( memToReg ),
    .in_0( res ),
    .in_1( s15 ),
    .out( s4 )
  );
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i15 (
    .sel( bsh ),
    .in_0( \Pc+4  ),
    .in_1( s16 ),
    .out( s17 )
  );
  assign bsh = ((Branch_Out & is_Zero) | (Bne & ~ is_Zero));
  Mux_2x1_NBits #(
    .Bits(32)
  )
  Mux_2x1_NBits_i16 (
    .sel( Jump ),
    .in_0( s17 ),
    .in_1( shift_Jump ),
    .out( s18 )
  );
  memdecoder memdecoder_i17 (
    .Enable( s21 ),
    .VirtualAddres( res ),
    .Physical_Addres( A ),
    .Invalid_Addres( invalid_addr )
  );
  reg [31:0] low_reg /*verilator public*/;

  assign t1 = low_reg;

  always @ (posedge clk) begin
    if (1'b1)
      low_reg <= low;
  end

  reg [31:0] high_reg /*verilator public*/;

  assign t = high_reg;

  always @ (posedge clk) begin
    if (1'b1)
      high_reg <= high;
  end

endmodule
