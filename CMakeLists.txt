cmake_minimum_required(VERSION 3.21)
project(gpu_praktikum CUDA)

set(CMAKE_CUDA_STANDARD 17)

add_executable(gpu_praktikum main.cu)

set_target_properties(gpu_praktikum PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
