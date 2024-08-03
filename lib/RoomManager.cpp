#include <stdio.h>
#include <SDL2/SDL.h>
#include "RoomManager.h"
#include "../renderer.h"
#include "roomstate.h"

// Include any rooms here
#include "./Rooms/Room1.h"

RoomManager::~RoomManager(){
	delete room1;
}

void RoomManager::update(int key){
	room1->update(key);
}

void RoomManager::create(){
    //Room manager logic
	// Add roomes here:
	room1 = new Room1();
    room1->create();

}
void RoomManager::draw(){
	// Draw room based on state:
	if(roomState == 1){
		room1->draw();
	}else if(roomState == 2){
	}
}

