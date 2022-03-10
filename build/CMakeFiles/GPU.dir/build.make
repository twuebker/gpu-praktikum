# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/theo/gpu-praktikum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/theo/gpu-praktikum/build

# Include any dependencies generated for this target.
include CMakeFiles/GPU.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GPU.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GPU.dir/flags.make

CMakeFiles/GPU.dir/src/app/Main.cpp.o: CMakeFiles/GPU.dir/flags.make
CMakeFiles/GPU.dir/src/app/Main.cpp.o: ../src/app/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/gpu-praktikum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CUDA object CMakeFiles/GPU.dir/src/app/Main.cpp.o"
	/usr/local/cuda/bin/nvcc  $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -x cu -dc /home/theo/gpu-praktikum/src/app/Main.cpp -o CMakeFiles/GPU.dir/src/app/Main.cpp.o

CMakeFiles/GPU.dir/src/app/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CUDA source to CMakeFiles/GPU.dir/src/app/Main.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

CMakeFiles/GPU.dir/src/app/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CUDA source to assembly CMakeFiles/GPU.dir/src/app/Main.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

CMakeFiles/GPU.dir/src/app/Main.cpp.o.requires:

.PHONY : CMakeFiles/GPU.dir/src/app/Main.cpp.o.requires

CMakeFiles/GPU.dir/src/app/Main.cpp.o.provides: CMakeFiles/GPU.dir/src/app/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GPU.dir/build.make CMakeFiles/GPU.dir/src/app/Main.cpp.o.provides.build
.PHONY : CMakeFiles/GPU.dir/src/app/Main.cpp.o.provides

CMakeFiles/GPU.dir/src/app/Main.cpp.o.provides.build: CMakeFiles/GPU.dir/src/app/Main.cpp.o


CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o: CMakeFiles/GPU.dir/flags.make
CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o: ../src/widgets/AsteroidsScene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/gpu-praktikum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CUDA object CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o"
	/usr/local/cuda/bin/nvcc  $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -x cu -dc /home/theo/gpu-praktikum/src/widgets/AsteroidsScene.cpp -o CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o

CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CUDA source to CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CUDA source to assembly CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o.requires:

.PHONY : CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o.requires

CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o.provides: CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o.requires
	$(MAKE) -f CMakeFiles/GPU.dir/build.make CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o.provides.build
.PHONY : CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o.provides

CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o.provides.build: CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o


CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o: CMakeFiles/GPU.dir/flags.make
CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o: ../src/app/GuiMainWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/gpu-praktikum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CUDA object CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o"
	/usr/local/cuda/bin/nvcc  $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -x cu -dc /home/theo/gpu-praktikum/src/app/GuiMainWindow.cpp -o CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o

CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CUDA source to CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CUDA source to assembly CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o.requires:

.PHONY : CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o.requires

CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o.provides: CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o.requires
	$(MAKE) -f CMakeFiles/GPU.dir/build.make CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o.provides.build
.PHONY : CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o.provides

CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o.provides.build: CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o


CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o: CMakeFiles/GPU.dir/flags.make
CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o: ../src/widgets/AsteroidPixmapItem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/gpu-praktikum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o -c /home/theo/gpu-praktikum/src/widgets/AsteroidPixmapItem.cpp

CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/theo/gpu-praktikum/src/widgets/AsteroidPixmapItem.cpp > CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.i

CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/theo/gpu-praktikum/src/widgets/AsteroidPixmapItem.cpp -o CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.s

CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o.requires:

.PHONY : CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o.requires

CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o.provides: CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o.requires
	$(MAKE) -f CMakeFiles/GPU.dir/build.make CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o.provides.build
.PHONY : CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o.provides

CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o.provides.build: CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o


CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o: CMakeFiles/GPU.dir/flags.make
CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o: GPU_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/gpu-praktikum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o -c /home/theo/gpu-praktikum/build/GPU_autogen/mocs_compilation.cpp

CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/theo/gpu-praktikum/build/GPU_autogen/mocs_compilation.cpp > CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.i

CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/theo/gpu-praktikum/build/GPU_autogen/mocs_compilation.cpp -o CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.s

CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o.requires:

.PHONY : CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o.requires

CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o.provides: CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f CMakeFiles/GPU.dir/build.make CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o.provides

CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o.provides.build: CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o


CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o: CMakeFiles/GPU.dir/flags.make
CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o: GPU_autogen/EWIEGA46WW/qrc_res.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/gpu-praktikum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o -c /home/theo/gpu-praktikum/build/GPU_autogen/EWIEGA46WW/qrc_res.cpp

CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/theo/gpu-praktikum/build/GPU_autogen/EWIEGA46WW/qrc_res.cpp > CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.i

CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/theo/gpu-praktikum/build/GPU_autogen/EWIEGA46WW/qrc_res.cpp -o CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.s

CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o.requires:

.PHONY : CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o.requires

CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o.provides: CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o.requires
	$(MAKE) -f CMakeFiles/GPU.dir/build.make CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o.provides.build
.PHONY : CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o.provides

CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o.provides.build: CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o


# Object files for target GPU
GPU_OBJECTS = \
"CMakeFiles/GPU.dir/src/app/Main.cpp.o" \
"CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o" \
"CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o" \
"CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o" \
"CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o"

# External object files for target GPU
GPU_EXTERNAL_OBJECTS =

CMakeFiles/GPU.dir/cmake_device_link.o: CMakeFiles/GPU.dir/src/app/Main.cpp.o
CMakeFiles/GPU.dir/cmake_device_link.o: CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o
CMakeFiles/GPU.dir/cmake_device_link.o: CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o
CMakeFiles/GPU.dir/cmake_device_link.o: CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o
CMakeFiles/GPU.dir/cmake_device_link.o: CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o
CMakeFiles/GPU.dir/cmake_device_link.o: CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o
CMakeFiles/GPU.dir/cmake_device_link.o: CMakeFiles/GPU.dir/build.make
CMakeFiles/GPU.dir/cmake_device_link.o: /usr/local/cuda/lib64/libcudart_static.a
CMakeFiles/GPU.dir/cmake_device_link.o: /usr/lib/aarch64-linux-gnu/librt.so
CMakeFiles/GPU.dir/cmake_device_link.o: /usr/lib/aarch64-linux-gnu/libQt5Widgets.so.5.9.5
CMakeFiles/GPU.dir/cmake_device_link.o: /usr/lib/aarch64-linux-gnu/libQt5Gui.so.5.9.5
CMakeFiles/GPU.dir/cmake_device_link.o: /usr/lib/aarch64-linux-gnu/libQt5Core.so.5.9.5
CMakeFiles/GPU.dir/cmake_device_link.o: CMakeFiles/GPU.dir/dlink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/theo/gpu-praktikum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CUDA device code CMakeFiles/GPU.dir/cmake_device_link.o"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GPU.dir/dlink.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GPU.dir/build: CMakeFiles/GPU.dir/cmake_device_link.o

.PHONY : CMakeFiles/GPU.dir/build

# Object files for target GPU
GPU_OBJECTS = \
"CMakeFiles/GPU.dir/src/app/Main.cpp.o" \
"CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o" \
"CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o" \
"CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o" \
"CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o"

# External object files for target GPU
GPU_EXTERNAL_OBJECTS =

GPU: CMakeFiles/GPU.dir/src/app/Main.cpp.o
GPU: CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o
GPU: CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o
GPU: CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o
GPU: CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o
GPU: CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o
GPU: CMakeFiles/GPU.dir/build.make
GPU: /usr/local/cuda/lib64/libcudart_static.a
GPU: /usr/lib/aarch64-linux-gnu/librt.so
GPU: /usr/lib/aarch64-linux-gnu/libQt5Widgets.so.5.9.5
GPU: /usr/lib/aarch64-linux-gnu/libQt5Gui.so.5.9.5
GPU: /usr/lib/aarch64-linux-gnu/libQt5Core.so.5.9.5
GPU: CMakeFiles/GPU.dir/cmake_device_link.o
GPU: CMakeFiles/GPU.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/theo/gpu-praktikum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable GPU"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GPU.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GPU.dir/build: GPU

.PHONY : CMakeFiles/GPU.dir/build

CMakeFiles/GPU.dir/requires: CMakeFiles/GPU.dir/src/app/Main.cpp.o.requires
CMakeFiles/GPU.dir/requires: CMakeFiles/GPU.dir/src/widgets/AsteroidsScene.cpp.o.requires
CMakeFiles/GPU.dir/requires: CMakeFiles/GPU.dir/src/app/GuiMainWindow.cpp.o.requires
CMakeFiles/GPU.dir/requires: CMakeFiles/GPU.dir/src/widgets/AsteroidPixmapItem.cpp.o.requires
CMakeFiles/GPU.dir/requires: CMakeFiles/GPU.dir/GPU_autogen/mocs_compilation.cpp.o.requires
CMakeFiles/GPU.dir/requires: CMakeFiles/GPU.dir/GPU_autogen/EWIEGA46WW/qrc_res.cpp.o.requires

.PHONY : CMakeFiles/GPU.dir/requires

CMakeFiles/GPU.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GPU.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GPU.dir/clean

CMakeFiles/GPU.dir/depend:
	cd /home/theo/gpu-praktikum/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/theo/gpu-praktikum /home/theo/gpu-praktikum /home/theo/gpu-praktikum/build /home/theo/gpu-praktikum/build /home/theo/gpu-praktikum/build/CMakeFiles/GPU.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GPU.dir/depend
