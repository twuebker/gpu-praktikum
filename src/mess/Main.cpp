#include <cmath>
#include <string>
#include <iostream>
#include <chrono>
#include "../data/data.h"
#include "../cuda/physics_v1.cu"
#include "../cuda/physics_v2.cu"
#include "CPU.cpp"

void cpu_v1(std::vector<Asteroid>& asteroids, std::vector<ForceField>& forceFields, int iterations){
        for(int i = 0; i < iterations; i++){
                cpu(asteroids, forceFields);
        }
}

void gpu_v1(std::vector<Asteroid>& asteroids, std::vector<ForceField>& forceFields, int iterations){
        for(int i = 0; i < iterations; i++){
                call_kernel_v1(asteroids, forceFields);
        }
}

void gpu_v2(std::vector<Asteroid>& asteroids, std::vector<ForceField>& forceFields, int iterations){
	std::pair<Asteroid*, ForceField*> data = updateMemory(asteroids, forceFields);
	Asteroid* ast = data.first;
	ForceField* fields = data.second;
	
	for(int i = 0; i < iterations; i++){
		call_kernel_v2(asteroids.data(), ast, fields, asteroids.size(), forceFields.size()); 
	}
}



void print_asteroids(std::vector<Asteroid> asteroids){
        for(int i = 0; i < asteroids.size(); i++){
                Asteroid ast = asteroids[i];
                std::cout << i << ": " << ast.pos.first << " , " << ast.pos.second <<std::endl;
    	}       
}   

int main(int argc, char* argv[]){
	if(argc != 3) return;

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

	print_asteroids(asteroids);
	
	auto start = std::chrono::steady_clock::now();
	

			
	if(std::string(argv[1]) == "CPU"){
		cpu_v1(asteroids, forceFields, iterations);
	} else if(std::string(argv[1]) == "GPU"){
		gpu_v1(asteroids, forceFields, iterations);
	} else if(std::string(argv[1]) == "GPUV2"){
		gpu_v2(asteroids, forceFields, iterations);
	}
	

	auto end = std::chrono::steady_clock::now();

	std::cout << "Calculation took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / iterations << " microseconds each." << std::endl;

	return 1;

}

