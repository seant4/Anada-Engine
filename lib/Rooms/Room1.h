#pragma once
#include "../Room.h"
#include "../Object.h"
#include "../Objects/Player.h"

class Room;

class Room1: public Room{
    public:
    	SDL_Texture* background;
        Room1();
		~Room1();
		Player* player;
		Object* floor;
		int inputArray[5];
        void create();
        void update(int key) override;
        void draw();
};
