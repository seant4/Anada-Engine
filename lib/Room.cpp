#include <SDL2/SDL.h>
#include <string>
#include "Room.h"

Room::Room(){
	n = 0;
}

void Room::create(){
	for(int i = 0; i < n; i++){
		objects[i]->setObjects(objects);
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


