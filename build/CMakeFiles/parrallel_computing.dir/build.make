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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xiaopizhu/Desktop/code_project/parrallel-computing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xiaopizhu/Desktop/code_project/parrallel-computing/build

# Include any dependencies generated for this target.
include CMakeFiles/parrallel_computing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/parrallel_computing.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/parrallel_computing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parrallel_computing.dir/flags.make

CMakeFiles/parrallel_computing.dir/main.cpp.o: CMakeFiles/parrallel_computing.dir/flags.make
CMakeFiles/parrallel_computing.dir/main.cpp.o: ../main.cpp
CMakeFiles/parrallel_computing.dir/main.cpp.o: CMakeFiles/parrallel_computing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiaopizhu/Desktop/code_project/parrallel-computing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/parrallel_computing.dir/main.cpp.o"
	/opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parrallel_computing.dir/main.cpp.o -MF CMakeFiles/parrallel_computing.dir/main.cpp.o.d -o CMakeFiles/parrallel_computing.dir/main.cpp.o -c /Users/xiaopizhu/Desktop/code_project/parrallel-computing/main.cpp

CMakeFiles/parrallel_computing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parrallel_computing.dir/main.cpp.i"
	/opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaopizhu/Desktop/code_project/parrallel-computing/main.cpp > CMakeFiles/parrallel_computing.dir/main.cpp.i

CMakeFiles/parrallel_computing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parrallel_computing.dir/main.cpp.s"
	/opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaopizhu/Desktop/code_project/parrallel-computing/main.cpp -o CMakeFiles/parrallel_computing.dir/main.cpp.s

CMakeFiles/parrallel_computing.dir/matrix.cpp.o: CMakeFiles/parrallel_computing.dir/flags.make
CMakeFiles/parrallel_computing.dir/matrix.cpp.o: ../matrix.cpp
CMakeFiles/parrallel_computing.dir/matrix.cpp.o: CMakeFiles/parrallel_computing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiaopizhu/Desktop/code_project/parrallel-computing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/parrallel_computing.dir/matrix.cpp.o"
	/opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parrallel_computing.dir/matrix.cpp.o -MF CMakeFiles/parrallel_computing.dir/matrix.cpp.o.d -o CMakeFiles/parrallel_computing.dir/matrix.cpp.o -c /Users/xiaopizhu/Desktop/code_project/parrallel-computing/matrix.cpp

CMakeFiles/parrallel_computing.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parrallel_computing.dir/matrix.cpp.i"
	/opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiaopizhu/Desktop/code_project/parrallel-computing/matrix.cpp > CMakeFiles/parrallel_computing.dir/matrix.cpp.i

CMakeFiles/parrallel_computing.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parrallel_computing.dir/matrix.cpp.s"
	/opt/homebrew/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiaopizhu/Desktop/code_project/parrallel-computing/matrix.cpp -o CMakeFiles/parrallel_computing.dir/matrix.cpp.s

# Object files for target parrallel_computing
parrallel_computing_OBJECTS = \
"CMakeFiles/parrallel_computing.dir/main.cpp.o" \
"CMakeFiles/parrallel_computing.dir/matrix.cpp.o"

# External object files for target parrallel_computing
parrallel_computing_EXTERNAL_OBJECTS =

parrallel_computing: CMakeFiles/parrallel_computing.dir/main.cpp.o
parrallel_computing: CMakeFiles/parrallel_computing.dir/matrix.cpp.o
parrallel_computing: CMakeFiles/parrallel_computing.dir/build.make
parrallel_computing: CMakeFiles/parrallel_computing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xiaopizhu/Desktop/code_project/parrallel-computing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable parrallel_computing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parrallel_computing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parrallel_computing.dir/build: parrallel_computing
.PHONY : CMakeFiles/parrallel_computing.dir/build

CMakeFiles/parrallel_computing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parrallel_computing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parrallel_computing.dir/clean

CMakeFiles/parrallel_computing.dir/depend:
	cd /Users/xiaopizhu/Desktop/code_project/parrallel-computing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xiaopizhu/Desktop/code_project/parrallel-computing /Users/xiaopizhu/Desktop/code_project/parrallel-computing /Users/xiaopizhu/Desktop/code_project/parrallel-computing/build /Users/xiaopizhu/Desktop/code_project/parrallel-computing/build /Users/xiaopizhu/Desktop/code_project/parrallel-computing/build/CMakeFiles/parrallel_computing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parrallel_computing.dir/depend
