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


void Room::draw(SDL_Surface* s){
	for(int i = 0; i < n; i++){
		objects[i]->draw(s);
	}
}

void Room::addObject(Object* p){
	objects.push_back(p);
	n++;
}

std::vector<Object*> Room::getObjects(){
	return objects;
}


