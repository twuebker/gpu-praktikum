project(GPU LANGUAGES CXX CUDA)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_MODULE_PATH ${GPU_SOURCE_DIR}/cmake/ ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Setup sources
set(GPU_SOURCES
        Main.cu
	AsteroidsScene.cpp
        )

find_package(CUDA 10.2 REQUIRED)
find_package(Qt5 COMPONENTS
	Gui
	Core
	Widgets
	REQUIRED)

add_executable(GPU ${GPU_SOURCES})

set_property(TARGET GPU PROPERTY CUDA_SEPERABLE_COMPILATION ON)

set_target_properties(GPU PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)

#convert the fpic option in Qt5::Core over to INTERFACE_POSITION_INDEPENDENT_CODE
get_property(core_options TARGET Qt5::Core PROPERTY INTERFACE_COMPILE_OPTIONS)
string(REPLACE "-fPIC" "" new_core_options ${core_options})
set_property(TARGET Qt5::Core PROPERTY INTERFACE_COMPILE_OPTIONS ${new_core_options})
set_property(TARGET Qt5::Core PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE "ON")

target_link_libraries(GPU ${CUDA_LIBRARIES})
target_link_libraries(GPU Qt5::Widgets
			  Qt5::Core
			  Qt5::Gui)


