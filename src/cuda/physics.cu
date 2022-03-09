#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include "../widgets/AsteroidsScene.h"

__global__ void calculate_forces(void *devX, void *devA)
{
	extern __shared__ float4[] shPosition;
	float4 *globalX = (float4 *)devX;
	float4 *globalA = (float4 *)devA;
	float4 myPosition;
	int i, tile;
	float3 acc = {0.0f, 0.0f, 0.0f};
	int gtid = blockIdx.x * blockDim.x + threadIdx.x;
	myPosition = globalX[gtid];
	for(i=0, tile = 0; i < N; i += p, tile++)
	{
		int idx = tile* blockDim.x + threadIdx.x;
		shPosition[threadIdx.x] = globalX[idx];
		__syncthreads();
		acc = tile_calculation(myPosition, acc);
		__syncthreads();
	}
	float4 acc4 = {acc.x, acc.y, acc.z, 0.0f};
	globalA[gtid] = acc4;
}



float call_kernel() {
	int n = 4;
	int size = 4 * sizeof(float) * n;
	float* h_p = (float*)malloc(size);
	float* h_a = (float*)malloc(size);

	float* d_p;
	float* d_a;
	cudaMalloc(&d_p, size);
	cudaMalloc(&d_a, size);

	cudaMemcpy(d_p, h_p, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);

}
