#ifndef DATA_H
#define DATA_H


#include <utility>
#include <vector>


enum class Direction {
        UP,
        DOWN,
        RIGHT,
        LEFT,
};

struct field{
        std::pair<float, float> leftCorner;
        std::pair<float, float> rightCorner;
        float force;
        Direction dir;
} typedef ForceField;

struct ast{
        std::pair<float, float> pos;
        std::pair<float, float> velocity;
        float mass;
        } typedef Asteroid;



#endif
