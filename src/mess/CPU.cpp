#include <cmath>
#include "../data/data.h"
#include "../mess/MessSaver.h"

void cpu(std::vector<Asteroid>& asteroids, std::vector<ForceField>& forceFields)
{
	float dt = 1;
	float BIG_G = 9.81;
	float epsilon = 10;

	if(asteroids.empty()) {
                return;
        }
        
	for(int i = 0; i < asteroids.size(); i++){
		Asteroid* ast = &asteroids[i];
		std::pair<float, float> acc= {0,0}; //Acceleration in x and y direction
		for(int j = 0; j < asteroids.size(); j++){
                	if(i == j) continue; //Keine Gravity zu sich selber

                	Asteroid* other = &asteroids[j];
                	std::pair<float, float> distance_dir = {ast->pos.first - other->pos.first, ast->pos.second - other->pos.second};
                	float distance = sqrt(distance_dir.first * distance_dir.first + distance_dir.second * distance_dir.second); //Pythagoras r = sqrt(x² + y²)

                	// Bei Distanz gegen 0 geht Kraft gegen unendlich
                	// -> Kraft begrenzen durch Softening Faktor EPS
                	float soften_dist = sqrt(distance * distance + epsilon * epsilon);
                	float acceleration = -1.0 * BIG_G * other->mass / (soften_dist * soften_dist);

			std::pair<float, float> distance_dir_unit = {distance_dir.first / soften_dist, distance_dir.second / soften_dist}; //Distance Vector normalisiert (durch Länge geteilt)

                	acc.first += acceleration * distance_dir_unit.first;
                	acc.second += acceleration * distance_dir_unit.second;
        	}

        
        	ast->velocity.first += acc.first * dt;
        	ast->velocity.second += acc.second * dt;

	}

	for(int i = 0; i < asteroids.size(); i++){
		Asteroid* ast = &asteroids[i];

		ast->pos.first += ast->velocity.first * dt;
                ast->pos.second += ast->velocity.second * dt;

	}
	

}
