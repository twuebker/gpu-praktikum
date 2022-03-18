#include <cmath>
#include <string>
#include <iostream>
#include <chrono>
#include <cuda.h>
#include <cuda_runtime.h>
#include "../data/data.h"
#include "../cuda/physics_v1.cu"
#include "../cuda/physics_v2.cu"
#include "../cuda/physics_v3.cu"
#include "CPU.cpp"

void cpu_v1(std::vector<Asteroid> asteroids, std::vector<ForceField> forceFields, int iterations){
        auto start = std::chrono::steady_clock::now();
	for(int i = 0; i < iterations; i++){
                cpu(asteroids, forceFields);
        }
	auto end = std::chrono::steady_clock::now();
	std::cout << "CPU took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / iterations << " Microseconds per Iteration." << std::endl;
}

void gpu_v1(std::vector<Asteroid> asteroids, std::vector<ForceField> forceFields, int iterations){
        auto start = std::chrono::steady_clock::now();
	for(int i = 0; i < iterations; i++){
                call_kernel_v1(asteroids, forceFields);
        }
	auto end = std::chrono::steady_clock::now();
        std::cout << "GPUV1 took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / iterations << " Microseconds per Iteration." << std::endl;
}

void gpu_v2(std::vector<Asteroid> asteroids, std::vector<ForceField> forceFields, int iterations){
	auto start = std::chrono::steady_clock::now();
	std::pair<Asteroid*, ForceField*> data = updateMemory_v2(asteroids, forceFields);
	Asteroid* ast = data.first;
	ForceField* fields = data.second;
	for(int i = 0; i < iterations; i++){
		call_kernel_v2(asteroids.data(), ast, fields, asteroids.size(), forceFields.size()); 
	}
	auto end = std::chrono::steady_clock::now();
        std::cout << "GPUV2 took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / iterations << " Microsecondper Iteration." << std::endl;
}

void gpu_v3(std::vector<Asteroid> asteroids, std::vector<ForceField> forceFields, int iterations) {
	auto start = std::chrono::steady_clock::now();
	std::tuple<Asteroid*, ForceField*, float2*> data = updateMemory_v3(asteroids, forceFields);
        Asteroid* ast = std::get<0>(data);
        ForceField* fields = std::get<1>(data);
	float2* accs = std::get<2>(data);
        for(int i = 0; i < iterations; i++){
                call_kernel_v3(asteroids.data(), ast, fields, asteroids.size(), forceFields.size(), accs);
        }
	auto end = std::chrono::steady_clock::now();
        std::cout << "GPUV3 took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / iterations << " Microseconds per Iteration." << std::endl;
}



void print_asteroids(std::vector<Asteroid> asteroids){
        for(int i = 0; i < asteroids.size(); i++){
                Asteroid ast = asteroids[i];
                std::cout << i << ": " << ast.pos.first << " , " << ast.pos.second <<std::endl;
    	}       
}   

int main(int argc, char* argv[]){
	if(argc != 3) return -1;

	auto asteroids = std::vector<Asteroid>();
        auto forceFields = std::vector<ForceField>();
	
	int num = std::stoi(std::string(argv[2]));
	int iterations = 100;

	for(float i = 0; i < num; i++) {
		Asteroid ast;
		ast.pos.first = cos(i / num * 2 * atan(1)*4) * 200;
		ast.pos.second = sin(i / num * 2 * atan(1)*4) * 200;
		ast.velocity.first = 0.0;
		ast.velocity.second = 0.0;
		ast.mass = 10.0;
		asteroids.push_back(ast);	

	}

	
	

			
	if(std::string(argv[1]) == "CPU"){
		cpu_v1(asteroids, forceFields, iterations);
	} else if(std::string(argv[1]) == "GPUV1"){
		gpu_v1(asteroids, forceFields, iterations);
	} else if(std::string(argv[1]) == "GPUV2"){
		gpu_v2(asteroids, forceFields, iterations);
	} else if(std::string(argv[1]) == "GPUV3")	{
		gpu_v3(asteroids, forceFields, iterations);
	} else if(std::string(argv[1]) == "ALL") {
		
		cpu_v1(asteroids, forceFields, iterations);
		
		gpu_v1(asteroids, forceFields, iterations);

		gpu_v2(asteroids, forceFields, iterations);

		gpu_v3(asteroids, forceFields, iterations);
	}


	return 1;

}

