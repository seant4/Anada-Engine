#include "Object.h"
#include <stdio.h>
#include <string>
Object::Object(int xi, int yi, int wi, int hi, std::string namei){
    x=xi;
	y=yi;
	h=hi;
	w=wi;
	frame = 1;
	name=namei;
	vel.push_back(0); //Starting x velocity
	vel.push_back(0); //Starting y velocity
}

void Object::update(){
}

int Object::getX(){
	return x;
}

int Object::getY(){
	return y;
}

int Object::getW(){
	return w;
}

int Object::getH(){
	return h;
}

void Object::setX(int x_in){
	x=x_in;
}

void Object::setY(int y_in){
	y=y_in;
}

std::string Object::getName(){
	return name;
}

void Object::setObjects(std::vector<Object*> objects_in){
	objects = objects_in;
}

SDL_Texture* Object::createTexture(char* p, SDL_Renderer* r_in){
	SDL_Surface* image = SDL_LoadBMP(p);
	if(image == NULL){
		printf("Image could not be loaded: %s\n", SDL_GetError());
	}
	SDL_Texture* t = SDL_CreateTextureFromSurface(r_in, image);
	if(t == NULL){
		printf("Texture could not be created: %s\n", SDL_GetError());
	}
	SDL_FreeSurface(image);
	return t;
}

void Object::draw(SDL_Renderer* r){
}

bool Object::rectCollision(Object* obj1, Object* obj2){
	int x1r = obj1->getX() + obj1->getW();
	int y1b = obj1->getY() + obj1->getH();
	int x2r = obj2->getX() + obj2->getW();
	int y2b = obj2->getY() + obj2->getH();
	if(obj1->getX() >= x2r || obj2->getX() >= x1r){
		return false;
	}

	if(obj1->getY() >= y2b || obj2->getY() >= y1b){
		return false;
	}
	return true;
}

bool Object::isColliding(std::vector<Object*> objects_in){
	return false;
}

std::vector<int> Object::applyPhysics(Object* o, std::vector<int> force){	
	//Apply gravity
	o->vel[0] += force[0];
	o->vel[1] += (force[1] + 1); //gravity
	int x_fut = vel[0] + o->getX();
	int y_fut = vel[1] + o->getY();
	return std::vector<int>{x_fut, y_fut};
}

