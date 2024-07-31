#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Object.h"
#include "./Rooms/Room1.h"
#include "./Rooms/Room2.h"

class RoomManager {
    public:
        SDL_Renderer* renderer;
        Room1* room1;
		Room2* room2;
        int n;
        void update(int key);
        void create(SDL_Renderer* r);
        void draw(SDL_Renderer* r);
};
