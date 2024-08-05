#pragma once
#include "../Room.h"
#include "../Objects/Dude.h"
#include "../Modules/Visuals/fade.h"

class Room;

class Room1: public Room{
    public:
    	SDL_Texture* background;
        Room1();
		~Room1();
		Dude d;
		Fade f;
		int inputArray[5];
        void create();
        void update(int key) override;
        void draw();
};
