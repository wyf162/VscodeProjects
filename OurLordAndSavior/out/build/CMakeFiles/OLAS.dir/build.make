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
CMAKE_SOURCE_DIR = /home/yefe/projects/OurLordAndSavior

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yefe/projects/OurLordAndSavior/out/build

# Include any dependencies generated for this target.
include CMakeFiles/OLAS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OLAS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OLAS.dir/flags.make

CMakeFiles/OLAS.dir/main.cpp.o: CMakeFiles/OLAS.dir/flags.make
CMakeFiles/OLAS.dir/main.cpp.o: ../../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yefe/projects/OurLordAndSavior/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OLAS.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OLAS.dir/main.cpp.o -c /home/yefe/projects/OurLordAndSavior/main.cpp

CMakeFiles/OLAS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OLAS.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yefe/projects/OurLordAndSavior/main.cpp > CMakeFiles/OLAS.dir/main.cpp.i

CMakeFiles/OLAS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OLAS.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yefe/projects/OurLordAndSavior/main.cpp -o CMakeFiles/OLAS.dir/main.cpp.s

# Object files for target OLAS
OLAS_OBJECTS = \
"CMakeFiles/OLAS.dir/main.cpp.o"

# External object files for target OLAS
OLAS_EXTERNAL_OBJECTS =

OLAS: CMakeFiles/OLAS.dir/main.cpp.o
OLAS: CMakeFiles/OLAS.dir/build.make
OLAS: CMakeFiles/OLAS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yefe/projects/OurLordAndSavior/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OLAS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OLAS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OLAS.dir/build: OLAS

.PHONY : CMakeFiles/OLAS.dir/build

CMakeFiles/OLAS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OLAS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OLAS.dir/clean

CMakeFiles/OLAS.dir/depend:
	cd /home/yefe/projects/OurLordAndSavior/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yefe/projects/OurLordAndSavior /home/yefe/projects/OurLordAndSavior /home/yefe/projects/OurLordAndSavior/out/build /home/yefe/projects/OurLordAndSavior/out/build /home/yefe/projects/OurLordAndSavior/out/build/CMakeFiles/OLAS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OLAS.dir/depend

