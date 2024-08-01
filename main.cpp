#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "./lib/Object.h"
#include "./lib/RoomManager.h"

//Include objects and rooms here:
/* Example
#include "./lib/Objects/Frog.h"
#include "./lib/Rooms/Room1.h"
*/

#include "./lib/Room.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

SDL_Renderer* initRender(SDL_Window* window){
	//Window initialization
	SDL_Renderer* renderer = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
	}

	if(TTF_Init() < 0){
		fprintf(stderr, "Could not initialize SDL_TTF: %s\n", TTF_GetError());
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
	unsigned int a = SDL_GetTicks();
	unsigned int b = SDL_GetTicks();
	double delta = 0;
	double framerate = 30.0; //Set framerate here
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = initRender(window);

    bool quit = false;
    SDL_Event e;
	//Typically set up room manager here
    //RoomManager manager;
    //manager.create(renderer);

    while(!quit){
		a = SDL_GetTicks();
		delta = a - b;
		if(delta > 1000/framerate){
			b=a;
			while(SDL_PollEvent(&e) != 0){
            	if(e.type==SDL_QUIT){
                	quit = true;
            	}
				//Handle user input here via SDL2 input handler, send this to manager
        	}
			//Draw room manager here
        	//manager.draw(renderer);
        	SDL_RenderPresent(renderer);
		}
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
