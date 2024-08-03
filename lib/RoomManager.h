#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Object.h"
// Include rooms you create here
/* Example:
#include "./Rooms/Room2.h"
*/

#include "./Rooms/Room1.h"

class RoomManager {
    public:
        /* Create room points here for rooms
            Example:
            Room1* room1;
		    Room2* room2;
        */
		Room1* room1;
        // Number of rooms
        int n;
		~RoomManager();
        void update(int key);
        void create();
        void draw();
};
