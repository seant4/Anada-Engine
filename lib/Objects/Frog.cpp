#include "Frog.h"
#include <stdio.h>
#include "../roomstate.h"

Frog::Frog(int xi, int yi, int wi, int hi, bool ci, std::string namei, SDL_Renderer* ri) : Object(xi, yi, wi, hi, ci, namei){
	//Load image
    texture = createTexture("./assets/sprites/frog.bmp", ri);
}

Frog::~Frog(){
    SDL_DestroyTexture(texture);
}

void Frog::update(int x_in, int y_in) {	
	std::vector<int> fut = Object::applyPhysics(this, std::vector<int>{x_in,y_in});
	Object* future = new Object(fut[0], fut[1],w,h,c,"Future");
	if(objects.size() > 1){
		bool col = future->rectCollision(future, objects[1]);//collide with floor
		if(!col){ //no collision
			Object::setX(fut[0]);
			Object::setY(fut[1]);
		}else{ //Collision with floor
			Object::setX(fut[0]);
			vel[0] = 0;
			vel[1] = 0; //Cant move down anymore
		}
		delete future;
	}
}

void Frog::draw(SDL_Renderer* r){
	SDL_Rect dstrect = {x,y,w,h};
	SDL_RenderCopy(r, texture, NULL, &dstrect);
}

