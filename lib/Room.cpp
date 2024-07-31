#include <stdio.h>
#include <SDL2/SDL.h>
#include "RoomManager.h"
#include "Room.h"
#include "Object.h"

void Room::update(int key){
}
void Room::create(SDL_Renderer* r){

}

void Room::draw(SDL_Renderer* r){

}

// Adds an object to the room
void Room::addObject(Object* p){
	objects.push_back(p);
	n++;
}


// Returns a vector of all obejcts in the room
std::vector<Object*> Room::getObjects(){
	return objects;
}

SDL_Texture* Room::createTexture(char* p, SDL_Renderer* r_in){
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

void Room::dispText(int x, int y, int w, int h, char* t, SDL_Renderer* r){
	SDL_Color color = {0,0,0};
	text = TTF_RenderText_Solid(font, t, color);
	text_texture = SDL_CreateTextureFromSurface(r, text);
	SDL_Rect dest = {0,0,text->w, text->h};
	SDL_RenderCopy(r, text_texture, NULL, &dest);
}
