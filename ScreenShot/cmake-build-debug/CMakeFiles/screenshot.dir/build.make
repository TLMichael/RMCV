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
CMAKE_SOURCE_DIR = /home/michael/文档/C++Projects/RMCV/ScreenShot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michael/文档/C++Projects/RMCV/ScreenShot/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/screenshot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/screenshot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/screenshot.dir/flags.make

CMakeFiles/screenshot.dir/excited.cpp.o: CMakeFiles/screenshot.dir/flags.make
CMakeFiles/screenshot.dir/excited.cpp.o: ../excited.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/文档/C++Projects/RMCV/ScreenShot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/screenshot.dir/excited.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/screenshot.dir/excited.cpp.o -c /home/michael/文档/C++Projects/RMCV/ScreenShot/excited.cpp

CMakeFiles/screenshot.dir/excited.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/screenshot.dir/excited.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michael/文档/C++Projects/RMCV/ScreenShot/excited.cpp > CMakeFiles/screenshot.dir/excited.cpp.i

CMakeFiles/screenshot.dir/excited.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/screenshot.dir/excited.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michael/文档/C++Projects/RMCV/ScreenShot/excited.cpp -o CMakeFiles/screenshot.dir/excited.cpp.s

CMakeFiles/screenshot.dir/excited.cpp.o.requires:

.PHONY : CMakeFiles/screenshot.dir/excited.cpp.o.requires

CMakeFiles/screenshot.dir/excited.cpp.o.provides: CMakeFiles/screenshot.dir/excited.cpp.o.requires
	$(MAKE) -f CMakeFiles/screenshot.dir/build.make CMakeFiles/screenshot.dir/excited.cpp.o.provides.build
.PHONY : CMakeFiles/screenshot.dir/excited.cpp.o.provides

CMakeFiles/screenshot.dir/excited.cpp.o.provides.build: CMakeFiles/screenshot.dir/excited.cpp.o


# Object files for target screenshot
screenshot_OBJECTS = \
"CMakeFiles/screenshot.dir/excited.cpp.o"

# External object files for target screenshot
screenshot_EXTERNAL_OBJECTS =

screenshot: CMakeFiles/screenshot.dir/excited.cpp.o
screenshot: CMakeFiles/screenshot.dir/build.make
screenshot: /usr/local/lib/libopencv_cudabgsegm.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudaobjdetect.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudastereo.so.3.3.1
screenshot: /usr/local/lib/libopencv_dnn.so.3.3.1
screenshot: /usr/local/lib/libopencv_ml.so.3.3.1
screenshot: /usr/local/lib/libopencv_shape.so.3.3.1
screenshot: /usr/local/lib/libopencv_stitching.so.3.3.1
screenshot: /usr/local/lib/libopencv_superres.so.3.3.1
screenshot: /usr/local/lib/libopencv_videostab.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudafeatures2d.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudacodec.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudaoptflow.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudalegacy.so.3.3.1
screenshot: /usr/local/lib/libopencv_calib3d.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudawarping.so.3.3.1
screenshot: /usr/local/lib/libopencv_features2d.so.3.3.1
screenshot: /usr/local/lib/libopencv_flann.so.3.3.1
screenshot: /usr/local/lib/libopencv_highgui.so.3.3.1
screenshot: /usr/local/lib/libopencv_objdetect.so.3.3.1
screenshot: /usr/local/lib/libopencv_photo.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudaimgproc.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudafilters.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudaarithm.so.3.3.1
screenshot: /usr/local/lib/libopencv_video.so.3.3.1
screenshot: /usr/local/lib/libopencv_videoio.so.3.3.1
screenshot: /usr/local/lib/libopencv_imgcodecs.so.3.3.1
screenshot: /usr/local/lib/libopencv_imgproc.so.3.3.1
screenshot: /usr/local/lib/libopencv_core.so.3.3.1
screenshot: /usr/local/lib/libopencv_cudev.so.3.3.1
screenshot: CMakeFiles/screenshot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michael/文档/C++Projects/RMCV/ScreenShot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable screenshot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/screenshot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/screenshot.dir/build: screenshot

.PHONY : CMakeFiles/screenshot.dir/build

CMakeFiles/screenshot.dir/requires: CMakeFiles/screenshot.dir/excited.cpp.o.requires

.PHONY : CMakeFiles/screenshot.dir/requires

CMakeFiles/screenshot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/screenshot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/screenshot.dir/clean

CMakeFiles/screenshot.dir/depend:
	cd /home/michael/文档/C++Projects/RMCV/ScreenShot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michael/文档/C++Projects/RMCV/ScreenShot /home/michael/文档/C++Projects/RMCV/ScreenShot /home/michael/文档/C++Projects/RMCV/ScreenShot/cmake-build-debug /home/michael/文档/C++Projects/RMCV/ScreenShot/cmake-build-debug /home/michael/文档/C++Projects/RMCV/ScreenShot/cmake-build-debug/CMakeFiles/screenshot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/screenshot.dir/depend
