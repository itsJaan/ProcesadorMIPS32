# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build

# Include any dependencies generated for this target.
include CMakeFiles/test_MIPS32SOC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_MIPS32SOC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_MIPS32SOC.dir/flags.make

verilog-build/VMIPS32SOC__ALL.a: /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/verilog/MIPS32SOC.v
verilog-build/VMIPS32SOC__ALL.a: /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/verilog/MIPS32SOC.v
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating verilog-build/VMIPS32SOC__ALL.a"
	/usr/bin/verilator -DNO_INIT_MEM -Wall -Wno-fatal -I/home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog --cc /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../verilog/MIPS32SOC.v --top-module MIPS32SOC -Mdir /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build/verilog-build -CFLAGS -I/home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/../../cpp\ -std=c++14\ -O2\ -DNDEBUG
	make -C /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build/verilog-build -f VMIPS32SOC.mk

CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o: CMakeFiles/test_MIPS32SOC.dir/flags.make
CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o: /usr/share/verilator/include/verilated.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o -c /usr/share/verilator/include/verilated.cpp

CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/share/verilator/include/verilated.cpp > CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.i

CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/share/verilator/include/verilated.cpp -o CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.s

CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o.requires:

.PHONY : CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o.requires

CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o.provides: CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_MIPS32SOC.dir/build.make CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o.provides.build
.PHONY : CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o.provides

CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o.provides.build: CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o


CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o: CMakeFiles/test_MIPS32SOC.dir/flags.make
CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o: /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/test_MIPS32SOC.cpp
CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o: verilog-build/VMIPS32SOC__ALL.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o -c /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/test_MIPS32SOC.cpp

CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/test_MIPS32SOC.cpp > CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.i

CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases/test_MIPS32SOC.cpp -o CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.s

CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o.requires:

.PHONY : CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o.requires

CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o.provides: CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_MIPS32SOC.dir/build.make CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o.provides.build
.PHONY : CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o.provides

CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o.provides.build: CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o


# Object files for target test_MIPS32SOC
test_MIPS32SOC_OBJECTS = \
"CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o" \
"CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o"

# External object files for target test_MIPS32SOC
test_MIPS32SOC_EXTERNAL_OBJECTS =

test_MIPS32SOC: CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o
test_MIPS32SOC: CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o
test_MIPS32SOC: CMakeFiles/test_MIPS32SOC.dir/build.make
test_MIPS32SOC: verilog-build/VMIPS32SOC__ALL.a
test_MIPS32SOC: CMakeFiles/test_MIPS32SOC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_MIPS32SOC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_MIPS32SOC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_MIPS32SOC.dir/build: test_MIPS32SOC

.PHONY : CMakeFiles/test_MIPS32SOC.dir/build

CMakeFiles/test_MIPS32SOC.dir/requires: CMakeFiles/test_MIPS32SOC.dir/usr/share/verilator/include/verilated.cpp.o.requires
CMakeFiles/test_MIPS32SOC.dir/requires: CMakeFiles/test_MIPS32SOC.dir/test_MIPS32SOC.cpp.o.requires

.PHONY : CMakeFiles/test_MIPS32SOC.dir/requires

CMakeFiles/test_MIPS32SOC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_MIPS32SOC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_MIPS32SOC.dir/clean

CMakeFiles/test_MIPS32SOC.dir/depend: verilog-build/VMIPS32SOC__ALL.a
	cd /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/test-cases /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build /home/itsjaan/Documentos/Procesador_Proyecto/MIPS32SOC-Part1/build/CMakeFiles/test_MIPS32SOC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_MIPS32SOC.dir/depend

