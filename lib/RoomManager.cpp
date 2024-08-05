#include <stdio.h>
#include <SDL2/SDL.h>
#include "RoomManager.h"
#include "../renderer.h"
#include "roomstate.h"

// Include any rooms here
#include "./Rooms/ExRoom.h"

RoomManager::~RoomManager(){
}

void RoomManager::update(int key){
	updateExRoom(&exroom, key);
}

void RoomManager::create(){
    //Room manager logic
	// Add roomes here:
	createExRoom(&exroom);

}
void RoomManager::draw(){
	// Draw room based on state:
	if(roomState == 1){
		drawExRoom(&exroom);
	}else if(roomState == 2){
	}
}

