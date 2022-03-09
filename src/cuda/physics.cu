#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include "../widgets/AsteroidsScene.h"

__global__ void calculate_forces(Asteroid *asteroids) {
	
}

float call_kernel() {
	int n = 4;
	float* h_p = (float*)malloc(4 * sizeof(float) * n);
	float* h_a = (float*)malloc(3 * sizeof(float) * n);

	float* d_p;
	float* d_a;
	cudaMalloc(&d_p, 4 * sizeof(float) * n);
	cudaMalloc(&d_a, 4 * sizeof(float) * n);

	
}
