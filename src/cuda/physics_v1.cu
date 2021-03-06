#define EPS (10)
#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include <thrust/device_vector.h>
#include <stdio.h>
#include "../mess/MessSaver.h"

void __global__ calculate_forces(Asteroid* d_a, float dt, int size, ForceField* d_f, int sizeFF) 	//DelteTime ist die Zeit die zwischen zwei Berechnungen vergeht. Mussen irgendwie
{	
	//in der MainLoop dafür die Zeit stoppen und hier übergeben
	float BIG_G = 9.81; //Gravitationkonstante, aber am Ende voll abhängig wie groß unsere Zahlen so sind
	int astId = blockIdx.x * blockDim.x + threadIdx.x;
	Asteroid* ast;
	if(astId < size) {
	ast = &d_a[astId];
	float2 acc = {0,0}; //Acceleration in x and y direction

	for(int i = 0; i < size; i++){
		if(i == astId) continue; //Keine Gravity zu sich selber

		Asteroid other = d_a[i];
		float2 distance_dir = {ast->pos.first - other.pos.first, ast->pos.second - other.pos.second};
		float distance = sqrt(distance_dir.x * distance_dir.x + distance_dir.y * distance_dir.y); //Pythagoras r = sqrt(x² + y²)
		
		// Bei Distanz gegen 0 geht Kraft gegen unendlich
		// -> Kraft begrenzen durch Softening Faktor EPS
		float soften_dist = sqrt(distance * distance + EPS * EPS);
		float acceleration = -1.0 * BIG_G * other.mass / (soften_dist * soften_dist);
	       	
		float2 distance_dir_unit = {distance_dir.x / soften_dist, distance_dir.y / soften_dist}; //Distance Vector normalisiert (durch Länge geteilt)

		acc.x += acceleration * distance_dir_unit.x;
		acc.y += acceleration * distance_dir_unit.y;	
	}
	
	for(int i = 0; i < sizeFF; i++) {
		ForceField force = d_f[i];
		if(!(ast->pos.first >= force.leftCorner.first && ast->pos.first <= force.rightCorner.first && ast->pos.second >= force.leftCorner.second && ast->pos.second <= force.rightCorner.second)) {
			continue;
		}
		switch(force.dir) {
				case Direction::UP:
						acc.y -= force.force /  ast->mass;
						break;
				case Direction::DOWN:
						acc.y += force.force / ast->mass;
						break;
				case Direction::LEFT:
						acc.x -= force.force / ast->mass;
						break;
				case Direction::RIGHT:
						acc.x += force.force / ast-> mass;		
						break;
				default:
					break;		
		}
	}


		ast->velocity.first += acc.x * dt;
		ast->velocity.second += acc.y * dt;

		ast->pos.first += ast->velocity.first * dt;
		ast->pos.second += ast->velocity.second * dt;
	}
}	

void __global__ updatePositions_v1(Asteroid* d_asteroid, int size, float dt) {
	if(blockIdx.x * blockDim.x + threadIdx.x < size) {
		Asteroid* ast = &d_asteroid[blockIdx.x * blockDim.x + threadIdx.x];
		ast->pos.first = ast->velocity.first;
		ast->pos.second = ast->velocity.second;
	}
}

void call_kernel_v1(std::vector<Asteroid>& asteroids, std::vector<ForceField>& forceFields)
{
	if(asteroids.empty()) {
		return;
	}
    Asteroid* a = asteroids.data();
    Asteroid* d_asteroid;

    ForceField* f = forceFields.data();
    ForceField* d_forceField;
    int size = sizeof(Asteroid) * asteroids.size();
	int sizeFF = sizeof(ForceField) * forceFields.size();

	auto start = std::chrono::steady_clock::now();
    	cudaMalloc(&d_asteroid, size);
	cudaMalloc(&d_forceField, sizeFF);
	
    cudaMemcpy(d_asteroid, a,size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_forceField, f, sizeFF, cudaMemcpyHostToDevice);
	auto end = std::chrono::steady_clock::now();
	float dif = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	MessSaver::add("GPUV1 Hinkopieren", dif);
	start = std::chrono::steady_clock::now();
    calculate_forces<<<std::ceil(asteroids.size() / 256.0), 256>>>(d_asteroid, 0.1, asteroids.size(), d_forceField, forceFields.size());
	
    updatePositions_v1<<<std::ceil(asteroids.size() / 256.0), 256>>>(d_asteroid, asteroids.size(), 0.1);
	end = std::chrono::steady_clock::now();
	dif = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	MessSaver::add("GPUV1 Berechnen", dif);
	start = std::chrono::steady_clock::now();
    cudaMemcpy(a, d_asteroid, size, cudaMemcpyDeviceToHost);
    cudaFree(d_asteroid);
	cudaFree(d_forceField);
	end = std::chrono::steady_clock::now();
	dif = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	MessSaver::add("GPUV1 Zurückkopieren", dif);

}
