// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VMIPS32SOC__Syms.h"
#include "VMIPS32SOC.h"
#include "VMIPS32SOC_MIPS32SOC.h"
#include "VMIPS32SOC_AsyncROM.h"
#include "VMIPS32SOC_RegisterFile.h"
#include "VMIPS32SOC_RAMDualPort.h"

// FUNCTIONS
VMIPS32SOC__Syms::VMIPS32SOC__Syms(VMIPS32SOC* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_didInit(false)
	// Setup submodule names
	, TOP__MIPS32SOC                 (Verilated::catName(topp->name(),"MIPS32SOC"))
	, TOP__MIPS32SOC__data_mem       (Verilated::catName(topp->name(),"MIPS32SOC.data_mem"))
	, TOP__MIPS32SOC__inst_mem       (Verilated::catName(topp->name(),"MIPS32SOC.inst_mem"))
	, TOP__MIPS32SOC__reg_file       (Verilated::catName(topp->name(),"MIPS32SOC.reg_file"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->MIPS32SOC                 = &TOP__MIPS32SOC;
    TOPp->MIPS32SOC->data_mem       = &TOP__MIPS32SOC__data_mem;
    TOPp->MIPS32SOC->inst_mem       = &TOP__MIPS32SOC__inst_mem;
    TOPp->MIPS32SOC->reg_file       = &TOP__MIPS32SOC__reg_file;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__MIPS32SOC.__Vconfigure(this, true);
    TOP__MIPS32SOC__data_mem.__Vconfigure(this, true);
    TOP__MIPS32SOC__inst_mem.__Vconfigure(this, true);
    TOP__MIPS32SOC__reg_file.__Vconfigure(this, true);
    // Setup scope names
    __Vscope_MIPS32SOC.configure(this,name(),"MIPS32SOC");
    __Vscope_MIPS32SOC__data_mem.configure(this,name(),"MIPS32SOC.data_mem");
    __Vscope_MIPS32SOC__inst_mem.configure(this,name(),"MIPS32SOC.inst_mem");
    __Vscope_MIPS32SOC__reg_file.configure(this,name(),"MIPS32SOC.reg_file");
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
	__Vscope_MIPS32SOC.varInsert(__Vfinal,"PC", &(TOP__MIPS32SOC.PC), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
	__Vscope_MIPS32SOC.varInsert(__Vfinal,"high_reg", &(TOP__MIPS32SOC.high_reg), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
	__Vscope_MIPS32SOC.varInsert(__Vfinal,"low_reg", &(TOP__MIPS32SOC.low_reg), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
	__Vscope_MIPS32SOC__data_mem.varInsert(__Vfinal,"memory", &(TOP__MIPS32SOC__data_mem.memory), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,255,0);
	__Vscope_MIPS32SOC__inst_mem.varInsert(__Vfinal,"memory", &(TOP__MIPS32SOC__inst_mem.memory), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,255,0);
	__Vscope_MIPS32SOC__reg_file.varInsert(__Vfinal,"memory", &(TOP__MIPS32SOC__reg_file.memory), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,31,0);
    }
}
