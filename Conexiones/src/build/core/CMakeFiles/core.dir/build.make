# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build"

# Include any dependencies generated for this target.
include core/CMakeFiles/core.dir/depend.make

# Include the progress variables for this target.
include core/CMakeFiles/core.dir/progress.make

# Include the compile flags for this target's objects.
include core/CMakeFiles/core.dir/flags.make

core/CMakeFiles/core.dir/socket.cc.o: core/CMakeFiles/core.dir/flags.make
core/CMakeFiles/core.dir/socket.cc.o: ../core/socket.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object core/CMakeFiles/core.dir/socket.cc.o"
	cd "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build/core" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/core.dir/socket.cc.o -c "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/core/socket.cc"

core/CMakeFiles/core.dir/socket.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/socket.cc.i"
	cd "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build/core" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/core/socket.cc" > CMakeFiles/core.dir/socket.cc.i

core/CMakeFiles/core.dir/socket.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/socket.cc.s"
	cd "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build/core" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/core/socket.cc" -o CMakeFiles/core.dir/socket.cc.s

# Object files for target core
core_OBJECTS = \
"CMakeFiles/core.dir/socket.cc.o"

# External object files for target core
core_EXTERNAL_OBJECTS =

core/libcore.a: core/CMakeFiles/core.dir/socket.cc.o
core/libcore.a: core/CMakeFiles/core.dir/build.make
core/libcore.a: core/CMakeFiles/core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcore.a"
	cd "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build/core" && $(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean_target.cmake
	cd "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build/core" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/CMakeFiles/core.dir/build: core/libcore.a

.PHONY : core/CMakeFiles/core.dir/build

core/CMakeFiles/core.dir/clean:
	cd "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build/core" && $(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean.cmake
.PHONY : core/CMakeFiles/core.dir/clean

core/CMakeFiles/core.dir/depend:
	cd "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src" "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/core" "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build" "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build/core" "/mnt/c/Users/ENDIKA PRADERA/OneDrive/Desktop/proyectos/Desencrypt/Conexiones/src/build/core/CMakeFiles/core.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : core/CMakeFiles/core.dir/depend

