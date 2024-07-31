#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Object.h"
// Include rooms you create here
/* Example:
#include "./Rooms/Room1.h"
#include "./Rooms/Room2.h"
*/


class RoomManager {
    public:
        SDL_Renderer* renderer;
        /* Create room points here for rooms
            Example:
            Room1* room1;
		    Room2* room2;
        */
        // Number of rooms
        int n;
		~RoomManager();
        void update(int key);
        void create(SDL_Renderer* r);
        void draw(SDL_Renderer* r);
};
