// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMIPS32SOC.h for the primary calling header

#include "VMIPS32SOC_MIPS32SOC.h" // For This
#include "VMIPS32SOC__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES

VL_ST_SIG16(VMIPS32SOC_MIPS32SOC::__Vtable1___PVT__ControlUnit_i0__DOT__s4[8],11,0);

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
    vlSymsp->TOP__MIPS32SOC.__PVT__s19 = (0xffffffcU 
					  & vlSymsp->TOP__MIPS32SOC.__PVT__s19);
    vlSymsp->TOP__MIPS32SOC.__PVT__shift2 = (0xfffffffcU 
					     & vlSymsp->TOP__MIPS32SOC.__PVT__shift2);
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s4 
	= (1U & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s4);
    vlSymsp->TOP__MIPS32SOC.__PVT__s22 = (0x7ffU & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__s22));
    vlSymsp->TOP__MIPS32SOC.__PVT__shift_Jump = ((0xfffffffU 
						  & vlSymsp->TOP__MIPS32SOC.__PVT__shift_Jump) 
						 | (0xf0000000U 
						    & ((IData)(
							       (VL_ULL(0x1f) 
								& ((VL_ULL(4) 
								    + (QData)((IData)(vlSymsp->TOP__MIPS32SOC.PC))) 
								   >> 0x1cU))) 
						       << 0x1cU)));
    vlSymsp->TOP__MIPS32SOC.__PVT__pcdecoder_i4__DOT__Invalid_pc_temp 
	= ((0x4003ffU < vlSymsp->TOP__MIPS32SOC.PC) 
	   | (0x400000U > vlSymsp->TOP__MIPS32SOC.PC));
}

void VMIPS32SOC_MIPS32SOC::_settle__TOP__MIPS32SOC__2(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_settle__TOP__MIPS32SOC__2\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC.__PVT__s19 = ((3U & vlSymsp->TOP__MIPS32SOC.__PVT__s19) 
					  | (0xffffffcU 
					     & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
						<< 2U)));
    vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i8__DOT__s6 
	= (((((0x24U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0)) 
	      | (0x25U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))) 
	     | (0x20U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))) 
	    | (0x22U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))) 
	   | (0x2aU == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0)));
    vlSymsp->TOP__MIPS32SOC.__PVT__s13 = ((0xffff0000U 
					   & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
								      >> 0xfU)))) 
					      << 0x10U)) 
					  | (0xffffU 
					     & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:68
    vlSymsp->TOP__MIPS32SOC.__Vtableidx1 = ((8U == 
					     (0x3fU 
					      & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
						 >> 0x1aU)))
					     ? 6U : 
					    ((2U == 
					      (0x3fU 
					       & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
						  >> 0x1aU)))
					      ? 5U : 
					     ((5U == 
					       (0x3fU 
						& (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
						   >> 0x1aU)))
					       ? 4U
					       : ((4U 
						   == 
						   (0x3fU 
						    & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
						       >> 0x1aU)))
						   ? 3U
						   : 
						  ((0x23U 
						    == 
						    (0x3fU 
						     & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
							>> 0x1aU)))
						    ? 2U
						    : 
						   ((0x2bU 
						     == 
						     (0x3fU 
						      & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
							 >> 0x1aU)))
						     ? 1U
						     : 0U))))));
    vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s4 
	= vlSymsp->TOP__MIPS32SOC.__Vtable1___PVT__ControlUnit_i0__DOT__s4
	[vlSymsp->TOP__MIPS32SOC.__Vtableidx1];
    vlSymsp->TOP__MIPS32SOC.__PVT__shift_Jump = ((0xf0000000U 
						  & vlSymsp->TOP__MIPS32SOC.__PVT__shift_Jump) 
						 | vlSymsp->TOP__MIPS32SOC.__PVT__s19);
    vlSymsp->TOP__MIPS32SOC.__PVT__shift2 = ((3U & vlSymsp->TOP__MIPS32SOC.__PVT__shift2) 
					     | (0xfffffffcU 
						& (vlSymsp->TOP__MIPS32SOC.__PVT__s13 
						   << 2U)));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9 
	= ((IData)(vlTOPp->rst) ? 0U : (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s4));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = (7U & 
					      ((7U 
						== 
						(7U 
						 & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
						    >> 3U)))
					        ? (
						   (7U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
							>> 3U)))
						    ? 
						   ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i8__DOT__s6)
						     ? 
						    ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i8__DOT__s6)
						      ? 
						     ((0x2aU 
						       == 
						       (0x3fU 
							& vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))
						       ? 4U
						       : 
						      ((0x22U 
							== 
							(0x3fU 
							 & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))
						        ? 3U
						        : 
						       ((0x20U 
							 == 
							 (0x3fU 
							  & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))
							 ? 2U
							 : 
							((0x25U 
							  == 
							  (0x3fU 
							   & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))
							  ? 1U
							  : 0U))))
						      : 0U)
						     : 5U)
						    : 0U)
					        : ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
						   >> 3U)));
}

void VMIPS32SOC_MIPS32SOC::_settle__TOP__MIPS32SOC__3(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_settle__TOP__MIPS32SOC__3\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__s11 = ((0x80U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9))
					   ? ((0x80U 
					       & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9))
					       ? vlSymsp->TOP__MIPS32SOC.__PVT__s13
					       : 0U)
					   : vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data2);
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s7 
	= ((QData)((IData)(vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1)) 
	   * (QData)((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__s11)));
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s4 
	= ((0xfffffffeU & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s4) 
	   | VL_LTS_III(32,32,32, vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1, vlSymsp->TOP__MIPS32SOC.__PVT__s11));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:68
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
	= ((4U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	    ? ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	        ? 0U : ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
			 ? (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
			    ^ vlSymsp->TOP__MIPS32SOC.__PVT__s11)
			 : vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s4))
	    : ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	        ? ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       - vlSymsp->TOP__MIPS32SOC.__PVT__s11)
		    : (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       + vlSymsp->TOP__MIPS32SOC.__PVT__s11))
	        : ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       | vlSymsp->TOP__MIPS32SOC.__PVT__s11)
		    : (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       & vlSymsp->TOP__MIPS32SOC.__PVT__s11))));
    vlSymsp->TOP__MIPS32SOC.__PVT__bsh = ((((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
					    >> 9U) 
					   & (0U == vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp)) 
					  | (((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
					      >> 0xbU) 
					     & (0U 
						!= vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp)));
    vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__DIG_Sub_i7__DOT__temp 
	= (VL_ULL(0x1ffffffff) & ((QData)((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp)) 
				  - (QData)((IData)(
						    ((7U 
						      == 
						      (0xfU 
						       & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
							  >> 0x1cU)))
						      ? 
						     ((7U 
						       == 
						       (0xfU 
							& (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
							   >> 0x1cU)))
						       ? 0x7fffebfcU
						       : 0U)
						      : 0x10000000U)))));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__s1 
	= ((7U == (0xfU & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
			   >> 0x1cU))) ? ((7U == (0xfU 
						  & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
						     >> 0x1cU)))
					   ? 0x7fffebfcU
					   : 0U) : 0x10000000U);
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__s5 
	= ((7U == (0xfU & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
			   >> 0x1cU))) ? ((7U == (0xfU 
						  & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
						     >> 0x1cU)))
					   ? 0x7fffeffbU
					   : 0U) : 0x100003ffU);
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__s17 = ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__bsh)
					   ? ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__bsh)
					       ? ((IData)(4U) 
						  + 
						  (vlSymsp->TOP__MIPS32SOC.PC 
						   + vlSymsp->TOP__MIPS32SOC.__PVT__shift2))
					       : 0U)
					   : ((IData)(4U) 
					      + vlSymsp->TOP__MIPS32SOC.PC));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:635
    vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__Invalid_Addres_temp 
	= (((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
	    | ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
	       >> 1U)) & ((vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
			   < vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__s1) 
			  | (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
			     > vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__s5)));
    vlSymsp->TOP__MIPS32SOC.__PVT__s22 = ((0x1800U 
					   & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__s22)) 
					  | (0x7ffU 
					     & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__Invalid_Addres_temp)
						 ? 0U
						 : 
						(((1U 
						   == 
						   (0xfU 
						    & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
						       >> 0x1cU)))
						   ? 
						  ((1U 
						    == 
						    (0xfU 
						     & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
							>> 0x1cU)))
						    ? (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__DIG_Sub_i7__DOT__temp)
						    : 0U)
						   : 0U) 
						 | ((7U 
						     == 
						     (0xfU 
						      & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
							 >> 0x1cU)))
						     ? 
						    ((7U 
						      == 
						      (0xfU 
						       & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
							  >> 0x1cU)))
						      ? 
						     ((IData)(0x400U) 
						      + (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__DIG_Sub_i7__DOT__temp))
						      : 0U)
						     : 0U)))));
}

VL_INLINE_OPT void VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__4(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__4\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:1021
    vlSymsp->TOP__MIPS32SOC.low_reg = (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s7);
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:1030
    vlSymsp->TOP__MIPS32SOC.high_reg = (IData)((vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s7 
						>> 0x20U));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:871
    vlSymsp->TOP__MIPS32SOC.PC = ((IData)(vlTOPp->rst)
				   ? ((IData)(vlTOPp->rst)
				       ? 0x400000U : 0U)
				   : ((0x400U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9))
				       ? ((0x400U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9))
					   ? vlSymsp->TOP__MIPS32SOC.__PVT__shift_Jump
					   : 0U) : vlSymsp->TOP__MIPS32SOC.__PVT__s17));
    vlSymsp->TOP__MIPS32SOC.__PVT__shift_Jump = ((0xfffffffU 
						  & vlSymsp->TOP__MIPS32SOC.__PVT__shift_Jump) 
						 | (0xf0000000U 
						    & ((IData)(
							       (VL_ULL(0x1f) 
								& ((VL_ULL(4) 
								    + (QData)((IData)(vlSymsp->TOP__MIPS32SOC.PC))) 
								   >> 0x1cU))) 
						       << 0x1cU)));
    vlSymsp->TOP__MIPS32SOC.__PVT__pcdecoder_i4__DOT__Invalid_pc_temp 
	= ((0x4003ffU < vlSymsp->TOP__MIPS32SOC.PC) 
	   | (0x400000U > vlSymsp->TOP__MIPS32SOC.PC));
}

VL_INLINE_OPT void VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__5(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__5\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC.__PVT__s19 = ((3U & vlSymsp->TOP__MIPS32SOC.__PVT__s19) 
					  | (0xffffffcU 
					     & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
						<< 2U)));
    vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i8__DOT__s6 
	= (((((0x24U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0)) 
	      | (0x25U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))) 
	     | (0x20U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))) 
	    | (0x22U == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))) 
	   | (0x2aU == (0x3fU & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0)));
    vlSymsp->TOP__MIPS32SOC.__PVT__s13 = ((0xffff0000U 
					   & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
								      >> 0xfU)))) 
					      << 0x10U)) 
					  | (0xffffU 
					     & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:68
    vlSymsp->TOP__MIPS32SOC.__Vtableidx1 = ((8U == 
					     (0x3fU 
					      & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
						 >> 0x1aU)))
					     ? 6U : 
					    ((2U == 
					      (0x3fU 
					       & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
						  >> 0x1aU)))
					      ? 5U : 
					     ((5U == 
					       (0x3fU 
						& (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
						   >> 0x1aU)))
					       ? 4U
					       : ((4U 
						   == 
						   (0x3fU 
						    & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
						       >> 0x1aU)))
						   ? 3U
						   : 
						  ((0x23U 
						    == 
						    (0x3fU 
						     & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
							>> 0x1aU)))
						    ? 2U
						    : 
						   ((0x2bU 
						     == 
						     (0x3fU 
						      & (vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
							 >> 0x1aU)))
						     ? 1U
						     : 0U))))));
    vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s4 
	= vlSymsp->TOP__MIPS32SOC.__Vtable1___PVT__ControlUnit_i0__DOT__s4
	[vlSymsp->TOP__MIPS32SOC.__Vtableidx1];
    vlSymsp->TOP__MIPS32SOC.__PVT__shift_Jump = ((0xf0000000U 
						  & vlSymsp->TOP__MIPS32SOC.__PVT__shift_Jump) 
						 | vlSymsp->TOP__MIPS32SOC.__PVT__s19);
    vlSymsp->TOP__MIPS32SOC.__PVT__shift2 = ((3U & vlSymsp->TOP__MIPS32SOC.__PVT__shift2) 
					     | (0xfffffffcU 
						& (vlSymsp->TOP__MIPS32SOC.__PVT__s13 
						   << 2U)));
}

VL_INLINE_OPT void VMIPS32SOC_MIPS32SOC::_combo__TOP__MIPS32SOC__6(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_combo__TOP__MIPS32SOC__6\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9 
	= ((IData)(vlTOPp->rst) ? 0U : (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s4));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = (7U & 
					      ((7U 
						== 
						(7U 
						 & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
						    >> 3U)))
					        ? (
						   (7U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
							>> 3U)))
						    ? 
						   ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i8__DOT__s6)
						     ? 
						    ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALUControl_i8__DOT__s6)
						      ? 
						     ((0x2aU 
						       == 
						       (0x3fU 
							& vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))
						       ? 4U
						       : 
						      ((0x22U 
							== 
							(0x3fU 
							 & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))
						        ? 3U
						        : 
						       ((0x20U 
							 == 
							 (0x3fU 
							  & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))
							 ? 2U
							 : 
							((0x25U 
							  == 
							  (0x3fU 
							   & vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0))
							  ? 1U
							  : 0U))))
						      : 0U)
						     : 5U)
						    : 0U)
					        : ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
						   >> 3U)));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__s11 = ((0x80U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9))
					   ? ((0x80U 
					       & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9))
					       ? vlSymsp->TOP__MIPS32SOC.__PVT__s13
					       : 0U)
					   : vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data2);
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s7 
	= ((QData)((IData)(vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1)) 
	   * (QData)((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__s11)));
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s4 
	= ((0xfffffffeU & vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s4) 
	   | VL_LTS_III(32,32,32, vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1, vlSymsp->TOP__MIPS32SOC.__PVT__s11));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:68
    vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
	= ((4U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	    ? ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	        ? 0U : ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
			 ? (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
			    ^ vlSymsp->TOP__MIPS32SOC.__PVT__s11)
			 : vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__s4))
	    : ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
	        ? ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       - vlSymsp->TOP__MIPS32SOC.__PVT__s11)
		    : (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       + vlSymsp->TOP__MIPS32SOC.__PVT__s11))
	        : ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
		    ? (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       | vlSymsp->TOP__MIPS32SOC.__PVT__s11)
		    : (vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
		       & vlSymsp->TOP__MIPS32SOC.__PVT__s11))));
    vlSymsp->TOP__MIPS32SOC.__PVT__bsh = ((((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
					    >> 9U) 
					   & (0U == vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp)) 
					  | (((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
					      >> 0xbU) 
					     & (0U 
						!= vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp)));
    vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__DIG_Sub_i7__DOT__temp 
	= (VL_ULL(0x1ffffffff) & ((QData)((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp)) 
				  - (QData)((IData)(
						    ((7U 
						      == 
						      (0xfU 
						       & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
							  >> 0x1cU)))
						      ? 
						     ((7U 
						       == 
						       (0xfU 
							& (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
							   >> 0x1cU)))
						       ? 0x7fffebfcU
						       : 0U)
						      : 0x10000000U)))));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__s1 
	= ((7U == (0xfU & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
			   >> 0x1cU))) ? ((7U == (0xfU 
						  & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
						     >> 0x1cU)))
					   ? 0x7fffebfcU
					   : 0U) : 0x10000000U);
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__s5 
	= ((7U == (0xfU & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
			   >> 0x1cU))) ? ((7U == (0xfU 
						  & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
						     >> 0x1cU)))
					   ? 0x7fffeffbU
					   : 0U) : 0x100003ffU);
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:94
    vlSymsp->TOP__MIPS32SOC.__PVT__s17 = ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__bsh)
					   ? ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__bsh)
					       ? ((IData)(4U) 
						  + 
						  (vlSymsp->TOP__MIPS32SOC.PC 
						   + vlSymsp->TOP__MIPS32SOC.__PVT__shift2))
					       : 0U)
					   : ((IData)(4U) 
					      + vlSymsp->TOP__MIPS32SOC.PC));
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:635
    vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__Invalid_Addres_temp 
	= (((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
	    | ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9) 
	       >> 1U)) & ((vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
			   < vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__s1) 
			  | (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
			     > vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__s5)));
    vlSymsp->TOP__MIPS32SOC.__PVT__s22 = ((0x1800U 
					   & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__s22)) 
					  | (0x7ffU 
					     & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__Invalid_Addres_temp)
						 ? 0U
						 : 
						(((1U 
						   == 
						   (0xfU 
						    & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
						       >> 0x1cU)))
						   ? 
						  ((1U 
						    == 
						    (0xfU 
						     & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
							>> 0x1cU)))
						    ? (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__DIG_Sub_i7__DOT__temp)
						    : 0U)
						   : 0U) 
						 | ((7U 
						     == 
						     (0xfU 
						      & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
							 >> 0x1cU)))
						     ? 
						    ((7U 
						      == 
						      (0xfU 
						       & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i11__DOT__res_temp 
							  >> 0x1cU)))
						      ? 
						     ((IData)(0x400U) 
						      + (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__memdecoder_i17__DOT__DIG_Sub_i7__DOT__temp))
						      : 0U)
						     : 0U)))));
}

void VMIPS32SOC_MIPS32SOC::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_ctor_var_reset\n"); );
    // Body
    rst = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    __PVT__invalid_opcode = VL_RAND_RESET_I(1);
    invalid_pc = VL_RAND_RESET_I(1);
    invalid_addr = VL_RAND_RESET_I(1);
    __PVT__s11 = VL_RAND_RESET_I(32);
    __PVT__aluFunc = VL_RAND_RESET_I(3);
    __PVT__s13 = VL_RAND_RESET_I(32);
    __PVT__shift2 = VL_RAND_RESET_I(32);
    __PVT__bsh = VL_RAND_RESET_I(1);
    __PVT__s17 = VL_RAND_RESET_I(32);
    __PVT__shift_Jump = VL_RAND_RESET_I(32);
    __PVT__s19 = VL_RAND_RESET_I(28);
    __PVT__s22 = VL_RAND_RESET_I(13);
    PC = VL_RAND_RESET_I(32);
    low_reg = VL_RAND_RESET_I(32);
    high_reg = VL_RAND_RESET_I(32);
    __PVT__ControlUnit_i0__DOT__s4 = VL_RAND_RESET_I(12);
    __PVT__ControlUnit_i0__DOT__s9 = VL_RAND_RESET_I(12);
    __PVT__pcdecoder_i4__DOT__Invalid_pc_temp = VL_RAND_RESET_I(1);
    __PVT__ALUControl_i8__DOT__s6 = VL_RAND_RESET_I(1);
    __PVT__ALU_i11__DOT__s4 = VL_RAND_RESET_I(32);
    __PVT__ALU_i11__DOT__res_temp = VL_RAND_RESET_I(32);
    __PVT__ALU_i11__DOT__s7 = VL_RAND_RESET_Q(64);
    __PVT__memdecoder_i17__DOT__Invalid_Addres_temp = VL_RAND_RESET_I(1);
    __PVT__memdecoder_i17__DOT__s1 = VL_RAND_RESET_I(32);
    __PVT__memdecoder_i17__DOT__s5 = VL_RAND_RESET_I(32);
    __PVT__memdecoder_i17__DOT__DIG_Sub_i7__DOT__temp = VL_RAND_RESET_Q(33);
    __Vtableidx1 = VL_RAND_RESET_I(3);
    __Vtable1___PVT__ControlUnit_i0__DOT__s4[0] = 0x178U;
    __Vtable1___PVT__ControlUnit_i0__DOT__s4[1] = 0x91U;
    __Vtable1___PVT__ControlUnit_i0__DOT__s4[2] = 0x196U;
    __Vtable1___PVT__ControlUnit_i0__DOT__s4[3] = 0x218U;
    __Vtable1___PVT__ControlUnit_i0__DOT__s4[4] = 0x818U;
    __Vtable1___PVT__ControlUnit_i0__DOT__s4[5] = 0x400U;
    __Vtable1___PVT__ControlUnit_i0__DOT__s4[6] = 0U;
    __Vtable1___PVT__ControlUnit_i0__DOT__s4[7] = 0U;
}
