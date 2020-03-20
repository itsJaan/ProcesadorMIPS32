#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <chrono>
#include <random>
#include "doctest.h"
#include "VMIPS32SOC_AsyncROM.h"
#include "VMIPS32SOC_RAMDualPort.h"
#include "VMIPS32SOC_RegisterFile.h"
#include "VMIPS32SOC_MIPS32SOC.h"
#include "VMIPS32SOC.h"

#define GLOBAL_BASEADDR 0x10000000
#define STACK_BASEADDR  0x7fffebfc
#define CODE_BASEADDR   0x00400000

#define DECLARE_MIPS32_REGS(m) \
    uint32_t& zero = m.MIPS32SOC->reg_file->memory[0]; \
    uint32_t& at = m.MIPS32SOC->reg_file->memory[1]; \
    uint32_t& v0 = m.MIPS32SOC->reg_file->memory[2]; \
    uint32_t& v1 = m.MIPS32SOC->reg_file->memory[3]; \
    uint32_t& a0 = m.MIPS32SOC->reg_file->memory[4]; \
    uint32_t& a1 = m.MIPS32SOC->reg_file->memory[5]; \
    uint32_t& a2 = m.MIPS32SOC->reg_file->memory[6]; \
    uint32_t& a3 = m.MIPS32SOC->reg_file->memory[7]; \
    uint32_t& t0 = m.MIPS32SOC->reg_file->memory[8]; \
    uint32_t& t1 = m.MIPS32SOC->reg_file->memory[9]; \
    uint32_t& t2 = m.MIPS32SOC->reg_file->memory[10]; \
    uint32_t& t3 = m.MIPS32SOC->reg_file->memory[11]; \
    uint32_t& t4 = m.MIPS32SOC->reg_file->memory[12]; \
    uint32_t& t5 = m.MIPS32SOC->reg_file->memory[13]; \
    uint32_t& t6 = m.MIPS32SOC->reg_file->memory[14]; \
    uint32_t& t7 = m.MIPS32SOC->reg_file->memory[15]; \
    uint32_t& s0 = m.MIPS32SOC->reg_file->memory[16]; \
    uint32_t& s1 = m.MIPS32SOC->reg_file->memory[17]; \
    uint32_t& s2 = m.MIPS32SOC->reg_file->memory[18]; \
    uint32_t& s3 = m.MIPS32SOC->reg_file->memory[19]; \
    uint32_t& s4 = m.MIPS32SOC->reg_file->memory[20]; \
    uint32_t& s5 = m.MIPS32SOC->reg_file->memory[21]; \
    uint32_t& s6 = m.MIPS32SOC->reg_file->memory[22]; \
    uint32_t& s7 = m.MIPS32SOC->reg_file->memory[23]; \
    uint32_t& t8 = m.MIPS32SOC->reg_file->memory[24]; \
    uint32_t& t9 = m.MIPS32SOC->reg_file->memory[25]; \
    uint32_t& k0 = m.MIPS32SOC->reg_file->memory[26]; \
    uint32_t& k1 = m.MIPS32SOC->reg_file->memory[27]; \
    uint32_t& gp = m.MIPS32SOC->reg_file->memory[28]; \
    uint32_t& sp = m.MIPS32SOC->reg_file->memory[29]; \
    uint32_t& fp = m.MIPS32SOC->reg_file->memory[30]; \
    uint32_t& ra = m.MIPS32SOC->reg_file->memory[31]; \
    uint32_t& pc = m.MIPS32SOC->PC

#define CHECK_ERROR_SIGNALS(m) \
        do { \
            REQUIRE((m).invalid_opcode == 0); \
            REQUIRE((m).invalid_pc == 0); \
        } while (0)

#include "tests-code.cpp"

void reset(VMIPS32SOC& m) {
    m.rst = 1;
    m.clk = 0;
    m.eval();
    m.clk = 1;
    m.eval();
    m.clk = 0;
    m.rst = 0;
    m.eval();
}

void clockPulse(VMIPS32SOC& m) {
    m.clk = 1;
    m.eval();
    m.clk = 0;
    m.eval();
}

void setProgramCode(VMIPS32SOC& m, const uint32_t code[], int size) {
    for (int i = 0; i < size; i++) {
        m.MIPS32SOC->inst_mem->memory[i] = code[i];
    }
}

void randomizeRegisterFile(VMIPS32SOC& m) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine re(seed);
    std::uniform_int_distribution<> dist(1, 65535);

    for (int i = 1; i < 32; i++) {
        m.MIPS32SOC->reg_file->memory[i] = dist(re);
    }
}

TEST_CASE("'add' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);
    a0 = 10500;  
    a1 = 3500;
    a2 = -3500;
    a3 = 500;

    setProgramCode(m, test_add_code, TEST_ADD_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);
    
    CHECK(t0 == 14000);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);
    
    CHECK(t1 == -3000);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);
    
    CHECK(t2 == 0);
}

TEST_CASE("'sub' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);
    a0 = 10500;  
    a1 = 3500;
    a2 = -3500;
    a3 = 500;

    setProgramCode(m, test_sub_code, TEST_SUB_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);
    
    CHECK(t0 == 7000);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);
    
    CHECK(t1 == -4000);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);
    
    CHECK(t2 == 7000);
}

TEST_CASE("'and' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);

    a0 = 0xaabbccdd;  
    a1 = 0x00ff00ff;
    a2 = 0x11223344;
    a3 = 0xff0000ff;

    setProgramCode(m, test_and_code, TEST_AND_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t0 == 0x00bb00dd);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t1 == 0x11000044);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t2 == 0x00220044);
}

TEST_CASE("'or' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);

    a0 = 0xaa00cc00;  
    a1 = 0x00bb00dd;
    a2 = 0x00223300;
    a3 = 0x11000044;

    setProgramCode(m, test_or_code, TEST_OR_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t0 == 0xaabbccdd);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t1 == 0x11223344);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t2 == 0x00BB33DD);
}

TEST_CASE("'xor' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);

    a0 = 0xaabbccdd;  
    a1 = 0xffffffff;
    a2 = 0x11223344;

    setProgramCode(m, test_xor_code, TEST_XOR_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t0 == 0x55443322);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t1 == 0xEEDDCCBB);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t2 == 0x0);
}

TEST_CASE("'slt' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);

    a0 = 10500;  
    a1 = 3500;
    a2 = -3500;
    a3 = 500;

    setProgramCode(m, test_slt_code, TEST_SLT_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t0 == 0);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t1 == 1);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(t2 == 0);
}

TEST_CASE("'lw' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);

    m.MIPS32SOC->data_mem->memory[0] = 0xaabbccdd;
    m.MIPS32SOC->data_mem->memory[4] = 0x11223344;
    m.MIPS32SOC->data_mem->memory[16] = 0xdeadbeef;

    setProgramCode(m, test_lw_code, TEST_LW_CODE_SIZE);

    a0 = GLOBAL_BASEADDR - 4;
    reset(m);
    REQUIRE(m.invalid_addr == 1);

    a0 = GLOBAL_BASEADDR;
    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    CHECK_ERROR_SIGNALS(m);
    REQUIRE(m.invalid_addr == 0);
    clockPulse(m);
    
    CHECK(t0 == 0xaabbccdd);
    CHECK_ERROR_SIGNALS(m);
    REQUIRE(m.invalid_addr == 0);
    clockPulse(m);

    CHECK(t1 == 0x11223344);
    CHECK_ERROR_SIGNALS(m);
    REQUIRE(m.invalid_addr == 0);
    clockPulse(m);

    CHECK(t2 == 0xdeadbeef);
}

TEST_CASE("'sw' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    t0 = 0xaabbccdd;
    t1 = 0x11223344;
    t2 = 0xdeadbeef;

    setProgramCode(m, test_sw_code, TEST_SW_CODE_SIZE);

    a0 = GLOBAL_BASEADDR - 4;
    reset(m);
    REQUIRE(m.invalid_addr == 1);

    a0 = GLOBAL_BASEADDR;
    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    CHECK_ERROR_SIGNALS(m);
    REQUIRE(m.invalid_addr == 0);
    clockPulse(m);

    CHECK(m.MIPS32SOC->data_mem->memory[0] == 0xaabbccdd);
    CHECK_ERROR_SIGNALS(m);
    REQUIRE(m.invalid_addr == 0);
    clockPulse(m);

    CHECK(m.MIPS32SOC->data_mem->memory[4] == 0x11223344);
    CHECK_ERROR_SIGNALS(m);
    REQUIRE(m.invalid_addr == 0);
    clockPulse(m);
    
    CHECK(m.MIPS32SOC->data_mem->memory[16] == 0xdeadbeef);
}

TEST_CASE("'jmp' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    setProgramCode(m, test_jump_code, TEST_JUMP_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(pc == (CODE_BASEADDR + 16));
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(pc == (CODE_BASEADDR + 20));
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(pc == (CODE_BASEADDR + 4));
}

TEST_CASE("'beq' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    a0 = 10500;
    a1 = -3500;
    a2 = 10500;
    a3 = -3500;

    setProgramCode(m, test_beq_code, TEST_BEQ_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(pc == (CODE_BASEADDR + 4));
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(pc == (CODE_BASEADDR + 20));
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(pc == (CODE_BASEADDR + 24));
    clockPulse(m);
    CHECK_ERROR_SIGNALS(m);
    CHECK(pc == (CODE_BASEADDR + 8));
}

TEST_CASE("'bne' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    a0 = 10500;
    a1 = 10500;
    a2 = -3500;
    a3 = -3500;

    setProgramCode(m, test_bne_code, TEST_BNE_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);
    
    CHECK(pc == (CODE_BASEADDR + 4));
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(pc == (CODE_BASEADDR + 20));
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(pc == (CODE_BASEADDR + 24));
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);
    
    CHECK(pc == (CODE_BASEADDR + 8));
}

TEST_CASE("'lui' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);
    setProgramCode(m, test_lui_code, TEST_LUI_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t0 == 0xaabb0000);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t1 == 0xccdd0000);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t2 == 0x11220000);
}

TEST_CASE("'addi' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);
    a0 = 3500;
    a1 = 3500;
    a2 = 3500;

    setProgramCode(m, test_addi_code, TEST_ADDI_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t0 == 4000);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t1 == 3000);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t2 == 0);
}

TEST_CASE("'andi' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);
    a0 = 0xaabbccdd;
    a2 = 0x11223344;

    setProgramCode(m, test_andi_code, TEST_ANDI_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t0 == 0xdd);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t1 == 0x3344);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t2 == 0xc0d0);
}

TEST_CASE("'ori' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);
    a0 = 0xaabbcc00;
    a1 = 0x11223300;
    a2 = 0x11223300;

    setProgramCode(m, test_ori_code, TEST_ORI_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t0 == 0xaabbccdd);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t1 == 0x11223344);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t2 == 0x1122f3cd);
}

TEST_CASE("'xori' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    randomizeRegisterFile(m);
    a0 = 0xaabbccdd;
    a1 = 0xffffffff;
    a2 = 0x11223344;

    setProgramCode(m, test_xori_code, TEST_XORI_CODE_SIZE);

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t0 == 0xAABB3322);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t1 == 0x1122CCBB);
    CHECK_ERROR_SIGNALS(m);
    clockPulse(m);

    CHECK(t2 == 0x11220000);
}

TEST_CASE("'invalid PC' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    // Special program
    m.MIPS32SOC->inst_mem->memory[0] = 0x08100040; //j	0x400100
    m.MIPS32SOC->inst_mem->memory[0x40] = 0x08100100; //j	0x400400

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    clockPulse(m);
    CHECK(m.invalid_pc == 0);
    CHECK(pc == (CODE_BASEADDR + 0x100));
    clockPulse(m);
    CHECK(m.invalid_pc == 1);
}

TEST_CASE("'invalid global address' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    setProgramCode(m, test_invalid_gbladdr_code, TEST_INVALID_GBLADDR_CODE_SIZE);
    a0 = GLOBAL_BASEADDR;

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    REQUIRE(m.invalid_addr == 0);
    clockPulse(m);
    REQUIRE(m.invalid_addr == 0);
    
    clockPulse(m);
    REQUIRE(m.invalid_addr == 0);

    clockPulse(m);
    REQUIRE(m.invalid_addr == 1);

    clockPulse(m);
    REQUIRE(pc == CODE_BASEADDR + 0x10);
    clockPulse(m);
    REQUIRE(pc == CODE_BASEADDR + 0x10);

    a0 = GLOBAL_BASEADDR - 4;
    reset(m);
    REQUIRE(m.invalid_addr == 1);
}

TEST_CASE("'invalid stack address' test") {
    VMIPS32SOC m;
    DECLARE_MIPS32_REGS(m);

    setProgramCode(m, test_invalid_stkaddr_code, TEST_INVALID_STKADDR_CODE_SIZE);
    a1 = STACK_BASEADDR;

    reset(m);
    REQUIRE(pc == CODE_BASEADDR);
    REQUIRE(m.invalid_addr == 0);
    clockPulse(m);
    REQUIRE(m.invalid_addr == 0);
    
    clockPulse(m);
    REQUIRE(m.invalid_addr == 0);

    clockPulse(m);
    REQUIRE(m.invalid_addr == 1);

    clockPulse(m);
    REQUIRE(pc == CODE_BASEADDR + 0x10);
    clockPulse(m);
    REQUIRE(pc == CODE_BASEADDR + 0x10);

    a1 = STACK_BASEADDR - 4;
    reset(m);
    REQUIRE(m.invalid_addr == 1);
}
