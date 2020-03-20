// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMIPS32SOC.h for the primary calling header

#include "VMIPS32SOC_RegisterFile.h" // For This
#include "VMIPS32SOC__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMIPS32SOC_RegisterFile) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VMIPS32SOC_RegisterFile::__Vconfigure(VMIPS32SOC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMIPS32SOC_RegisterFile::~VMIPS32SOC_RegisterFile() {
}

//--------------------
// Internal Methods

void VMIPS32SOC_RegisterFile::_initial__TOP__MIPS32SOC__reg_file__1(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_RegisterFile::_initial__TOP__MIPS32SOC__reg_file__1\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:411
    vlSymsp->TOP__MIPS32SOC__reg_file.memory[0U] = 0U;
}

VL_INLINE_OPT void VMIPS32SOC_RegisterFile::_settle__TOP__MIPS32SOC__reg_file__2(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_RegisterFile::_settle__TOP__MIPS32SOC__reg_file__2\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data1 
	= vlSymsp->TOP__MIPS32SOC__reg_file.memory[
	(0x1fU & (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
		  >> 0x15U))];
    vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data2 
	= vlSymsp->TOP__MIPS32SOC__reg_file.memory[
	(0x1fU & (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
		  >> 0x10U))];
}

VL_INLINE_OPT void VMIPS32SOC_RegisterFile::_sequent__TOP__MIPS32SOC__reg_file__3(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_RegisterFile::_sequent__TOP__MIPS32SOC__reg_file__3\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__memory__v0,4,0);
    VL_SIG8(__Vdlyvset__memory__v0,0,0);
    VL_SIG(__Vdlyvval__memory__v0,31,0);
    // Body
    __Vdlyvset__memory__v0 = 0U;
    // ALWAYS at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:405
    if ((((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5) 
	  >> 8U) & (0U != (0x1fU & ((0x40U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
				     ? ((0x40U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
					 ? (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
					    >> 0xbU)
					 : 0U) : (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
						  >> 0x10U)))))) {
	__Vdlyvval__memory__v0 = ((4U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
				   ? ((4U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
				       ? ((((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
					     ? vlSymsp->TOP__MIPS32SOC__data_mem.memory
					    [(0xffU 
					      & (vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__res_temp 
						 >> 2U))]
					     : 0U) 
					   & ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
					       ? 0xffffffffU
					       : 0U)) 
					  & ((2U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
					      ? 0xffffffffU
					      : 0U))
				       : 0U) : vlSymsp->TOP__MIPS32SOC.__PVT__ALU_i9__DOT__res_temp);
	__Vdlyvset__memory__v0 = 1U;
	__Vdlyvdim0__memory__v0 = (0x1fU & ((0x40U 
					     & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
					     ? ((0x40U 
						 & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i1__DOT__s5))
						 ? 
						(vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
						 >> 0xbU)
						 : 0U)
					     : (vlSymsp->TOP__MIPS32SOC__inst_mem.dout__out__out0 
						>> 0x10U)));
    }
    // ALWAYSPOST at /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v:408
    if (__Vdlyvset__memory__v0) {
	vlSymsp->TOP__MIPS32SOC__reg_file.memory[__Vdlyvdim0__memory__v0] 
	    = __Vdlyvval__memory__v0;
    }
}

void VMIPS32SOC_RegisterFile::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_RegisterFile::_ctor_var_reset\n"); );
    // Body
    __PVT__read_addr1 = VL_RAND_RESET_I(5);
    __PVT__read_addr2 = VL_RAND_RESET_I(5);
    __PVT__write_addr = VL_RAND_RESET_I(5);
    __PVT__write_data = VL_RAND_RESET_I(32);
    __PVT__write_en = VL_RAND_RESET_I(1);
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__read_data1 = VL_RAND_RESET_I(32);
    __PVT__read_data2 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
}
