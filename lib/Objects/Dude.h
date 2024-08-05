#pragma once
#include <vector>

struct Dude{
	int x; //X pos
	int y; //Y pos
	int w; //Width
	int h; //Height
	int o; //Spritesheet offset
	int a; //Animation speed
	int f; //Animation frame
	bool b; //Blink frame
	SDL_Texture* texture; //Texture 
	std::vector<int> vel; //Velocity
};

void drawDude(struct Dude d);
void updateDude(Dude* d);
