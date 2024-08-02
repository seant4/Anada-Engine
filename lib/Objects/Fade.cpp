#include "Fade.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../roomstate.h"

Fade::Fade(int xi, int yi, int wi, int hi, std::string namei, SDL_Renderer* ri) : Object(xi, yi, wi, hi, namei){
	timer = xi;
	amount = yi;
	if(timer==255){
		fade = 0;
	}else{
		fade = 1;
	}
	room = wi;
}

Fade::~Fade(){
}

bool Fade::update(int x_in, int y_in) {
	if(fade == 0){//Fade in
		if(timer > 0){
			if(!((timer - amount) <= 0)){
				timer = timer - amount;
				return false;
			}else{
				timer = 0;
				if(room != 0){
					roomState = room;
				}
				return true;
			}
		}
	}else{
		if(timer < 255){
			if(!((timer + amount) >= 255)){
				timer = timer + amount;
				return false;
			}else{
				timer = 255;
				if(room != 0){
					roomState = room;
				}
				return true;
			}
		}
	}
	return false;
}

void Fade::draw(SDL_Renderer* r){
	SDL_Rect rect = {0,0,1280,720};
	SDL_SetRenderDrawColor(r,0,0,0,timer);
	SDL_RenderFillRect(r, &rect);
}

