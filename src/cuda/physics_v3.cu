#define EPS (10)
#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include <utility>
#include <thrust/device_vector.h>
#include <stdio.h>

void __global__ calculate_forces_v3(Asteroid* d_a, float dt, int size, ForceField* d_f,
        int sizeFF)    //DelteTime ist die Zeit die zwischen zwei Berechnungen vergeht. Mussen irgendwie
{
    extern __shared__ float2 accs[];
    printf("IM KERNEL\n");
    int i = threadIdx.x;
    int j = threadIdx.y;
    Asteroid* asteroidI = &d_a[i];
    Asteroid* asteroidJ = &d_a[j];

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
    accs[j*size+i].x = acc.x;
    accs[j*size+i].y = acc.y;

    __syncthreads(); //Synchronisiert alle Threads im Block. Können also so doch nur einen Block haben da sonst
    //die späteren Blocke mit veränderten Daten arbeiten
    for (unsigned int s = 1; s<size; s *= 2)
    {
        if (j%(2*s)==0)
        {
            accs[j*size+i].x += accs[(j+s)*size+i].x;
            accs[j*size+i].y += accs[(j+s)*size+i].y;
        }
        __syncthreads();
    }

    if (i==j)
    {
        Asteroid* ast = &d_a[i];
        ast->velocity.first += accs[i].x*dt;
        ast->velocity.second += accs[i].y*dt;

        ast->pos.first += ast->velocity.first*dt;
        ast->pos.second += ast->velocity.second*dt;
        if (i==1)
        {
            printf("adding %f, %f to ast 1\n", ast->velocity.first, ast->velocity.second);
        }

    }

}

void freeDeviceMemory(Asteroid* d_asteroid, ForceField* d_forceField)
{
    cudaFree(d_asteroid);
    cudaFree(d_forceField);
}

std::pair<Asteroid*, ForceField*> updateMemory(std::vector<Asteroid>& asteroids, std::vector<ForceField>& forceFields)
{
    Asteroid* d_asteroid;
    ForceField* d_forceField;
    int size = sizeof(Asteroid)*asteroids.size();
    int sizeFF = sizeof(ForceField)*forceFields.size();
    cudaMalloc(&d_asteroid, size);
    cudaMalloc(&d_forceField, sizeFF);
    cudaMemcpy(d_asteroid, asteroids.data(), size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_forceField, forceFields.data(), sizeFF, cudaMemcpyHostToDevice);
    return std::make_pair(d_asteroid, d_forceField);
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

void call_kernel_v3(Asteroid* a, Asteroid* d_asteroid, ForceField* d_forceField, int sizeAsteroids, int sizeForceFields)
{
    if (sizeAsteroids==0)
    {
        return;
    }
    std::cout << "Kernel invoked" << std::endl;
    int sharedArraySize = sizeof(float2)*sizeAsteroids*sizeAsteroids;
    calculate_forces_v3<<<1, dim3(sizeAsteroids, sizeAsteroids), sharedArraySize>>>(d_asteroid, 0.1, sizeAsteroids,
            d_forceField, sizeForceFields);
    gpuErrchk(cudaPeekAtLastError());
    gpuErrchk(cudaDeviceSynchronize());
    cudaMemcpy(a, d_asteroid, sizeof(Asteroid)*sizeAsteroids, cudaMemcpyDeviceToHost);
    if (sizeAsteroids>=2)
    {
        std::cout << "Pos: " << a[1].pos.first << "," << a[1].pos.second << std::endl;
    }
}
