# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/progalap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/progalap.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/progalap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/progalap.dir/flags.make

CMakeFiles/progalap.dir/main.c.o: CMakeFiles/progalap.dir/flags.make
CMakeFiles/progalap.dir/main.c.o: ../main.c
CMakeFiles/progalap.dir/main.c.o: CMakeFiles/progalap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/progalap.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/progalap.dir/main.c.o -MF CMakeFiles/progalap.dir/main.c.o.d -o CMakeFiles/progalap.dir/main.c.o -c /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/main.c

CMakeFiles/progalap.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/progalap.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/main.c > CMakeFiles/progalap.dir/main.c.i

CMakeFiles/progalap.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/progalap.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/main.c -o CMakeFiles/progalap.dir/main.c.s

CMakeFiles/progalap.dir/beolvaso.c.o: CMakeFiles/progalap.dir/flags.make
CMakeFiles/progalap.dir/beolvaso.c.o: ../beolvaso.c
CMakeFiles/progalap.dir/beolvaso.c.o: CMakeFiles/progalap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/progalap.dir/beolvaso.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/progalap.dir/beolvaso.c.o -MF CMakeFiles/progalap.dir/beolvaso.c.o.d -o CMakeFiles/progalap.dir/beolvaso.c.o -c /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/beolvaso.c

CMakeFiles/progalap.dir/beolvaso.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/progalap.dir/beolvaso.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/beolvaso.c > CMakeFiles/progalap.dir/beolvaso.c.i

CMakeFiles/progalap.dir/beolvaso.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/progalap.dir/beolvaso.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/beolvaso.c -o CMakeFiles/progalap.dir/beolvaso.c.s

# Object files for target progalap
progalap_OBJECTS = \
"CMakeFiles/progalap.dir/main.c.o" \
"CMakeFiles/progalap.dir/beolvaso.c.o"

# External object files for target progalap
progalap_EXTERNAL_OBJECTS =

progalap: CMakeFiles/progalap.dir/main.c.o
progalap: CMakeFiles/progalap.dir/beolvaso.c.o
progalap: CMakeFiles/progalap.dir/build.make
progalap: libkiir.a
progalap: item/libitem.a
progalap: CMakeFiles/progalap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable progalap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/progalap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/progalap.dir/build: progalap
.PHONY : CMakeFiles/progalap.dir/build

CMakeFiles/progalap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/progalap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/progalap.dir/clean

CMakeFiles/progalap.dir/depend:
	cd /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/cmake-build-debug /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/cmake-build-debug /mnt/d/university/sem2/progalap/SZTE-progalap-cash-register/cmake-build-debug/CMakeFiles/progalap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/progalap.dir/depend
