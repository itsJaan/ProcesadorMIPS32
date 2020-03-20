// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMIPS32SOC.h for the primary calling header

#include "VMIPS32SOC_RAMDualPort.h" // For This
#include "VMIPS32SOC__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMIPS32SOC_RAMDualPort) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VMIPS32SOC_RAMDualPort::__Vconfigure(VMIPS32SOC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMIPS32SOC_RAMDualPort::~VMIPS32SOC_RAMDualPort() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VMIPS32SOC_RAMDualPort::_sequent__TOP__MIPS32SOC__data_mem__1(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_RAMDualPort::_sequent__TOP__MIPS32SOC__data_mem__1\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC__data_mem.__Vdlyvset__memory__v0 = 0U;
    // ALWAYS at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:615
    if ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__ControlUnit_i0__DOT__s9))) {
	vlSymsp->TOP__MIPS32SOC__data_mem.__Vdlyvval__memory__v0 
	    = vlSymsp->TOP__MIPS32SOC__reg_file.__PVT__read_data2;
	vlSymsp->TOP__MIPS32SOC__data_mem.__Vdlyvset__memory__v0 = 1U;
	vlSymsp->TOP__MIPS32SOC__data_mem.__Vdlyvdim0__memory__v0 
	    = (0xffU & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__s22) 
			>> 2U));
    }
}

VL_INLINE_OPT void VMIPS32SOC_RAMDualPort::_sequent__TOP__MIPS32SOC__data_mem__2(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_RAMDualPort::_sequent__TOP__MIPS32SOC__data_mem__2\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYSPOST at /home/itsjaan/Escritorio/OrganizaciondeComputadoras/Procesador_Proyecto/MIPS32SOC-Part3/build/MIPS32SOC.v:617
    if (vlSymsp->TOP__MIPS32SOC__data_mem.__Vdlyvset__memory__v0) {
	vlSymsp->TOP__MIPS32SOC__data_mem.memory[vlSymsp->TOP__MIPS32SOC__data_mem.__Vdlyvdim0__memory__v0] 
	    = vlSymsp->TOP__MIPS32SOC__data_mem.__Vdlyvval__memory__v0;
    }
}

void VMIPS32SOC_RAMDualPort::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_RAMDualPort::_ctor_var_reset\n"); );
    // Body
    __PVT__addr = VL_RAND_RESET_I(8);
    __PVT__write_data = VL_RAND_RESET_I(32);
    __PVT__mem_write = VL_RAND_RESET_I(1);
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__mem_read = VL_RAND_RESET_I(1);
    __PVT__read_data = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    read_data__out = VL_RAND_RESET_I(32);
    read_data__en = VL_RAND_RESET_I(32);
    __Vdlyvdim0__memory__v0 = VL_RAND_RESET_I(8);
    __Vdlyvval__memory__v0 = VL_RAND_RESET_I(32);
    __Vdlyvset__memory__v0 = VL_RAND_RESET_I(1);
}
