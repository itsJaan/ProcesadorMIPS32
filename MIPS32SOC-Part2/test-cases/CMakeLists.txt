cmake_minimum_required (VERSION 3.0)
project (test_MIPS32SOC)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/")

find_package(VERILATOR REQUIRED)

set(CPP_SRC_DIR "${CMAKE_SOURCE_DIR}/../../cpp")
set(VERILOG_SRC_DIR "${CMAKE_SOURCE_DIR}/../verilog")
set(VERILOG_SOURCES "${VERILOG_SRC_DIR}/MIPS32SOC.v")
set(VTOPMODULE "MIPS32SOC")
set(VERILOG_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/verilog-build")
set(VREWRITE "${CMAKE_SOURCE_DIR}/../tools/vrewrite")

set(CPP_GEN_SOURCES    "${VERILOG_BINARY_DIR}/VMIPS32SOC__Syms.cpp \
                        ${VERILOG_BINARY_DIR}/VMIPS32SOC.cpp \
                        ${VERILOG_BINARY_DIR}/VMIPS32SOC_MIPS32SOC.cpp \
                        ${VERILOG_BINARY_DIR}/VMIPS32SOC_AsyncROM.cpp \
                        ${VERILOG_BINARY_DIR}/VMIPS32SOC_RegisterFile.cpp \
                        ${VERILOG_BINARY_DIR}/VMIPS32SOC_RAMDualPort.cpp")

separate_arguments(VERILOG_SOURCES)
separate_arguments(CPP_GEN_SOURCES)

# Run vrewrite to generate MIPS32SOC verilog file
add_custom_command (
    OUTPUT  ${VTOPMODULE}.v
    COMMAND ${VREWRITE} --in ${VERILOG_SRC_DIR}/${VTOPMODULE}.v --out ${VTOPMODULE}.v --repl-with ${VERILOG_SRC_DIR}/mips32soc_repl.v

    MAIN_DEPENDENCY ${VERILOG_SRC_DIR}/${VTOPMODULE}.v
    DEPENDS ${VERILOG_SRC_DIR}/mips32soc_repl.v
  )

# Run verilator to compile the MIPS32SOC
add_custom_command (
    OUTPUT  ${CPP_GEN_SOURCES}
    COMMAND ${VERILATOR} -DNO_INIT_MEM -Wall -Wno-fatal -I${CMAKE_CURRENT_BINARY_DIR} --cc ${VTOPMODULE}.v
            --top-module ${VTOPMODULE} -Mdir ${VERILOG_BINARY_DIR} -CFLAGS "-I${CPP_SRC_DIR} -std=c++14 -O2 -DNDEBUG"

    MAIN_DEPENDENCY ${VTOPMODULE}.v
  )

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${VERILOG_BINARY_DIR})
include_directories(${VERILATOR_INCLUDE_DIR})
include_directories(${VERILATOR_DPI_INCLUDE_DIR})
include_directories(${CPP_SRC_DIR})

set_directory_properties(
    PROPERTIES
    ADDITIONAL_MAKE_CLEAN_FILES "${VERILOG_BINARY_DIR}"
)

add_executable(${PROJECT_NAME}  ${VERILATOR_INCLUDE_DIR}/verilated.cpp
                                ${CPP_GEN_SOURCES}
                                ${PROJECT_NAME}.cpp
                )
