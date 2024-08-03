#include <stdio.h>
#include <SDL2/SDL.h>
#include "RoomManager.h"
#include "Room.h"
#include "Object.h"

void Room::update(int key){
}
void Room::create(){

}

void Room::draw(){

}

// Adds an object to the room
void Room::addObject(Object* p){
	objects.push_back(p);
	n++;
}


// Returns a vector of all obejcts in the room
std::vector<Object*> Room::getObjects(){
	return objects;
}

