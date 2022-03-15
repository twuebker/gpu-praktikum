#define EPS (10)
#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include <thrust/device_vector.h>
#include <stdio.h>

void __global__ calculate_forces(Asteroid* d_a, float dt, int size, ForceField* d_f, int sizeFF) 	//DelteTime ist die Zeit die zwischen zwei Berechnungen vergeht. Mussen irgendwie
{	
	//in der MainLoop dafür die Zeit stoppen und hier übergeben
	float BIG_G = 9.81; //Gravitationkonstante, aber am Ende voll abhängig wie groß unsere Zahlen so sind
	int astId = blockIdx.x * blockDim.x + threadIdx.x;
	Asteroid* ast = &d_a[astId];
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
	__syncthreads(); //Synchronisiert alle Threads im Block. Können also so doch nur einen Block haben da sonst
                        //die späteren Blocke mit veränderten Daten arbeiten


	ast->velocity.first += acc.x * dt;
	ast->velocity.second += acc.y * dt;

	//printf("wert der draufkommt: %f, %f\n", ast->velocity.first * dt, ast->velocity.second * dt);
	ast->pos.first += ast->velocity.first * dt;
	ast->pos.second += ast->velocity.second * dt;

}	

void call_kernel(std::vector<Asteroid>& asteroids, std::vector<ForceField>& forceFields)
{
	std::cout << "Begin" << std::endl;
	if(asteroids.empty()) {
		return;
	}
    Asteroid* a = asteroids.data();
    Asteroid* d_asteroid;

    ForceField* f = forceFields.data();
    ForceField* d_forceField;
    std::cout << "MOIN" << std::endl;
    int size = sizeof(Asteroid) * asteroids.size();
	int sizeFF = sizeof(ForceField) * forceFields.size();
    cudaMalloc(&d_asteroid, size);
	cudaMalloc(&d_forceField, sizeFF);
	
    cudaMemcpy(d_asteroid, a,size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_forceField, f, sizeFF, cudaMemcpyHostToDevice);
	std::cout << "HALLO" << std::endl;
    calculate_forces<<<1, asteroids.size()>>>(d_asteroid, 0.1, asteroids.size(), d_forceField, forceFields.size());
	std::cout << "ALLES GECALCT" << std::endl;
    cudaMemcpy(a, d_asteroid, size, cudaMemcpyDeviceToHost);
	std::cout << "HI" << std::endl;
    cudaFree(d_asteroid);
	cudaFree(d_forceField);
	std::cout << "FERTIG" << std::endl;
}
