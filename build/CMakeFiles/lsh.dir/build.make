# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/build

# Include any dependencies generated for this target.
include CMakeFiles/lsh.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lsh.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lsh.dir/flags.make

CMakeFiles/lsh.dir/main.cpp.o: CMakeFiles/lsh.dir/flags.make
CMakeFiles/lsh.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lsh.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lsh.dir/main.cpp.o -c /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/main.cpp

CMakeFiles/lsh.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lsh.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/main.cpp > CMakeFiles/lsh.dir/main.cpp.i

CMakeFiles/lsh.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lsh.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/main.cpp -o CMakeFiles/lsh.dir/main.cpp.s

# Object files for target lsh
lsh_OBJECTS = \
"CMakeFiles/lsh.dir/main.cpp.o"

# External object files for target lsh
lsh_EXTERNAL_OBJECTS =

lsh: CMakeFiles/lsh.dir/main.cpp.o
lsh: CMakeFiles/lsh.dir/build.make
lsh: liblsh_source.a
lsh: libreader.a
lsh: CMakeFiles/lsh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lsh"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lsh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lsh.dir/build: lsh

.PHONY : CMakeFiles/lsh.dir/build

CMakeFiles/lsh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lsh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lsh.dir/clean

CMakeFiles/lsh.dir/depend:
	cd /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/build /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/build /home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/build/CMakeFiles/lsh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lsh.dir/depend

