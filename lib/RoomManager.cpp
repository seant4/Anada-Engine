#include <stdio.h>
#include <SDL2/SDL.h>
#include "RoomManager.h"
// Include any objects here
/* Example
#include "./Objects/Frog.h"
*/

// Include any rooms here
/* Example:
#include "./Rooms/Room1.h"
#include "./Rooms/Room2.h"
*/

#include "./roomstate.h"

RoomManager::~RoomManager(){
	/* Delete created rooms
	delete room1;
	delete room2;
	*/
}

void RoomManager::update(int key){
	/* Handle room update 
	Room switch handling example:
	if(roomState == 1){
		room1->update(key);
	}else if(roomState == 2){
		room2->update(key);
	}
	*/	
}

void RoomManager::create(SDL_Renderer* r){
    //Room manager logic
	// Add roomes here:
	/* Examples: 
	room1 = new Room1();
    renderer = r;
    room1->create(renderer);
	room2 = new Room2();
	room2->create(renderer);
	*/

}
void RoomManager::draw(SDL_Renderer* r){
	// Draw room based on state:
	/* Example:
	if(roomState == 1){
		room1->draw(renderer);
	}else if(roomState == 2){
		room2->draw(renderer);
	}
	*/
}

