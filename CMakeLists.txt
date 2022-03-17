project(GPU LANGUAGES CXX CUDA)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_MODULE_PATH ${GPU_SOURCE_DIR}/cmake/ ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

# Setup sources
set(GPU_SOURCES
        src/app/Main.cpp
	src/widgets/AsteroidsScene.cpp
	src/app/GuiMainWindow.cpp
	src/widgets/AsteroidPixmapItem.cpp
	src/widgets/ForceFieldPixmapItem.cpp
	src/widgets/MassSlider.cpp
	src/app/CreateForceFieldDialog.cpp
	)

find_package(CUDA 10.2 REQUIRED)
find_package(Qt5 COMPONENTS
	Gui
	Core
	Widgets
	REQUIRED)

add_executable(GPU ${GPU_SOURCES} res.qrc)

set(MESS_SOURCES 
	src/mess/Main.cpp
	)

add_executable(MESS ${MESS_SOURCES})

set_property(TARGET GPU PROPERTY CUDA_SEPERABLE_COMPILATION ON)
set_property(TARGET MESS PROPERTY CUDA_SEPERABLE_COMPILATION ON)

set_target_properties(GPU PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
set_source_files_properties(src/app/Main.cpp src/app/GuiMainWindow.cpp src/widgets/AsteroidsScene.cpp src/cuda/physics_v1.cu src/cuda/physics_v2.cu src/cuda/physics_v3.cu PROPERTIES LANGUAGE CUDA)

set_target_properties(MESS PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
set_source_files_properties(src/mess/Main.cpp PROPERTIES LANGUAGE CUDA)



#convert the fpic option in Qt5::Core over to INTERFACE_POSITION_INDEPENDENT_CODE
get_property(core_options TARGET Qt5::Core PROPERTY INTERFACE_COMPILE_OPTIONS)
string(REPLACE "-fPIC" "" new_core_options ${core_options})
set_property(TARGET Qt5::Core PROPERTY INTERFACE_COMPILE_OPTIONS ${new_core_options})
set_property(TARGET Qt5::Core PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE "ON")

target_link_libraries(GPU ${CUDA_LIBRARIES})
target_link_libraries(GPU Qt5::Widgets
			  Qt5::Core
			  Qt5::Gui)

target_link_libraries(MESS ${CUDA_LIBRARIES})
target_link_libraries(MESS Qt5::Widgets
                          Qt5::Core
                          Qt5::Gui)

