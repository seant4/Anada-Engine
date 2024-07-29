#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "./lib/Object.cpp"
#include "./lib/Room.cpp"
#include "./lib/Rooms/Room1.cpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* args[]){

	//Window initialization
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow(
			"Hello, World!",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
			);
	if (window == NULL){
		fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	screenSurface = SDL_GetWindowSurface(window);
	bool quit = false;
	SDL_Event e;
	// Create initial variables
	Room1 room1;
	room1.create();
	while(!quit){
		while(SDL_PollEvent(&e) != 0){
			if(e.type==SDL_QUIT){
				quit = true;
			}
			else if(e.type == SDL_KEYDOWN){ //Input handler
				switch(e.key.keysym.sym){
					case SDLK_UP:
						room1.update(1);
						break;
					case SDLK_DOWN:
						room1.update(2);
						break;
					case SDLK_LEFT:
						room1.update(3);
						break;
					case SDLK_RIGHT:
						room1.update(4);
						break;
				}
			}			
		}
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0,0,0));
		room1.draw(screenSurface);
		SDL_UpdateWindowSurface(window);
	}

	SDL_DestroyWindow(window);
	SDL_FreeSurface(screenSurface);
	// TODO: Deconstructors
	SDL_Quit();
	return 0;
}

