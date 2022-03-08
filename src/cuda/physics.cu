#include <cuda.h>
#include <cuda_runtime.h>

__global__ void mein_op_kernel(void) {
	
}

float call_kernel(float a, float b) {

	mein_op_kernel<<<1, 1>>>();

	return a + b;
}
