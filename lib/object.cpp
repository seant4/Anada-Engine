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

Player::Player(int x_in, int y_in, int w_in, int h_in, bool c_in, std::string name_in) : Object(x_in, y_in, w_in, h_in, c_in, name_in){
}

void Player::draw(SDL_Surface* s) const {
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	rect.h=h;
	rect.w=w;
	SDL_FillRect(s, &rect, SDL_MapRGB(s -> format, 0xFF, 0xFF, 0xFF));
}

void Player::update(int x_in, int y_in) {
	Player* future = new Player(x_in, y_in, w,h,c,name);
	bool col = future->isColliding(objects);
	if(!col){
		Object::setX(x_in);
		Object::setY(y_in);
	}
	delete future;
}

bool Player::isColliding(std::vector<Object*> objects){
	for(int i = 0; i < objects.size(); i++){
		if(this->name != objects[i]->getName()){
			if(rectCollision(this, objects[i])==true){
				return true;
			}
		}
	}
	return false;
}
