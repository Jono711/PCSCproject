# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/youssef/Desktop/PCSCproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/youssef/Desktop/PCSCproject/cmake-build-debug

# Include any dependencies generated for this target.
include src/Data_Fitting/CMakeFiles/Data_Fitting.dir/depend.make

# Include the progress variables for this target.
include src/Data_Fitting/CMakeFiles/Data_Fitting.dir/progress.make

# Include the compile flags for this target's objects.
include src/Data_Fitting/CMakeFiles/Data_Fitting.dir/flags.make

src/Data_Fitting/CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.o: src/Data_Fitting/CMakeFiles/Data_Fitting.dir/flags.make
src/Data_Fitting/CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.o: ../src/Data_Fitting/LeastSquares.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/youssef/Desktop/PCSCproject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Data_Fitting/CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.o"
	cd /Users/youssef/Desktop/PCSCproject/cmake-build-debug/src/Data_Fitting && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.o -c /Users/youssef/Desktop/PCSCproject/src/Data_Fitting/LeastSquares.cpp

src/Data_Fitting/CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.i"
	cd /Users/youssef/Desktop/PCSCproject/cmake-build-debug/src/Data_Fitting && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/youssef/Desktop/PCSCproject/src/Data_Fitting/LeastSquares.cpp > CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.i

src/Data_Fitting/CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.s"
	cd /Users/youssef/Desktop/PCSCproject/cmake-build-debug/src/Data_Fitting && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/youssef/Desktop/PCSCproject/src/Data_Fitting/LeastSquares.cpp -o CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.s

# Object files for target Data_Fitting
Data_Fitting_OBJECTS = \
"CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.o"

# External object files for target Data_Fitting
Data_Fitting_EXTERNAL_OBJECTS =

src/Data_Fitting/libData_Fitting.a: src/Data_Fitting/CMakeFiles/Data_Fitting.dir/LeastSquares.cpp.o
src/Data_Fitting/libData_Fitting.a: src/Data_Fitting/CMakeFiles/Data_Fitting.dir/build.make
src/Data_Fitting/libData_Fitting.a: src/Data_Fitting/CMakeFiles/Data_Fitting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/youssef/Desktop/PCSCproject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libData_Fitting.a"
	cd /Users/youssef/Desktop/PCSCproject/cmake-build-debug/src/Data_Fitting && $(CMAKE_COMMAND) -P CMakeFiles/Data_Fitting.dir/cmake_clean_target.cmake
	cd /Users/youssef/Desktop/PCSCproject/cmake-build-debug/src/Data_Fitting && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Data_Fitting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Data_Fitting/CMakeFiles/Data_Fitting.dir/build: src/Data_Fitting/libData_Fitting.a

.PHONY : src/Data_Fitting/CMakeFiles/Data_Fitting.dir/build

src/Data_Fitting/CMakeFiles/Data_Fitting.dir/clean:
	cd /Users/youssef/Desktop/PCSCproject/cmake-build-debug/src/Data_Fitting && $(CMAKE_COMMAND) -P CMakeFiles/Data_Fitting.dir/cmake_clean.cmake
.PHONY : src/Data_Fitting/CMakeFiles/Data_Fitting.dir/clean

src/Data_Fitting/CMakeFiles/Data_Fitting.dir/depend:
	cd /Users/youssef/Desktop/PCSCproject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/youssef/Desktop/PCSCproject /Users/youssef/Desktop/PCSCproject/src/Data_Fitting /Users/youssef/Desktop/PCSCproject/cmake-build-debug /Users/youssef/Desktop/PCSCproject/cmake-build-debug/src/Data_Fitting /Users/youssef/Desktop/PCSCproject/cmake-build-debug/src/Data_Fitting/CMakeFiles/Data_Fitting.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Data_Fitting/CMakeFiles/Data_Fitting.dir/depend

