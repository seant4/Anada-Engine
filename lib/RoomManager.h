#pragma once
#include <SDL2/SDL.h>
#include <vector>
// Include rooms you create here
/* Example:
#include "./Rooms/Room2.h"
*/

#include "./Rooms/ExRoom.h"

class RoomManager {
    public:
        /* Create room points here for rooms
            Example:
            Room1* room1;
		    Room2* room2;
        */
		ExRoom exroom;
        // Number of rooms
        int n;
		~RoomManager();
        void update(int key);
        void create();
        void draw();
};
