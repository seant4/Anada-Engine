#pragma once
#include "../Room.h"
#include "../Objects/Frog.h"

class Room;

class Room2: public Room{
    public:
    	SDL_Texture* background;
        Room2();
		Frog* frog1;
		Frog* frog2;
        void create(SDL_Renderer* r) override;
        void update(int key) override;
        void draw(SDL_Renderer* r) override;
};
