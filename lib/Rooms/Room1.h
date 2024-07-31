#pragma once
#include "../Room.h"
#include "../Objects/Frog.h"
#include "../Object.h"

class Room;

class Room1: public Room{
    public:
    	SDL_Texture* background;
        Room1();
		Frog* frog1;
		Object* floor;
        void create(SDL_Renderer* r) override;
        void update(int key) override;
        void draw(SDL_Renderer* r) override;
};
