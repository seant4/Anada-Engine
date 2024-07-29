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

// Room 1 logic -------------------------------------------------------------
void Room1::update(int key){	
	for(int i = 0; i < n; i++){
		//Handle player controlled object
		if(objects[i]->playerControll()){
			int prev_x = objects[i]->getX();
			int prev_y = objects[i]->getY();
			if(key == 1){
				if(!((prev_y-3) <= 0)){
					objects[i]->update(prev_x, prev_y-3);
				}
			}else if(key == 2){
				if(!((prev_y+3) >= 480)){	
					objects[i]->update(prev_x, prev_y+3);
				}
			}else if(key == 3){
				if(!((prev_x-3) <= 0)){
					objects[i]->update(prev_x-3, prev_y);
				}
			}else if(key == 4){
				if(!((prev_x+3) >= 640)){	
					objects[i]->update(prev_x+3, prev_y);
				}
			}else{
				objects[i]->update(prev_x, prev_y);
			}
		}
	}
}
