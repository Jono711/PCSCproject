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
CMAKE_SOURCE_DIR = C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug

# Include any dependencies generated for this target.
include Input\CMakeFiles\Input.dir\depend.make

# Include the progress variables for this target.
include Input\CMakeFiles\Input.dir\progress.make

# Include the compile flags for this target's objects.
include Input\CMakeFiles\Input.dir\flags.make

Input\CMakeFiles\Input.dir\Input.cpp.obj: Input\CMakeFiles\Input.dir\flags.make
Input\CMakeFiles\Input.dir\Input.cpp.obj: ..\Input\Input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Input/CMakeFiles/Input.dir/Input.cpp.obj"
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug\Input
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Input.dir\Input.cpp.obj /FdCMakeFiles\Input.dir\ /FS -c C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\Input\Input.cpp
<<
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug

Input\CMakeFiles\Input.dir\Input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Input.dir/Input.cpp.i"
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug\Input
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Input.dir\Input.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\Input\Input.cpp
<<
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug

Input\CMakeFiles\Input.dir\Input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Input.dir/Input.cpp.s"
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug\Input
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Input.dir\Input.cpp.s /c C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\Input\Input.cpp
<<
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug

# Object files for target Input
Input_OBJECTS = \
"CMakeFiles\Input.dir\Input.cpp.obj"

# External object files for target Input
Input_EXTERNAL_OBJECTS =

Input\Input.exe: Input\CMakeFiles\Input.dir\Input.cpp.obj
Input\Input.exe: Input\CMakeFiles\Input.dir\build.make
Input\Input.exe: Input\CMakeFiles\Input.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Input.exe"
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug\Input
	"C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Input.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Input.dir\objects1.rsp @<<
 /out:Input.exe /implib:Input.lib /pdb:C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug\Input\Input.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug

# Rule to build all files generated by this target.
Input\CMakeFiles\Input.dir\build: Input\Input.exe

.PHONY : Input\CMakeFiles\Input.dir\build

Input\CMakeFiles\Input.dir\clean:
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug\Input
	$(CMAKE_COMMAND) -P CMakeFiles\Input.dir\cmake_clean.cmake
	cd C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug
.PHONY : Input\CMakeFiles\Input.dir\clean

Input\CMakeFiles\Input.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\Input C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug\Input C:\Users\morin\OneDrive\Documents\EPFL\PCSC\projet\PCSCproject\cmake-build-debug\Input\CMakeFiles\Input.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Input\CMakeFiles\Input.dir\depend

