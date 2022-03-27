#define EPS (10)
#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include <utility>
#include <thrust/device_vector.h>
#include <stdio.h>

#define blockSize  16
#define blockFloat 16.0

void __global__ calculate_forces_v3(Asteroid* d_a, float dt, int size, ForceField* d_f,
        int sizeFF, float2* accs)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;
    
    Asteroid* asteroidI;
    Asteroid* asteroidJ;
    if(i < size && j < size) {
	   
    	asteroidI = &d_a[i];
    	asteroidJ = &d_a[j];

    float BIG_G = 9.81; //Gravitationkonstante, aber am Ende voll abhängig wie groß unsere Zahlen so sind
    float2 acc = {0, 0}; //Acceleration in x and y direction

    if (i!=j)
    {

        float2 distance_dir = {asteroidI->pos.first-asteroidJ->pos.first, asteroidI->pos.second-asteroidJ->pos.second};
        float distance = sqrt(
                distance_dir.x*distance_dir.x+distance_dir.y*distance_dir.y); //Pythagoras r = sqrt(x² + y²)

        // Bei Distanz gegen 0 geht Kraft gegen unendlich
        // -> Kraft begrenzen durch Softening Faktor EPS
        float soften_dist = sqrt(distance*distance+EPS*EPS);
        float acceleration = -1.0*BIG_G*asteroidJ->mass/(soften_dist*soften_dist);
        float2 distance_dir_unit = {distance_dir.x/soften_dist,
                                    distance_dir.y/soften_dist}; //Distance Vector normalisiert (durch Länge geteilt)

        acc.x += acceleration*distance_dir_unit.x;
        acc.y += acceleration*distance_dir_unit.y;

    }
    else
    {

        for (int k = 0; k<sizeFF; k++)
        {
            ForceField force = d_f[k];
            if (!(asteroidI->pos.first>=force.leftCorner.first && asteroidI->pos.first<=force.rightCorner.first
                    && asteroidI->pos.second>=force.leftCorner.second
                    && asteroidI->pos.second<=force.rightCorner.second))
            {
                continue;
            }
            switch (force.dir)
            {
            case Direction::UP: acc.y -= force.force/asteroidI->mass;
                break;
            case Direction::DOWN: acc.y += force.force/asteroidI->mass;
                break;
            case Direction::LEFT: acc.x -= force.force/asteroidI->mass;
                break;
            case Direction::RIGHT: acc.x += force.force/asteroidI->mass;
                break;
            default: break;
            }
        }
    }
    accs[threadIdx.y * blockDim.x + threadIdx.x].x = acc.x;
    accs[threadIdx.y * blockDim.x + threadIdx.x].y = acc.y;
}
    __syncthreads(); //Synchronisiert alle Threads im Block. Können also so doch nur einen Block haben da sonst
    //die späteren Blocke mit veränderten Daten arbeiten
    // Size 5: Threads 0 - 4, shared arr size 25, i,j zwischen 0 - 4

    for (unsigned int s = 1; s<blockDim.x; s *= 2)
    {
        if (threadIdx.y%(2*s)==0 && i < size && j < size && blockIdx.y * blockDim.y + (threadIdx.y + s) < size)
        {
            accs[threadIdx.y* blockDim.x + threadIdx.x].x += accs[(threadIdx.y+s)*blockDim.x + threadIdx.x].x;
            accs[threadIdx.y* blockDim.x + threadIdx.x].y += accs[(threadIdx.y+s)*blockDim.x + threadIdx.x].y;
        }
        __syncthreads();
    }

    if (threadIdx.x == threadIdx.y && i < size && j < size)
    {
        Asteroid* ast = &d_a[i];
        ast->velocity.first += accs[threadIdx.x].x*dt;
        ast->velocity.second += accs[threadIdx.x].y*dt;
    }


}

void __global__ updatePositions(Asteroid* d_asteroid, int size, float dt) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if(i < size) {
		Asteroid* ast = &d_asteroid[i];
		ast->pos.first += ast->velocity.first * dt;
		ast->pos.second += ast->velocity.second * dt;
	}
}


void freeDeviceMemory_v3(Asteroid* d_asteroid, ForceField* d_forceField, float2* d_accs)
{
    cudaFree(d_asteroid);
    cudaFree(d_forceField);
    cudaFree(d_accs);
}

std::tuple<Asteroid*, ForceField*, float2*> updateMemory_v3(std::vector<Asteroid>& asteroids, std::vector<ForceField>& forceFields)
{
    Asteroid* d_asteroid;
    ForceField* d_forceField;
    float2* d_accs;
    int size = sizeof(Asteroid)*asteroids.size();
    int sizeFF = sizeof(ForceField)*forceFields.size();
    int sizeAccs = sizeof(float2)* blockSize * blockSize;
    auto start = std::chrono::steady_clock::now();
    cudaMalloc(&d_asteroid, size);
    cudaMalloc(&d_forceField, sizeFF);
    cudaMalloc(&d_accs, sizeAccs);
    cudaMemcpy(d_asteroid, asteroids.data(), size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_forceField, forceFields.data(), sizeFF, cudaMemcpyHostToDevice);
    auto end = std::chrono::steady_clock::now();
    float dif = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    MessSaver::add("GPUV3 Hinkopieren", dif);
    return std::make_tuple(d_asteroid, d_forceField, d_accs);
}

#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char* file, int line, bool abort = true)
{
    if (code!=cudaSuccess)
    {
        fprintf(stderr, "GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
        if (abort) exit(code);
    }
}

void call_kernel_v3(Asteroid* a, Asteroid* d_asteroid, ForceField* d_forceField, int sizeAsteroids, int sizeForceFields, float2* d_accs)
{
    if (sizeAsteroids==0)
    {
        return;
    }
	dim3 dim(std::ceil(sizeAsteroids / blockFloat), std::ceil(sizeAsteroids / blockFloat));
	auto start = std::chrono::steady_clock::now();

    calculate_forces_v3<<<dim, dim3(blockSize, blockSize)>>>(d_asteroid, 0.1, sizeAsteroids,
            d_forceField, sizeForceFields, d_accs);
    gpuErrchk(cudaPeekAtLastError());
    gpuErrchk(cudaDeviceSynchronize());

    updatePositions<<<std::ceil(sizeAsteroids / blockFloat * blockFloat), blockSize * blockSize>>>(d_asteroid, sizeAsteroids, 0.1);	
	auto end = std::chrono::steady_clock::now();
    float dif = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	 MessSaver::add("GPUV3 Berechnen", dif);
     start = std::chrono::steady_clock::now();
    cudaMemcpy(a, d_asteroid, sizeof(Asteroid)*sizeAsteroids, cudaMemcpyDeviceToHost);
    end = std::chrono::steady_clock::now();
    dif = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
         MessSaver::add("GPUV3 Zurückkopieren", dif);
}

