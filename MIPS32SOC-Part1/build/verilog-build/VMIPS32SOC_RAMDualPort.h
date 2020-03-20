// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMIPS32SOC.h for the primary calling header

#ifndef _VMIPS32SOC_RAMDualPort_H_
#define _VMIPS32SOC_RAMDualPort_H_

#include "verilated.h"
#include "VMIPS32SOC__Dpi.h"

class VMIPS32SOC__Syms;

//----------

VL_MODULE(VMIPS32SOC_RAMDualPort) {
  public:
    
    // PORTS
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__addr,7,0);
    VL_IN8(__PVT__mem_write,0,0);
    VL_IN8(__PVT__mem_read,0,0);
    VL_IN(__PVT__write_data,31,0);
    VL_IN(__PVT__read_data,31,0);
    VL_OUT(read_data__out,31,0);
    VL_OUT(read_data__en,31,0);
    
    // LOCAL SIGNALS
    VL_SIG(memory[256],31,0);
    
    // LOCAL VARIABLES
    VL_SIG8(__Vdlyvdim0__memory__v0,7,0);
    VL_SIG8(__Vdlyvset__memory__v0,0,0);
    VL_SIG(__Vdlyvval__memory__v0,31,0);
    
    // INTERNAL VARIABLES
  private:
    VMIPS32SOC__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VMIPS32SOC_RAMDualPort& operator= (const VMIPS32SOC_RAMDualPort&);  ///< Copying not allowed
    VMIPS32SOC_RAMDualPort(const VMIPS32SOC_RAMDualPort&);  ///< Copying not allowed
  public:
    VMIPS32SOC_RAMDualPort(const char* name="TOP");
    ~VMIPS32SOC_RAMDualPort();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(VMIPS32SOC__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
  public:
    static void _sequent__TOP__MIPS32SOC__data_mem__1(VMIPS32SOC__Syms* __restrict vlSymsp);
    static void _sequent__TOP__MIPS32SOC__data_mem__2(VMIPS32SOC__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
