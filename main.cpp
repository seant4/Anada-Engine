#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "./lib/Object.h"
#include "./lib/RoomManager.h"
#include "./lib/Objects/Frog.h"
#include "./lib/Rooms/Room1.h"
#include "./lib/Room.h"
#include "./lib/Rooms/Room2.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

SDL_Renderer* initRender(SDL_Window* window){
	//Window initialization
	SDL_Renderer* renderer = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
	}

	window = SDL_CreateWindow(
			"Hello, World!",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
			);

	if (window == NULL){
		fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
	}
	//Create renderer
	renderer = SDL_CreateRenderer(window,-1,0);
	return renderer;
}

int main(int argc, char* args[]){
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = initRender(window);

    bool quit = false;
    SDL_Event e;
    RoomManager manager;
    manager.create(renderer);
    manager.update(5);

    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type==SDL_QUIT){
                quit = true;
            }
			else if(e.type == SDL_KEYDOWN){
				switch(e.key.keysym.sym){
					case SDLK_UP: manager.update(1); break;
					case SDLK_DOWN: manager.update(2); break;
					case SDLK_LEFT: manager.update(3); break;
					case SDLK_RIGHT: manager.update(4); break;
				}
			}else if(e.type == SDL_KEYUP){
				switch(e.key.keysym.sym){
					case SDLK_UP: manager.update(6); break;
					case SDLK_DOWN: manager.update(7); break;
					case SDLK_LEFT: manager.update(8); break;
					case SDLK_RIGHT: manager.update(9); break;
				}
			}
        }
        manager.update(5);
        manager.draw(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
