project(gpu_praktikum LANGUAGES CXX CUDA)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_MODULE_PATH ${gpu_praktikum_SOURCE_DIR}/cmake/ ${CMAKE_MODULE_PATH})

find_package(CUDA 10.2 REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

set_target_properties(gpu_praktikum PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)

add_executable(gpu_praktikum main.cu)

set_property(TARGET gpu_praktikum PROPERTIES CUDA_SEPERABLE_COMPILATION ON)

target_link_libraries(gpu_praktikum ${CUDA_LIBRARIES})
target_link_libraries(gpu_praktikum ${SDL2_LIBRARY} ${SDL2_IMG_LIBRARY})
target_link_libraries(gpu_praktikum m)


