// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMIPS32SOC.h for the primary calling header

#include "VMIPS32SOC_MIPS32SOC.h" // For This
#include "VMIPS32SOC__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMIPS32SOC_MIPS32SOC) {
    VL_CELL (inst_mem, VMIPS32SOC_AsyncROM);
    VL_CELL (reg_file, VMIPS32SOC_RegisterFile);
    VL_CELL (data_mem, VMIPS32SOC_RAMDualPort);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VMIPS32SOC_MIPS32SOC::__Vconfigure(VMIPS32SOC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMIPS32SOC_MIPS32SOC::~VMIPS32SOC_MIPS32SOC() {
}

//--------------------
// Internal Methods

void VMIPS32SOC_MIPS32SOC::_settle__TOP__MIPS32SOC__1(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_settle__TOP__MIPS32SOC__1\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s4 
	= (1U & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s4);
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s6 
	= (1U & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s6);
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s5 
	= (1U & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s5);
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:15
    vlSymsp->TOP__MIPS32SOC.__PVT__s0 = ((IData)(vlTOPp->rst)
					  ? 0U : ((IData)(4U) 
						  + vlSymsp->TOP__MIPS32SOC.PC));
}

void VMIPS32SOC_MIPS32SOC::_settle__TOP__MIPS32SOC__2(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_settle__TOP__MIPS32SOC__2\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i7__DOT__s8 
	= (((((((0x24U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0)) 
		| (0x25U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))) 
	       | (0x20U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))) 
	      | (0x22U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))) 
	     | (0x2aU == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))) 
	    | (5U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))) 
	   | (4U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0)));
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:49
    vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s3 
	= ((0x23U == (0x3fU & (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
			       >> 0x1aU))) ? 2U : (
						   (0x2bU 
						    == 
						    (0x3fU 
						     & (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
							>> 0x1aU)))
						    ? 1U
						    : 0U));
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:15
    vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5 
	= ((IData)(vlTOPp->rst) ? 0U : ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s3))
					 ? ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s3))
					     ? 0U : 0x196U)
					 : ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s3))
					     ? 0x91U
					     : 0x178U)));
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:15
    vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = (7U & 
					      ((7U 
						== 
						(7U 
						 & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5) 
						    >> 3U)))
					        ? (
						   (7U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5) 
							>> 3U)))
						    ? 
						   ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i7__DOT__s8)
						     ? 
						    ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i7__DOT__s8)
						      ? 
						     ((4U 
						       == 
						       (0x3fU 
							& vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
						       ? 6U
						       : 
						      ((5U 
							== 
							(0x3fU 
							 & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
						        ? 5U
						        : 
						       ((0x2aU 
							 == 
							 (0x3fU 
							  & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
							 ? 4U
							 : 
							((0x22U 
							  == 
							  (0x3fU 
							   & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
							  ? 3U
							  : 
							 ((0x20U 
							   == 
							   (0x3fU 
							    & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
							   ? 2U
							   : 
							  ((0x25U 
							    == 
							    (0x3fU 
							     & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
							    ? 1U
							    : 0U))))))
						      : 0U)
						     : 5U)
						    : 0U)
					        : ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5) 
						   >> 3U)));
}

void VMIPS32SOC_MIPS32SOC::_settle__TOP__MIPS32SOC__3(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_settle__TOP__MIPS32SOC__3\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:15
    vlSymsp->TOP__MIPS32SOC.__PVT__s13 = ((0x80U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
					   ? ((0x80U 
					       & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
					       ? ((0xffff0000U 
						   & (VL_NEGATE_I((IData)(
									  (1U 
									   & (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
									      >> 0xfU)))) 
						      << 0x10U)) 
						  | (0xffffU 
						     & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
					       : 0U)
					   : vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data2);
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s4 
	= ((0xfffffffeU & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s4) 
	   | VL_LTS_III(32,32,32, vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1, vlSymsp->TOP__MIPS32SOC.__PVT__s13));
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s6 
	= ((0xfffffffeU & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s6) 
	   | (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
	      == vlSymsp->TOP__MIPS32SOC.__PVT__s13));
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s5 
	= ((0xfffffffeU & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s5) 
	   | ((~ vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1) 
	      == vlSymsp->TOP__MIPS32SOC.__PVT__s13));
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:466
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__res_temp 
	= ((4U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	    ? ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	        ? ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? 0U : vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s6)
	        : ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s5
		    : vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s4))
	    : ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	        ? ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       - vlSymsp->TOP__MIPS32SOC.__PVT__s13)
		    : (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       + vlSymsp->TOP__MIPS32SOC.__PVT__s13))
	        : ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       | vlSymsp->TOP__MIPS32SOC.__PVT__s13)
		    : (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       & vlSymsp->TOP__MIPS32SOC.__PVT__s13))));
}

VL_INLINE_OPT void VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__4(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__4\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:665
    vlSymsp->TOP__MIPS32SOC.PC = vlSymsp->TOP__MIPS32SOC.__PVT__s0;
}

VL_INLINE_OPT void VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__5(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__5\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i7__DOT__s8 
	= (((((((0x24U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0)) 
		| (0x25U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))) 
	       | (0x20U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))) 
	      | (0x22U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))) 
	     | (0x2aU == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))) 
	    | (5U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))) 
	   | (4U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0)));
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:49
    vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s3 
	= ((0x23U == (0x3fU & (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
			       >> 0x1aU))) ? 2U : (
						   (0x2bU 
						    == 
						    (0x3fU 
						     & (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
							>> 0x1aU)))
						    ? 1U
						    : 0U));
}

VL_INLINE_OPT void VMIPS32SOC_MIPS32SOC::_combo__TOP__MIPS32SOC__6(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_combo__TOP__MIPS32SOC__6\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:15
    vlSymsp->TOP__MIPS32SOC.__PVT__s0 = ((IData)(vlTOPp->rst)
					  ? 0U : ((IData)(4U) 
						  + vlSymsp->TOP__MIPS32SOC.PC));
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:15
    vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5 
	= ((IData)(vlTOPp->rst) ? 0U : ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s3))
					 ? ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s3))
					     ? 0U : 0x196U)
					 : ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s3))
					     ? 0x91U
					     : 0x178U)));
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:15
    vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = (7U & 
					      ((7U 
						== 
						(7U 
						 & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5) 
						    >> 3U)))
					        ? (
						   (7U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5) 
							>> 3U)))
						    ? 
						   ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i7__DOT__s8)
						     ? 
						    ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i7__DOT__s8)
						      ? 
						     ((4U 
						       == 
						       (0x3fU 
							& vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
						       ? 6U
						       : 
						      ((5U 
							== 
							(0x3fU 
							 & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
						        ? 5U
						        : 
						       ((0x2aU 
							 == 
							 (0x3fU 
							  & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
							 ? 4U
							 : 
							((0x22U 
							  == 
							  (0x3fU 
							   & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
							  ? 3U
							  : 
							 ((0x20U 
							   == 
							   (0x3fU 
							    & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
							   ? 2U
							   : 
							  ((0x25U 
							    == 
							    (0x3fU 
							     & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
							    ? 1U
							    : 0U))))))
						      : 0U)
						     : 5U)
						    : 0U)
					        : ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5) 
						   >> 3U)));
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:15
    vlSymsp->TOP__MIPS32SOC.__PVT__s13 = ((0x80U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
					   ? ((0x80U 
					       & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
					       ? ((0xffff0000U 
						   & (VL_NEGATE_I((IData)(
									  (1U 
									   & (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
									      >> 0xfU)))) 
						      << 0x10U)) 
						  | (0xffffU 
						     & vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0))
					       : 0U)
					   : vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data2);
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s4 
	= ((0xfffffffeU & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s4) 
	   | VL_LTS_III(32,32,32, vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1, vlSymsp->TOP__MIPS32SOC.__PVT__s13));
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s6 
	= ((0xfffffffeU & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s6) 
	   | (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
	      == vlSymsp->TOP__MIPS32SOC.__PVT__s13));
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s5 
	= ((0xfffffffeU & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s5) 
	   | ((~ vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1) 
	      == vlSymsp->TOP__MIPS32SOC.__PVT__s13));
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:466
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__res_temp 
	= ((4U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	    ? ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	        ? ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? 0U : vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s6)
	        : ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s5
		    : vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__s4))
	    : ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	        ? ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       - vlSymsp->TOP__MIPS32SOC.__PVT__s13)
		    : (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       + vlSymsp->TOP__MIPS32SOC.__PVT__s13))
	        : ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       | vlSymsp->TOP__MIPS32SOC.__PVT__s13)
		    : (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       & vlSymsp->TOP__MIPS32SOC.__PVT__s13))));
}

void VMIPS32SOC_MIPS32SOC::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    __PVT__invalid_opcode = VL_RAND_RESET_I(1);
    __PVT__s0 = VL_RAND_RESET_I(32);
    __PVT__s13 = VL_RAND_RESET_I(32);
    __PVT__aluFunc = VL_RAND_RESET_I(3);
    PC = VL_RAND_RESET_I(32);
    __PVT__ControlUnit_i1__DOT__s3 = VL_RAND_RESET_I(2);
    __PVT__ControlUnit_i1__DOT__s5 = VL_RAND_RESET_I(9);
    __PVT__ALUControl_i7__DOT__s8 = VL_RAND_RESET_I(1);
    __PVT__ALU_i9__DOT__s4 = VL_RAND_RESET_I(32);
    __PVT__ALU_i9__DOT__s5 = VL_RAND_RESET_I(32);
    __PVT__ALU_i9__DOT__s6 = VL_RAND_RESET_I(32);
    __PVT__ALU_i9__DOT__res_temp = VL_RAND_RESET_I(32);
}
