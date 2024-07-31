#include "Frog.h"
#include <stdio.h>
#include "../roomstate.h"

Frog::Frog(int xi, int yi, int wi, int hi, bool ci, std::string namei, SDL_Renderer* ri) : Object(xi, yi, wi, hi, ci, namei){
	//Load image
	airborne = true;
    texture = createTexture("./assets/sprites/frog_sheet.bmp", ri);
}

Frog::~Frog(){
    SDL_DestroyTexture(texture);
}

void Frog::update(int x_in, int y_in) {	
	//if in the air, cant jump
	if(airborne){
		y_in = 0;
		x_in = 0;
	}
	//Collision detection
	std::vector<int> fut = Object::applyPhysics(this, std::vector<int>{x_in,y_in});
	Object* future = new Object(fut[0], fut[1],w,h,c,"Future");
	if(objects.size() > 1){
		bool col = future->rectCollision(future, objects[1]);//Check collision with floor
		if(!col){ //Airborne
			Object::setX(fut[0]);
			if(fut[1] < this->getY()){//jumping
				airborne = true;
			}
			Object::setY(fut[1]);
		}else{ //Collision with floor
			Object::setX(fut[0]);
			vel[0] = 0;
			vel[1] = 0; //Cant move down anymore
			airborne = false;
		}
		delete future;
	}
}

void Frog::draw(SDL_Renderer* r){
	int woffset = w * (frame%2);
	SDL_Rect dstrect = {x,y,w,h};
	SDL_Rect srcrect = {woffset,0,w,h};
	SDL_RenderCopy(r, texture, &srcrect, &dstrect);
	frame++;
}

