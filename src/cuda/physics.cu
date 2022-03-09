#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include "../widgets/AsteroidsScene.h"
#include <thrust/device_vector.h>

void __global__ calculate_forces(Asteroid* d_a, float dt) 	//DelteTime ist die Zeit die zwischen zwei Berechnungen vergeht. Mussen irgendwie
{								//in der MainLoop dafür die Zeit stoppen und hier übergeben
	float BIG_G = 9.81; //Gravitationkonstante, aber am Ende voll abhängig wie groß unsere Zahlen so sind
	int astId = blockIdx.x * blockDim.x + threadIdx.x;
	Asteroid ast = d_a[astId];
	float2 acc = {0,0}; //Acceleration in x and y direction

	for(int i = 0; i < 4 /* asteroids.size() einfach übergeben?? */; i++){
		if(i == astId) continue; //Keine Gravity zu sich selber

		Asteroid other = d_a[i];
		float3 distance_dir = {ast.pos.first - other.pos.first, ast.pos.second - other.pos.second};
		float distance = sqrt(distance_dir.x * distance_dir.x + distance_dir.y * distance_dir.y); //Pythagoras r = sqrt(x² + y²)
		float acceleration = -1.0 * BIG_G * other.mass / (distance * distance);
	       	float2 distance_dir_unit = {distance_dir.x / distance, distance_dir.y / distance}; //Distance Vector normalisiert (durch Länge geteilt)

		acc.x += acceleration * distance_dir_unit.x;
		acc.y += acceleration * distance_dir_unit.y;	
	}

	__syncthreads(); //Synchronisiert alle Threads im Block. Können also so doch nur einen Block haben da sonst
                        //die späteren Blocke mit veränderten Daten arbeiten


	ast.velocity.first = acc.x * dt;
	ast.velocity.second = acc.y * dt;

	ast.pos.first = ast.velocity.first * dt;
	ast.pos.second = ast.velocity.second * dt;

}	


float call_kernel(std::vector<Asteroid>& asteroids)
{
    Asteroid* a = asteroids.data();
    Asteroid* d_asteroid;
     	
    int size = sizeof(Asteroid) * asteroids.size();

    cudaMalloc(&d_asteroid, size);

    cudaMemcpy(d_asteroid, a,size, cudaMemcpyHostToDevice);

    calculate_forces<<<1, asteroids.size()>>>(d_asteroid, 0.1);  //Wollen wir hier den Pointer oder direkt einen Vector übergeben??

    cudaMemcpy(a, d_asteroid, size, cudaMemcpyDeviceToHost);
	    
    
}
