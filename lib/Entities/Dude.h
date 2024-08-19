#pragma once
#include <vector>
#include "Entity.h"
struct Dude : public Entity{
	int o; //Spritesheet offset
	int a; //Animation speed
	int f; //Animation frame
	bool b; //Blink frame
	SDL_Texture* texture; //Texture 
	std::vector<int> vel; //Velocity
	void draw();
	void update();
};
