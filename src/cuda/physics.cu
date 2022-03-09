#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include "../widgets/AsteroidsScene.h"

__device__ float3 tile_calculation(float4 myPosition, float3 accel)
{
    int i;
    extern __shared__ float4[] shPosition;
    for (i = 0; i < blockDim.x; i++) 
    {
        accel = bodyBodyInteraction(myPosition, shPosition[i], accel);
    }
    return accel; 
}

__device__ float3 bodyBodyInteraction(float4 bi, float4 bj, float3 ai) 
{
    float3 r;
       // r_ij  [3 FLOPS]
    r.x = bj.x - bi.x;
       r.y = bj.y - bi.y;
       r.z = bj.z - bi.z;
       // distSqr = dot(r_ij, r_ij) + EPS^2  [6 FLOPS]
        float distSqr = r.x * r.x + r.y * r.y + r.z * r.z + EPS2;
       // invDistCube =1/distSqr^(3/2)  [4 FLOPS (2 mul, 1 sqrt, 1 inv)]
        float distSixth = distSqr * distSqr * distSqr;
       float invDistCube = 1.0f/sqrtf(distSixth);
       // s = m_j * invDistCube [1 FLOP]
        float s = bj.w * invDistCube;
       // a_i =  a_i + s * r_ij [6 FLOPS]
       ai.x += r.x * s;
       ai.y += r.y * s;
    ai.z += r.z * s;
    return ai;
}

__global__ void calculate_forces(void *devX, void *devA)
{
	extern __shared__ float4[] shPosition;
	float4 *globalX = (float4 *)devX;
	float4 *globalA = (float4 *)devA;
	float4 myPosition;
	int i, tile;
	int p = 1;
	int N = 4;
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
	int sizeA = 3 * sizeof(float) * n;
	float* h_p = (float*)malloc(size);
	float* h_a = (float*)malloc(sizeA);


	for(int i = 0; i < 4; i++) {
		h_p[i] = i;
		h_a[i] = i;
	}
	float* d_p;
	float* d_a;
	cudaMalloc(&d_p, size);
	cudaMalloc(&d_a, sizeA);

	cudaMemcpy(d_p, h_p, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_a, h_a, sizeA, cudaMemcpyHostToDevice);
	
	calculate_forces<<<1,n,n>>>(d_p, d_a);

	cudaMemcpy(h_p, d_p, size, cudaMemcpyDeviceToHost);
	cudaMemcpy(h_a, d_a, sizeA, cudaMemcpyDeviceToHost);

	std::cout << "Ergebnis: " << std::endl;
	for(int i = 0; i < 4; i++) {
		std::cout << h_p[i] << " " << h_a[i] << std::endl;
	}
}
