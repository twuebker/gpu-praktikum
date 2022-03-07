cmake_minimum_required(VERSION 3.10)
project(gpu_praktikum LANGUAGES CXX CUDA)

set(CMAKE_MODULE_PATH ${gpu_praktikum_SOURCE_DIR}/cmake/ ${CMAKE_MODULE_PATH})

find_package(CUDA 10.2 REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)


add_executable(gpu_praktikum main.cu)

target_link_libraries(gpu_praktikum ${CUDA_LIBRARIES})
target_link_libraries(gpu_praktikum ${SDL2_LIBRARY} ${SDL2_IMG_LIBRARY})
target_link_libraries(gpu_praktikum m)


set_target_properties(gpu_praktikum PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
