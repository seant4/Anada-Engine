#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "../Objects/Dude.h"
#include "../Modules/Visuals/fade.h"

struct ExRoom {
    int inputArray[5];
    SDL_Texture* background;
	SDL_Texture* clouds;
	int scrollingOffset;
	int frame;
    Dude d;
    Fade f;
}; 

void createExRoom(ExRoom* room);
void updateExRoom(ExRoom* room, int key);
void drawExRoom(ExRoom* room);
