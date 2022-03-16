#include <cmath>
#include <string>
#include <iostream>
#include <chrono>
#include "../data/data.h"
#include "../cuda/physics_v1.cu"
#include "CPU.cpp"

void print_asteroids(std::vector<Asteroid> asteroids){
        for(int i = 0; i < asteroids.size(); i++){
                Asteroid ast = asteroids[i];
                std::cout << i << ": " << ast.pos.first << " , " << ast.pos.second <<std::endl;
    	}       
}   

int main(int argc, char* argv[]){
	auto asteroids = std::vector<Asteroid>();
        auto forceFields = std::vector<ForceField>();
	
	int num = 100000;
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
	
	for(int i = 0; i < iterations; i++){
		if(std::string(argv[1]) == "CPU"){
			cpu(asteroids, forceFields);
		} else if(std::string(argv[1]) == "GPU"){
			call_kernel_v1(asteroids, forceFields);
		}
	}

	auto end = std::chrono::steady_clock::now();

	std::cout << "Calculation took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / iterations << " microseconds each." << std::endl;



}

