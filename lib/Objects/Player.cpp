#include "Player.h"
#include <stdio.h>
#include "../roomstate.h"
#include <ctime>
#include "../Modules/Physics/physics.h"
#include "../Modules/Visuals/createTexture.h"
#include "../../renderer.h"

Player::Player(int xi, int yi, int wi, int hi, int woffset, std::string namei) : Object(xi, yi, wi, hi, namei){
	//Load image
	this->woffset = woffset;
    texture = createTexture("./assets/sprites/frog_sheet.bmp");
	frame = 0;
	srand(woffset);
	animSpeed = rand()%(30+1-20)+20;
	animFrame = 0;
	blink = false;
	airborne = true;
}

Player::~Player(){
    SDL_DestroyTexture(texture);
}

void Player::update(int x_in, int y_in) {	
	/* Handle animation */
	//Blink every x frames
	if(animFrame == 2){
		animFrame = 0;
		blink = false;
	}
	if((frame % animSpeed) == 0){
		blink = true;
	}
	if(blink){
		animFrame++;
	}
	frame++;

	//Apply physics
	std::vector<int> fut = applyPhysics(this, std::vector<int>{x_in,y_in});
	Object* future = new Object(fut[0], fut[1],w,h,"Future");
	bool col = rectCollision(future, objects[1]);//Check collision with floor
	if(!col){ //Airborne
		x=fut[0];
		if(fut[1] < y){//jumping
			airborne = true;
		}
		y=fut[1];
	}else{ //Collision with floor
		x=fut[0];
		vel[0] = 0;
		vel[1] = 0; //Cant move down anymore
		airborne = false;
	}
	delete future;
}

void Player::draw(){
	// int woffset = w * (frame%2);
	SDL_Rect dstrect = {x,y,w,h};
	SDL_Rect srcrect = {woffset,animFrame * h,400,400};
	SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}


