# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug

# Include any dependencies generated for this target.
include Vector_Operations\CMakeFiles\VectorOperations.dir\depend.make

# Include the progress variables for this target.
include Vector_Operations\CMakeFiles\VectorOperations.dir\progress.make

# Include the compile flags for this target's objects.
include Vector_Operations\CMakeFiles\VectorOperations.dir\flags.make

Vector_Operations\CMakeFiles\VectorOperations.dir\VectorOperations.cpp.obj: Vector_Operations\CMakeFiles\VectorOperations.dir\flags.make
Vector_Operations\CMakeFiles\VectorOperations.dir\VectorOperations.cpp.obj: ..\Vector_Operations\VectorOperations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Vector_Operations/CMakeFiles/VectorOperations.dir/VectorOperations.cpp.obj"
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug\Vector_Operations
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\VectorOperations.dir\VectorOperations.cpp.obj /FdCMakeFiles\VectorOperations.dir\ /FS -c C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\Vector_Operations\VectorOperations.cpp
<<
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug

Vector_Operations\CMakeFiles\VectorOperations.dir\VectorOperations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VectorOperations.dir/VectorOperations.cpp.i"
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug\Vector_Operations
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\VectorOperations.dir\VectorOperations.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\Vector_Operations\VectorOperations.cpp
<<
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug

Vector_Operations\CMakeFiles\VectorOperations.dir\VectorOperations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VectorOperations.dir/VectorOperations.cpp.s"
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug\Vector_Operations
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\VectorOperations.dir\VectorOperations.cpp.s /c C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\Vector_Operations\VectorOperations.cpp
<<
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug

# Object files for target VectorOperations
VectorOperations_OBJECTS = \
"CMakeFiles\VectorOperations.dir\VectorOperations.cpp.obj"

# External object files for target VectorOperations
VectorOperations_EXTERNAL_OBJECTS =

Vector_Operations\VectorOperations.exe: Vector_Operations\CMakeFiles\VectorOperations.dir\VectorOperations.cpp.obj
Vector_Operations\VectorOperations.exe: Vector_Operations\CMakeFiles\VectorOperations.dir\build.make
Vector_Operations\VectorOperations.exe: Vector_Operations\CMakeFiles\VectorOperations.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable VectorOperations.exe"
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug\Vector_Operations
	"C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\VectorOperations.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\VectorOperations.dir\objects1.rsp @<<
 /out:VectorOperations.exe /implib:VectorOperations.lib /pdb:C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug\Vector_Operations\VectorOperations.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug

# Rule to build all files generated by this target.
Vector_Operations\CMakeFiles\VectorOperations.dir\build: Vector_Operations\VectorOperations.exe

.PHONY : Vector_Operations\CMakeFiles\VectorOperations.dir\build

Vector_Operations\CMakeFiles\VectorOperations.dir\clean:
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug\Vector_Operations
	$(CMAKE_COMMAND) -P CMakeFiles\VectorOperations.dir\cmake_clean.cmake
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug
.PHONY : Vector_Operations\CMakeFiles\VectorOperations.dir\clean

Vector_Operations\CMakeFiles\VectorOperations.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\Vector_Operations C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug\Vector_Operations C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\cmake-build-debug\Vector_Operations\CMakeFiles\VectorOperations.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Vector_Operations\CMakeFiles\VectorOperations.dir\depend

