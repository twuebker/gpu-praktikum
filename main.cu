#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>

namespace asteroids{

using vec2f = std::vector<float, float>;

SDL_Texture *m_texture;

void render(){

}

int main(int argc, char** argv)
{
	SDL_Event e;
	const Uint8* currentKeyStates;
	bool quit = false;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window;
	SDL_Renderer *renderer;
	window = SDL_CreateWindow("Asteroids", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_Surface *surface = IMG_Load(argv[1]);
        m_texture = SDL_CreateTextureFromSurface(renderer, surface);


	while(!quit){
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT){
				quit = true;
			}
		}
		SDL_RenderClear(renderer);
		render();
	}
	std::cout << "Hello, World!" << std::endl;
	return 0;
}


struct asteroid{
	std::vector<float> pos;
	float mass;

};


}
