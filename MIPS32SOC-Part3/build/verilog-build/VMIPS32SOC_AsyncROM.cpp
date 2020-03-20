// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMIPS32SOC.h for the primary calling header

#include "VMIPS32SOC_AsyncROM.h" // For This
#include "VMIPS32SOC__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMIPS32SOC_AsyncROM) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VMIPS32SOC_AsyncROM::__Vconfigure(VMIPS32SOC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMIPS32SOC_AsyncROM::~VMIPS32SOC_AsyncROM() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VMIPS32SOC_AsyncROM::_settle__TOP__MIPS32SOC__inst_mem__1(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_AsyncROM::_settle__TOP__MIPS32SOC__inst_mem__1\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC__inst_mem.read_data__out__out0 
	= vlSymsp->TOP__MIPS32SOC__inst_mem.memory[
	(0xffU & (((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__pcdecoder_i4__DOT__Invalid_pc_temp)
		    ? 0U : vlSymsp->TOP__MIPS32SOC.PC) 
		  >> 2U))];
}

void VMIPS32SOC_AsyncROM::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_AsyncROM::_ctor_var_reset\n"); );
    // Body
    __PVT__addr = VL_RAND_RESET_I(8);
    __PVT__en = VL_RAND_RESET_I(1);
    __PVT__read_data = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    read_data__out = VL_RAND_RESET_I(32);
    read_data__en = VL_RAND_RESET_I(32);
    read_data__out__out0 = VL_RAND_RESET_I(32);
}
