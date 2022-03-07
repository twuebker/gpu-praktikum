#include <iostream>
#include <vector>
#include "MainWindow.h"

namespace asteroids{

using vec2f = std::vector<float, float>;

void render(){

}

int main(int argc, char** argv)
{
	asteroids::MainWindow mw = MainWindow("asteroids", 600, 800);
}


struct asteroid{
	std::vector<float> pos;
	float mass;

};


}
