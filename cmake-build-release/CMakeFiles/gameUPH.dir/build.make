# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kali/CLionProjects/gameUPH

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kali/CLionProjects/gameUPH/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/gameUPH.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gameUPH.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gameUPH.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gameUPH.dir/flags.make

CMakeFiles/gameUPH.dir/codegen:
.PHONY : CMakeFiles/gameUPH.dir/codegen

CMakeFiles/gameUPH.dir/main.c.o: CMakeFiles/gameUPH.dir/flags.make
CMakeFiles/gameUPH.dir/main.c.o: /home/kali/CLionProjects/gameUPH/main.c
CMakeFiles/gameUPH.dir/main.c.o: CMakeFiles/gameUPH.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/CLionProjects/gameUPH/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gameUPH.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gameUPH.dir/main.c.o -MF CMakeFiles/gameUPH.dir/main.c.o.d -o CMakeFiles/gameUPH.dir/main.c.o -c /home/kali/CLionProjects/gameUPH/main.c

CMakeFiles/gameUPH.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/gameUPH.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kali/CLionProjects/gameUPH/main.c > CMakeFiles/gameUPH.dir/main.c.i

CMakeFiles/gameUPH.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/gameUPH.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kali/CLionProjects/gameUPH/main.c -o CMakeFiles/gameUPH.dir/main.c.s

CMakeFiles/gameUPH.dir/src/game.c.o: CMakeFiles/gameUPH.dir/flags.make
CMakeFiles/gameUPH.dir/src/game.c.o: /home/kali/CLionProjects/gameUPH/src/game.c
CMakeFiles/gameUPH.dir/src/game.c.o: CMakeFiles/gameUPH.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/CLionProjects/gameUPH/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/gameUPH.dir/src/game.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gameUPH.dir/src/game.c.o -MF CMakeFiles/gameUPH.dir/src/game.c.o.d -o CMakeFiles/gameUPH.dir/src/game.c.o -c /home/kali/CLionProjects/gameUPH/src/game.c

CMakeFiles/gameUPH.dir/src/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/gameUPH.dir/src/game.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kali/CLionProjects/gameUPH/src/game.c > CMakeFiles/gameUPH.dir/src/game.c.i

CMakeFiles/gameUPH.dir/src/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/gameUPH.dir/src/game.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kali/CLionProjects/gameUPH/src/game.c -o CMakeFiles/gameUPH.dir/src/game.c.s

CMakeFiles/gameUPH.dir/src/input.c.o: CMakeFiles/gameUPH.dir/flags.make
CMakeFiles/gameUPH.dir/src/input.c.o: /home/kali/CLionProjects/gameUPH/src/input.c
CMakeFiles/gameUPH.dir/src/input.c.o: CMakeFiles/gameUPH.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/CLionProjects/gameUPH/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/gameUPH.dir/src/input.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gameUPH.dir/src/input.c.o -MF CMakeFiles/gameUPH.dir/src/input.c.o.d -o CMakeFiles/gameUPH.dir/src/input.c.o -c /home/kali/CLionProjects/gameUPH/src/input.c

CMakeFiles/gameUPH.dir/src/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/gameUPH.dir/src/input.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kali/CLionProjects/gameUPH/src/input.c > CMakeFiles/gameUPH.dir/src/input.c.i

CMakeFiles/gameUPH.dir/src/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/gameUPH.dir/src/input.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kali/CLionProjects/gameUPH/src/input.c -o CMakeFiles/gameUPH.dir/src/input.c.s

CMakeFiles/gameUPH.dir/src/render.c.o: CMakeFiles/gameUPH.dir/flags.make
CMakeFiles/gameUPH.dir/src/render.c.o: /home/kali/CLionProjects/gameUPH/src/render.c
CMakeFiles/gameUPH.dir/src/render.c.o: CMakeFiles/gameUPH.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/CLionProjects/gameUPH/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/gameUPH.dir/src/render.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gameUPH.dir/src/render.c.o -MF CMakeFiles/gameUPH.dir/src/render.c.o.d -o CMakeFiles/gameUPH.dir/src/render.c.o -c /home/kali/CLionProjects/gameUPH/src/render.c

CMakeFiles/gameUPH.dir/src/render.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/gameUPH.dir/src/render.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kali/CLionProjects/gameUPH/src/render.c > CMakeFiles/gameUPH.dir/src/render.c.i

CMakeFiles/gameUPH.dir/src/render.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/gameUPH.dir/src/render.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kali/CLionProjects/gameUPH/src/render.c -o CMakeFiles/gameUPH.dir/src/render.c.s

CMakeFiles/gameUPH.dir/src/sprites.c.o: CMakeFiles/gameUPH.dir/flags.make
CMakeFiles/gameUPH.dir/src/sprites.c.o: /home/kali/CLionProjects/gameUPH/src/sprites.c
CMakeFiles/gameUPH.dir/src/sprites.c.o: CMakeFiles/gameUPH.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/CLionProjects/gameUPH/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/gameUPH.dir/src/sprites.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gameUPH.dir/src/sprites.c.o -MF CMakeFiles/gameUPH.dir/src/sprites.c.o.d -o CMakeFiles/gameUPH.dir/src/sprites.c.o -c /home/kali/CLionProjects/gameUPH/src/sprites.c

CMakeFiles/gameUPH.dir/src/sprites.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/gameUPH.dir/src/sprites.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kali/CLionProjects/gameUPH/src/sprites.c > CMakeFiles/gameUPH.dir/src/sprites.c.i

CMakeFiles/gameUPH.dir/src/sprites.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/gameUPH.dir/src/sprites.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kali/CLionProjects/gameUPH/src/sprites.c -o CMakeFiles/gameUPH.dir/src/sprites.c.s

# Object files for target gameUPH
gameUPH_OBJECTS = \
"CMakeFiles/gameUPH.dir/main.c.o" \
"CMakeFiles/gameUPH.dir/src/game.c.o" \
"CMakeFiles/gameUPH.dir/src/input.c.o" \
"CMakeFiles/gameUPH.dir/src/render.c.o" \
"CMakeFiles/gameUPH.dir/src/sprites.c.o"

# External object files for target gameUPH
gameUPH_EXTERNAL_OBJECTS =

gameUPH: CMakeFiles/gameUPH.dir/main.c.o
gameUPH: CMakeFiles/gameUPH.dir/src/game.c.o
gameUPH: CMakeFiles/gameUPH.dir/src/input.c.o
gameUPH: CMakeFiles/gameUPH.dir/src/render.c.o
gameUPH: CMakeFiles/gameUPH.dir/src/sprites.c.o
gameUPH: CMakeFiles/gameUPH.dir/build.make
gameUPH: CMakeFiles/gameUPH.dir/compiler_depend.ts
gameUPH: /usr/lib/libcurses.so
gameUPH: /usr/lib/libform.so
gameUPH: CMakeFiles/gameUPH.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kali/CLionProjects/gameUPH/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable gameUPH"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gameUPH.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gameUPH.dir/build: gameUPH
.PHONY : CMakeFiles/gameUPH.dir/build

CMakeFiles/gameUPH.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gameUPH.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gameUPH.dir/clean

CMakeFiles/gameUPH.dir/depend:
	cd /home/kali/CLionProjects/gameUPH/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kali/CLionProjects/gameUPH /home/kali/CLionProjects/gameUPH /home/kali/CLionProjects/gameUPH/cmake-build-release /home/kali/CLionProjects/gameUPH/cmake-build-release /home/kali/CLionProjects/gameUPH/cmake-build-release/CMakeFiles/gameUPH.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/gameUPH.dir/depend

