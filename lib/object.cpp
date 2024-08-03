#include "Object.h"
#include <stdio.h>
#include <string>
Object::Object(int xi, int yi, int wi, int hi, std::string namei){
    x=xi;
	y=yi;
	h=hi;
	w=wi;
	name=namei;
	vel.push_back(0); //Starting x velocity
	vel.push_back(0); //Starting y velocity
}

void Object::update(){
}
void Object::setObjects(std::vector<Object*> objects_in){
	objects = objects_in;
}

void Object::draw(SDL_Renderer* r){
}

