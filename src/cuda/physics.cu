#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include "../widgets/AsteroidsScene.h"
#include <thrust/device_vector.h>

__global__ calculate_forces(Asteroid* d_a) {
	int astId = blockIdx.x * blockDim.x + threadIdx.x;
	
}	


float call_kernel(std::vector<Asteroid>& asteroids)
{
    Asteroid* a = asteroids.data();
    Asteroid* d_asteroid;
     	

    cudaMalloc(&d_asteroid, sizeof(Asteroid) * asteroids.size());

    cudaMemcpy(d_asteroid, a, sizeof(Asteroid) * asteroids.size(), cudaMemcpyHostToDevice);

    calculate_forces<<<1, n>>>(d_asteroids);

    cudaMemcpy(h_p, d_p, size, cudaMemcpyDeviceToHost);
    cudaMemcpy(h_a, d_a, sizeA, cudaMemcpyDeviceToHost);

    std::cout << "Ergebnis: " << std::endl;
    for (int i = 0; i<4; i++)
    {
        std::cout << h_p[i] << " " << h_a[i] << std::endl;
    }
}
