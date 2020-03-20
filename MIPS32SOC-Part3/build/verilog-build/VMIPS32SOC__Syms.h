// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _VMIPS32SOC__Syms_H_
#define _VMIPS32SOC__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VMIPS32SOC.h"
#include "VMIPS32SOC_MIPS32SOC.h"
#include "VMIPS32SOC_AsyncROM.h"
#include "VMIPS32SOC_RegisterFile.h"
#include "VMIPS32SOC_RAMDualPort.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class VMIPS32SOC__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VMIPS32SOC*                    TOPp;
    VMIPS32SOC_MIPS32SOC           TOP__MIPS32SOC;
    VMIPS32SOC_RAMDualPort         TOP__MIPS32SOC__data_mem;
    VMIPS32SOC_AsyncROM            TOP__MIPS32SOC__inst_mem;
    VMIPS32SOC_RegisterFile        TOP__MIPS32SOC__reg_file;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_MIPS32SOC;
    VerilatedScope __Vscope_MIPS32SOC__data_mem;
    VerilatedScope __Vscope_MIPS32SOC__inst_mem;
    VerilatedScope __Vscope_MIPS32SOC__reg_file;
    
    // CREATORS
    VMIPS32SOC__Syms(VMIPS32SOC* topp, const char* namep);
    ~VMIPS32SOC__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
