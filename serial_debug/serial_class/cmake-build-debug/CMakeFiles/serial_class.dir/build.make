# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/serial_class.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/serial_class.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serial_class.dir/flags.make

CMakeFiles/serial_class.dir/main.cpp.o: CMakeFiles/serial_class.dir/flags.make
CMakeFiles/serial_class.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serial_class.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serial_class.dir/main.cpp.o -c /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/main.cpp

CMakeFiles/serial_class.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial_class.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/main.cpp > CMakeFiles/serial_class.dir/main.cpp.i

CMakeFiles/serial_class.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial_class.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/main.cpp -o CMakeFiles/serial_class.dir/main.cpp.s

CMakeFiles/serial_class.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/serial_class.dir/main.cpp.o.requires

CMakeFiles/serial_class.dir/main.cpp.o.provides: CMakeFiles/serial_class.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/serial_class.dir/build.make CMakeFiles/serial_class.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/serial_class.dir/main.cpp.o.provides

CMakeFiles/serial_class.dir/main.cpp.o.provides.build: CMakeFiles/serial_class.dir/main.cpp.o


CMakeFiles/serial_class.dir/serial.cpp.o: CMakeFiles/serial_class.dir/flags.make
CMakeFiles/serial_class.dir/serial.cpp.o: ../serial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/serial_class.dir/serial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serial_class.dir/serial.cpp.o -c /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/serial.cpp

CMakeFiles/serial_class.dir/serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial_class.dir/serial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/serial.cpp > CMakeFiles/serial_class.dir/serial.cpp.i

CMakeFiles/serial_class.dir/serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial_class.dir/serial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/serial.cpp -o CMakeFiles/serial_class.dir/serial.cpp.s

CMakeFiles/serial_class.dir/serial.cpp.o.requires:

.PHONY : CMakeFiles/serial_class.dir/serial.cpp.o.requires

CMakeFiles/serial_class.dir/serial.cpp.o.provides: CMakeFiles/serial_class.dir/serial.cpp.o.requires
	$(MAKE) -f CMakeFiles/serial_class.dir/build.make CMakeFiles/serial_class.dir/serial.cpp.o.provides.build
.PHONY : CMakeFiles/serial_class.dir/serial.cpp.o.provides

CMakeFiles/serial_class.dir/serial.cpp.o.provides.build: CMakeFiles/serial_class.dir/serial.cpp.o


# Object files for target serial_class
serial_class_OBJECTS = \
"CMakeFiles/serial_class.dir/main.cpp.o" \
"CMakeFiles/serial_class.dir/serial.cpp.o"

# External object files for target serial_class
serial_class_EXTERNAL_OBJECTS =

serial_class: CMakeFiles/serial_class.dir/main.cpp.o
serial_class: CMakeFiles/serial_class.dir/serial.cpp.o
serial_class: CMakeFiles/serial_class.dir/build.make
serial_class: CMakeFiles/serial_class.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable serial_class"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial_class.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serial_class.dir/build: serial_class

.PHONY : CMakeFiles/serial_class.dir/build

CMakeFiles/serial_class.dir/requires: CMakeFiles/serial_class.dir/main.cpp.o.requires
CMakeFiles/serial_class.dir/requires: CMakeFiles/serial_class.dir/serial.cpp.o.requires

.PHONY : CMakeFiles/serial_class.dir/requires

CMakeFiles/serial_class.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serial_class.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serial_class.dir/clean

CMakeFiles/serial_class.dir/depend:
	cd /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/cmake-build-debug /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/cmake-build-debug /home/michael/文档/C++Projects/RMCV/serial_debug/serial_class/cmake-build-debug/CMakeFiles/serial_class.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serial_class.dir/depend

