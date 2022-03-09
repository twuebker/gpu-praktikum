#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include <AsteroidsScene.h>

__global__ void calc_asteroid_physics(void) {
	
}

float call_kernel(std::vector<Asteroid>& asteroids) {
	Asteroid* a = asteroids.data();
    Asteroid* dA;
    cudaMalloc(&da, sizeof(Asteroid) * asteroids.size())
	calc_asteroid_physics<<<1, 1>>>();

	
}
