# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/nithin/data/dev/godseye

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nithin/data/dev/godseye/build

# Include any dependencies generated for this target.
include CMakeFiles/godseye.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/godseye.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/godseye.dir/flags.make

CMakeFiles/godseye.dir/main.cpp.o: CMakeFiles/godseye.dir/flags.make
CMakeFiles/godseye.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nithin/data/dev/godseye/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/godseye.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/godseye.dir/main.cpp.o -c /home/nithin/data/dev/godseye/main.cpp

CMakeFiles/godseye.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/godseye.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nithin/data/dev/godseye/main.cpp > CMakeFiles/godseye.dir/main.cpp.i

CMakeFiles/godseye.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/godseye.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nithin/data/dev/godseye/main.cpp -o CMakeFiles/godseye.dir/main.cpp.s

CMakeFiles/godseye.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/godseye.dir/main.cpp.o.requires

CMakeFiles/godseye.dir/main.cpp.o.provides: CMakeFiles/godseye.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/godseye.dir/build.make CMakeFiles/godseye.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/godseye.dir/main.cpp.o.provides

CMakeFiles/godseye.dir/main.cpp.o.provides.build: CMakeFiles/godseye.dir/main.cpp.o

CMakeFiles/godseye.dir/color_constancy.cpp.o: CMakeFiles/godseye.dir/flags.make
CMakeFiles/godseye.dir/color_constancy.cpp.o: ../color_constancy.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nithin/data/dev/godseye/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/godseye.dir/color_constancy.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/godseye.dir/color_constancy.cpp.o -c /home/nithin/data/dev/godseye/color_constancy.cpp

CMakeFiles/godseye.dir/color_constancy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/godseye.dir/color_constancy.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nithin/data/dev/godseye/color_constancy.cpp > CMakeFiles/godseye.dir/color_constancy.cpp.i

CMakeFiles/godseye.dir/color_constancy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/godseye.dir/color_constancy.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nithin/data/dev/godseye/color_constancy.cpp -o CMakeFiles/godseye.dir/color_constancy.cpp.s

CMakeFiles/godseye.dir/color_constancy.cpp.o.requires:
.PHONY : CMakeFiles/godseye.dir/color_constancy.cpp.o.requires

CMakeFiles/godseye.dir/color_constancy.cpp.o.provides: CMakeFiles/godseye.dir/color_constancy.cpp.o.requires
	$(MAKE) -f CMakeFiles/godseye.dir/build.make CMakeFiles/godseye.dir/color_constancy.cpp.o.provides.build
.PHONY : CMakeFiles/godseye.dir/color_constancy.cpp.o.provides

CMakeFiles/godseye.dir/color_constancy.cpp.o.provides.build: CMakeFiles/godseye.dir/color_constancy.cpp.o

# Object files for target godseye
godseye_OBJECTS = \
"CMakeFiles/godseye.dir/main.cpp.o" \
"CMakeFiles/godseye.dir/color_constancy.cpp.o"

# External object files for target godseye
godseye_EXTERNAL_OBJECTS =

godseye: CMakeFiles/godseye.dir/main.cpp.o
godseye: CMakeFiles/godseye.dir/color_constancy.cpp.o
godseye: CMakeFiles/godseye.dir/build.make
godseye: /usr/local/lib/libopencv_viz.so.2.4.10
godseye: /usr/local/lib/libopencv_videostab.so.2.4.10
godseye: /usr/local/lib/libopencv_video.so.2.4.10
godseye: /usr/local/lib/libopencv_ts.a
godseye: /usr/local/lib/libopencv_superres.so.2.4.10
godseye: /usr/local/lib/libopencv_stitching.so.2.4.10
godseye: /usr/local/lib/libopencv_photo.so.2.4.10
godseye: /usr/local/lib/libopencv_ocl.so.2.4.10
godseye: /usr/local/lib/libopencv_objdetect.so.2.4.10
godseye: /usr/local/lib/libopencv_nonfree.so.2.4.10
godseye: /usr/local/lib/libopencv_ml.so.2.4.10
godseye: /usr/local/lib/libopencv_legacy.so.2.4.10
godseye: /usr/local/lib/libopencv_imgproc.so.2.4.10
godseye: /usr/local/lib/libopencv_highgui.so.2.4.10
godseye: /usr/local/lib/libopencv_gpu.so.2.4.10
godseye: /usr/local/lib/libopencv_flann.so.2.4.10
godseye: /usr/local/lib/libopencv_features2d.so.2.4.10
godseye: /usr/local/lib/libopencv_core.so.2.4.10
godseye: /usr/local/lib/libopencv_contrib.so.2.4.10
godseye: /usr/local/lib/libopencv_calib3d.so.2.4.10
godseye: /usr/lib/x86_64-linux-gnu/libGLU.so
godseye: /usr/lib/x86_64-linux-gnu/libGL.so
godseye: /usr/lib/x86_64-linux-gnu/libSM.so
godseye: /usr/lib/x86_64-linux-gnu/libICE.so
godseye: /usr/lib/x86_64-linux-gnu/libX11.so
godseye: /usr/lib/x86_64-linux-gnu/libXext.so
godseye: /usr/local/lib/libopencv_nonfree.so.2.4.10
godseye: /usr/local/lib/libopencv_ocl.so.2.4.10
godseye: /usr/local/lib/libopencv_gpu.so.2.4.10
godseye: /usr/local/lib/libopencv_photo.so.2.4.10
godseye: /usr/local/lib/libopencv_objdetect.so.2.4.10
godseye: /usr/local/lib/libopencv_legacy.so.2.4.10
godseye: /usr/local/lib/libopencv_video.so.2.4.10
godseye: /usr/local/lib/libopencv_ml.so.2.4.10
godseye: /usr/local/lib/libopencv_calib3d.so.2.4.10
godseye: /usr/local/lib/libopencv_features2d.so.2.4.10
godseye: /usr/local/lib/libopencv_highgui.so.2.4.10
godseye: /usr/local/lib/libopencv_imgproc.so.2.4.10
godseye: /usr/local/lib/libopencv_flann.so.2.4.10
godseye: /usr/local/lib/libopencv_core.so.2.4.10
godseye: CMakeFiles/godseye.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable godseye"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/godseye.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/godseye.dir/build: godseye
.PHONY : CMakeFiles/godseye.dir/build

CMakeFiles/godseye.dir/requires: CMakeFiles/godseye.dir/main.cpp.o.requires
CMakeFiles/godseye.dir/requires: CMakeFiles/godseye.dir/color_constancy.cpp.o.requires
.PHONY : CMakeFiles/godseye.dir/requires

CMakeFiles/godseye.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/godseye.dir/cmake_clean.cmake
.PHONY : CMakeFiles/godseye.dir/clean

CMakeFiles/godseye.dir/depend:
	cd /home/nithin/data/dev/godseye/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nithin/data/dev/godseye /home/nithin/data/dev/godseye /home/nithin/data/dev/godseye/build /home/nithin/data/dev/godseye/build /home/nithin/data/dev/godseye/build/CMakeFiles/godseye.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/godseye.dir/depend

