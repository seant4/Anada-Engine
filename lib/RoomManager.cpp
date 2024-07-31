#include <stdio.h>
#include <SDL2/SDL.h>
#include "RoomManager.h"
#include "./Objects/Frog.h"
#include "./Rooms/Room1.h"
#include "./Rooms/Room2.h"
#include "./roomstate.h"

RoomManager::~RoomManager(){
	delete room1;
	delete room2;
}

void RoomManager::update(int key){
	if(roomState == 1){
		room1->update(key);
	}else if(roomState == 2){
		//room2->update(key);
	}
		
}
void RoomManager::create(SDL_Renderer* r){
    //Room manager logic
    room1 = new Room1();
    renderer = r;
    room1->create(renderer);
	//room2 = new Room2();
	//room2->create(renderer);
}
void RoomManager::draw(SDL_Renderer* r){
	if(roomState == 1){
		room1->draw(renderer);
	}else if(roomState == 2){
		//room2->draw(renderer);
	}
}

