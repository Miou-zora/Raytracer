# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/miouzora/home/epi/Raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/miouzora/home/epi/Raytracer

# Include any dependencies generated for this target.
include CMakeFiles/tests_run.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests_run.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests_run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests_run.dir/flags.make

CMakeFiles/tests_run.dir/tests/test_sample.cpp.o: CMakeFiles/tests_run.dir/flags.make
CMakeFiles/tests_run.dir/tests/test_sample.cpp.o: tests/test_sample.cpp
CMakeFiles/tests_run.dir/tests/test_sample.cpp.o: CMakeFiles/tests_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/miouzora/home/epi/Raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests_run.dir/tests/test_sample.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests_run.dir/tests/test_sample.cpp.o -MF CMakeFiles/tests_run.dir/tests/test_sample.cpp.o.d -o CMakeFiles/tests_run.dir/tests/test_sample.cpp.o -c /home/miouzora/home/epi/Raytracer/tests/test_sample.cpp

CMakeFiles/tests_run.dir/tests/test_sample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests_run.dir/tests/test_sample.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/miouzora/home/epi/Raytracer/tests/test_sample.cpp > CMakeFiles/tests_run.dir/tests/test_sample.cpp.i

CMakeFiles/tests_run.dir/tests/test_sample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests_run.dir/tests/test_sample.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/miouzora/home/epi/Raytracer/tests/test_sample.cpp -o CMakeFiles/tests_run.dir/tests/test_sample.cpp.s

# Object files for target tests_run
tests_run_OBJECTS = \
"CMakeFiles/tests_run.dir/tests/test_sample.cpp.o"

# External object files for target tests_run
tests_run_EXTERNAL_OBJECTS =

tests_run: CMakeFiles/tests_run.dir/tests/test_sample.cpp.o
tests_run: CMakeFiles/tests_run.dir/build.make
tests_run: CMakeFiles/tests_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/miouzora/home/epi/Raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tests_run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests_run.dir/build: tests_run
.PHONY : CMakeFiles/tests_run.dir/build

CMakeFiles/tests_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests_run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests_run.dir/clean

CMakeFiles/tests_run.dir/depend:
	cd /home/miouzora/home/epi/Raytracer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/miouzora/home/epi/Raytracer /home/miouzora/home/epi/Raytracer /home/miouzora/home/epi/Raytracer /home/miouzora/home/epi/Raytracer /home/miouzora/home/epi/Raytracer/CMakeFiles/tests_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests_run.dir/depend

