#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Object.h"
#include "Collision.cpp"

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
