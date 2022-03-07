cmake_minimum_required(VERSION 3.21)
project(gpu_praktikum CUDA)

set(CMAKE_CUDA_STANDARD 17)
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

add_executable(gpu_praktikum main.cu)

target_link_libraries(gpu_praktikum ${SDL2_LIBRARY} ${SDL2_IMG_LIBRARY})

set_target_properties(gpu_praktikum PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
