#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Object.h"

Object::Object(int x_in, int y_in, int w_in, int h_in,bool c_in, std::string name_in){
	x=x_in;
	y=y_in;
	h=h_in;
	w=w_in;
	c=c_in;
	name=name_in;
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

bool Object::playerControll(){
	return c;
}

void Object::setX(int x_in){
	x=x_in;
}

void Object::setY(int y_in){
	y=y_in;
}

void Object::setObjects(std::vector<Object*> objects_in){
	objects = objects_in;
}

std::string Object::getName(){
	return name;
}

bool Object::isColliding(std::vector<Object*> objects_in){
	return false;
}

void Object::draw(SDL_Renderer* r){
	SDL_Rect dstrect = {x,y,w,h};
	SDL_RenderCopy(r, texture, NULL, &dstrect);
}

void Object::update(int x_in, int y_in){

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

SDL_Texture* Object::createTexture(char* p, SDL_Renderer* r_in){
	SDL_Surface* image = SDL_LoadBMP(p);
	if(image == NULL){
		printf("Image could not be loaded: %s\n", SDL_GetError());
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(r_in, image);
	if(texture == NULL){
		printf("Texture could not be created: %s\n", SDL_GetError());
	}
	SDL_FreeSurface(image);
	return texture;
}
