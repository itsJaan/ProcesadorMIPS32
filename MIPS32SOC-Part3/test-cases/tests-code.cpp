// File 'test_add.S'
const uint32_t test_add_code[] = {
    /*0x00400000: */ 0x00854020, //add	t0, a0, a1
    /*0x00400004: */ 0x00c74820, //add	t1, a2, a3
    /*0x00400008: */ 0x00a65020, //add	t2, a1, a2
    /*0x0040000c: */ 0x08100003, //j	0x40000c
};
const int TEST_ADD_CODE_SIZE = 4;

// File 'test_sub.S'
const uint32_t test_sub_code[] = {
    /*0x00400000: */ 0x00854022, //sub	t0, a0, a1
    /*0x00400004: */ 0x00c74822, //sub	t1, a2, a3
    /*0x00400008: */ 0x00a65022, //sub	t2, a1, a2
    /*0x0040000c: */ 0x08100003, //j	0x40000c
};
const int TEST_SUB_CODE_SIZE = 4;

// File 'test_and.S'
const uint32_t test_and_code[] = {
    /*0x00400000: */ 0x00854024, //and	t0, a0, a1
    /*0x00400004: */ 0x00c74824, //and	t1, a2, a3
    /*0x00400008: */ 0x00a65024, //and	t2, a1, a2
    /*0x0040000c: */ 0x08100003, //j	0x40000c
};
const int TEST_AND_CODE_SIZE = 4;

// File 'test_or.S'
const uint32_t test_or_code[] = {
    /*0x00400000: */ 0x00854025, //or	t0, a0, a1
    /*0x00400004: */ 0x00c74825, //or	t1, a2, a3
    /*0x00400008: */ 0x00a65025, //or	t2, a1, a2
    /*0x0040000c: */ 0x08100003, //j	0x40000c
};
const int TEST_OR_CODE_SIZE = 4;

// File 'test_slt.S'
const uint32_t test_slt_code[] = {
    /*0x00400000: */ 0x0085402a, //slt	t0, a0, a1
    /*0x00400004: */ 0x00c7482a, //slt	t1, a2, a3
    /*0x00400008: */ 0x00a6502a, //slt	t2, a1, a2
    /*0x0040000c: */ 0x08100003, //j	0x40000c
};
const int TEST_SLT_CODE_SIZE = 4;

// File 'test_beq.S'
const uint32_t test_beq_code[] = {
    /*0x00400000: */ 0x10850004, //beq	a0, a1, 0x400014
    /*0x00400004: */ 0x10860003, //beq	a0, a2, 0x400014
    /*0x00400008: */ 0x00005020, //add	t2, zero, zero
    /*0x0040000c: */ 0x00005020, //add	t2, zero, zero
    /*0x00400010: */ 0x00005020, //add	t2, zero, zero
    /*0x00400014: */ 0x00005020, //add	t2, zero, zero
    /*0x00400018: */ 0x10a7fffb, //beq	a1, a3, 0x400008
};
const int TEST_BEQ_CODE_SIZE = 7;

// File 'test_bne.S'
const uint32_t test_bne_code[] = {
    /*0x00400000: */ 0x14850004, //bne	a0, a1, 0x400014
    /*0x00400004: */ 0x14860003, //bne	a0, a2, 0x400014
    /*0x00400008: */ 0x00005020, //add	t2, zero, zero
    /*0x0040000c: */ 0x00005020, //add	t2, zero, zero
    /*0x00400010: */ 0x00005020, //add	t2, zero, zero
    /*0x00400014: */ 0x00005020, //add	t2, zero, zero
    /*0x00400018: */ 0x14a7fffb, //bne	a1, a3, 0x400008
};
const int TEST_BNE_CODE_SIZE = 7;

// File 'test_jump.S'
const uint32_t test_jump_code[] = {
    /*0x00400000: */ 0x08100004, //j	0x400010
    /*0x00400004: */ 0x00005020, //add	t2, zero, zero
    /*0x00400008: */ 0x00005020, //add	t2, zero, zero
    /*0x0040000c: */ 0x00005020, //add	t2, zero, zero
    /*0x00400010: */ 0x00005020, //add	t2, zero, zero
    /*0x00400014: */ 0x08100001, //j	0x400004
};
const int TEST_JUMP_CODE_SIZE = 6;

// File 'test_lw.S'
const uint32_t test_lw_code[] = {
    /*0x00400000: */ 0x8c880000, //lw	t0, 0(a0)
    /*0x00400004: */ 0x8c890010, //lw	t1, 16(a0)
    /*0x00400008: */ 0x8c8a0040, //lw	t2, 64(a0)
    /*0x0040000c: */ 0x08100003, //j	0x40000c
};
const int TEST_LW_CODE_SIZE = 4;

// File 'test_sw.S'
const uint32_t test_sw_code[] = {
    /*0x00400000: */ 0xac880000, //sw	t0, 0(a0)
    /*0x00400004: */ 0xac890010, //sw	t1, 16(a0)
    /*0x00400008: */ 0xac8a0040, //sw	t2, 64(a0)
    /*0x0040000c: */ 0x08100003, //j	0x40000c
};
const int TEST_SW_CODE_SIZE = 4;

// File 'test_addi.S'
const uint32_t test_addi_code[] = {
    /*0x00000000: */ 0x208801f4, //addi	t0, a0, 500
    /*0x00000004: */ 0x20c9fe0c, //addi	t1, a2, -500
    /*0x00000008: */ 0x20aaf254, //addi	t2, a1, -3500
    /*0x0000000c: */ 0x08000003, //j	0xc
};
const int TEST_ADDI_CODE_SIZE = 4;

// File 'test_andi.S'
const uint32_t test_andi_code[] = {
    /*0x00000000: */ 0x308800ff, //andi	t0, a0, 0xff
    /*0x00000004: */ 0x30c9ffff, //andi	t1, a2, 0xffff
    /*0x00000008: */ 0x308af0f0, //andi	t2, a0, 0xf0f0
    /*0x0000000c: */ 0x08000003, //j	0xc
};
const int TEST_ANDI_CODE_SIZE = 4;

// File 'test_ori.S'
const uint32_t test_ori_code[] = {
    /*0x00000000: */ 0x348800dd, //ori	t0, a0, 0xdd
    /*0x00000004: */ 0x34c90044, //ori	t1, a2, 0x44
    /*0x00000008: */ 0x34aac0cd, //ori	t2, a1, 0xc0cd
    /*0x0000000c: */ 0x08000003, //j	0xc
};
const int TEST_ORI_CODE_SIZE = 4;

// File 'test_lui.S'
const uint32_t test_lui_code[] = {
    /*0x00000000: */ 0x3c08aabb, //lui	t0, 0xaabb
    /*0x00000004: */ 0x3c09ccdd, //lui	t1, 0xccdd
    /*0x00000008: */ 0x3c0a1122, //lui	t2, 0x1122
    /*0x0000000c: */ 0x08000003, //j	0xc
};
const int TEST_LUI_CODE_SIZE = 4;

// File 'test_xor.S'
const uint32_t test_xor_code[] = {
    /*0x00000000: */ 0x00854026, //xor	t0, a0, a1
    /*0x00000004: */ 0x00c54826, //xor	t1, a2, a1
    /*0x00000008: */ 0x00c65026, //xor	t2, a2, a2
    /*0x0000000c: */ 0x08000003, //j	0xc
};
const int TEST_XOR_CODE_SIZE = 4;

// File 'test_xori.S'
const uint32_t test_xori_code[] = {
    /*0x00000000: */ 0x3888ffff, //xori	t0, a0, 0xffff
    /*0x00000004: */ 0x38c9ffff, //xori	t1, a2, 0xffff
    /*0x00000008: */ 0x38ca3344, //xori	t2, a2, 0x3344
    /*0x0000000c: */ 0x08000003, //j	0xc
};
const int TEST_XORI_CODE_SIZE = 4;

// File 'test_invalid_gbladdr.S'
const uint32_t test_invalid_gbladdr_code[] = {
    /*0x00400000: */ 0x8c880000, //lw	t0, 0(a0)
    /*0x00400004: */ 0x8c8803f8, //lw	t0, 1028(a0)
    /*0x00400008: */ 0x8c8803fc, //lw	t0, 1020(a0)
    /*0x0040000c: */ 0x8c880400, //lw	t0, 1024(a0)
    /*0x00400010: */ 0x08100004, //j	0x400010
};
const int TEST_INVALID_GBLADDR_CODE_SIZE = 5;

// File 'test_invalid_stkaddr.S'
const uint32_t test_invalid_stkaddr_code[] = {
    /*0x00400000: */ 0x8ca80000, //lw	t0, 0(a0)
    /*0x00400004: */ 0x8ca803f8, //lw	t0, 1028(a0)
    /*0x00400008: */ 0x8ca803fc, //lw	t0, 1020(a0)
    /*0x0040000c: */ 0x8ca80400, //lw	t0, 1024(a0)
    /*0x00400010: */ 0x08100004, //j	0x400010
};
const int TEST_INVALID_STKADDR_CODE_SIZE = 5;

// File 'mult.S'
const uint32_t test_mult_code[] = {
    /*0x00400000: */ 0x00850018, //mult	a0, a1
    /*0x00400004: */ 0x08100001, //j	0x400004
};
const int TEST_MULT_CODE_SIZE = 2;

// File 'div.S'
const uint32_t test_div_code[] = {
    /*0x00400000: */ 0x0085001a, //div	a0, a1
    /*0x00400004: */ 0x08100001, //j	0x400004
};
const int TEST_DIV_CODE_SIZE = 2;

// File 'mflo.S'
const uint32_t test_mflo_code[] = {
    /*0x00400000: */ 0x00002012, //mflo	a0
    /*0x00400004: */ 0x08100001, //j	0x400004
};
const int TEST_MFLO_CODE_SIZE = 2;

// File 'mfhi.S'
const uint32_t test_mfhi_code[] = {
    /*0x00400000: */ 0x00002010, //mfhi	a0
    /*0x00400004: */ 0x08100001, //j	0x400004
};
const int TEST_MFHI_CODE_SIZE = 2;