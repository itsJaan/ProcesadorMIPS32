// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMIPS32SOC.h for the primary calling header

#ifndef _VMIPS32SOC_RegisterFile_H_
#define _VMIPS32SOC_RegisterFile_H_

#include "verilated.h"
#include "VMIPS32SOC__Dpi.h"

class VMIPS32SOC__Syms;

//----------

VL_MODULE(VMIPS32SOC_RegisterFile) {
  public:
    
    // PORTS
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__read_addr1,4,0);
    VL_IN8(__PVT__read_addr2,4,0);
    VL_IN8(__PVT__write_addr,4,0);
    VL_IN8(__PVT__write_en,0,0);
    VL_IN(__PVT__write_data,31,0);
    VL_OUT(__PVT__read_data1,31,0);
    VL_OUT(__PVT__read_data2,31,0);
    
    // LOCAL SIGNALS
    VL_SIG(memory[32],31,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    VMIPS32SOC__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VMIPS32SOC_RegisterFile& operator= (const VMIPS32SOC_RegisterFile&);  ///< Copying not allowed
    VMIPS32SOC_RegisterFile(const VMIPS32SOC_RegisterFile&);  ///< Copying not allowed
  public:
    VMIPS32SOC_RegisterFile(const char* name="TOP");
    ~VMIPS32SOC_RegisterFile();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(VMIPS32SOC__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
  public:
    static void _initial__TOP__MIPS32SOC__reg_file__1(VMIPS32SOC__Syms* __restrict vlSymsp);
    static void _sequent__TOP__MIPS32SOC__reg_file__3(VMIPS32SOC__Syms* __restrict vlSymsp);
    static void _settle__TOP__MIPS32SOC__reg_file__2(VMIPS32SOC__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
