project(GPU LANGUAGES CXX CUDA)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_MODULE_PATH ${GPU_SOURCE_DIR}/cmake/ ${CMAKE_MODULE_PATH})

# Setup sources
set(GPU_SOURCES
        MainWindow.cu
        Main.cu
        )

find_package(CUDA 10.2 REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

add_executable(GPU ${GPU_SOURCES})

set_property(TARGET GPU PROPERTY CUDA_SEPERABLE_COMPILATION ON)

set_target_properties(GPU PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)

set_property(TARGET GPU
        PROPERTY
        BUILD_RPATH ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})

target_link_libraries(GPU ${CUDA_LIBRARIES})
target_link_libraries(GPU ${SDL2_LIBRARY} ${SDL2_IMG_LIBRARY})
target_link_libraries(GPU m)


