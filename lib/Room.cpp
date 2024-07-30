#include <SDL2/SDL.h>
#include <string>
#include "Room.h"

Room::Room(){
	n = 0;
}

Room::~Room(){
	//Free objects added to room
	//Change later for persistant objects
	for(int i = 0; i < objects.size(); i++){ 
		delete objects[i];
	}
}

// Draws all objects in the room
void Room::draw(SDL_Renderer* r){
	for(int i = 0; i < n; i++){
		objects[i]->draw(r);
	}
	SDL_RenderPresent(r);
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


