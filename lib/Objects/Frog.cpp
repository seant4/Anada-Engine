#include "Frog.h"
#include <stdio.h>

/* Example object
 *
 * This is an example of an implemented object, it has a sprite, collision detection,
 * and can move around the screen via keyboard input
 */

Frog::Frog(int x_in, int y_in, int w_in, int h_in, bool c_in, std::string name_in, SDL_Renderer* r_in) : Object(x_in, y_in, w_in, h_in, c_in, name_in){
	//Load image
	SDL_Surface* image = SDL_LoadBMP("./assets/sprites/frog.bmp");
	if(image == NULL){
		printf("Image could not be loaded: %s\n", SDL_GetError());
	}
	//Create texture
	texture = SDL_CreateTextureFromSurface(r_in, image);
	if(texture == NULL){
		printf("Texture could not be created: %s\n", SDL_GetError());
	}
	//Push texture to renderer
	SDL_Rect dstrect = {x_in,y_in,400,400};
	SDL_RenderCopy(r_in, texture, NULL, &dstrect);
	SDL_FreeSurface(image);
}

Frog::~Frog(){
	SDL_DestroyTexture(texture);
}
void Frog::draw(SDL_Renderer* r) const {
	//Push updated position to renderer
	SDL_Rect dstrect = {x,y,400,400};
	SDL_RenderCopy(r, texture, NULL, &dstrect);
}

void Frog::update(int x_in, int y_in) {
	//Collision detection
	Object* future = new Object(x_in, y_in,w,h,c,"Future");
	bool col = future->isColliding(objects);
	if(!col){
		Object::setX(x_in);
		Object::setY(y_in);
	}
	delete future;
}

bool Frog::isColliding(std::vector<Object*> objects){
	//Check collision on all objects in room
	for(int i = 0; i < objects.size(); i++){
		if(this->name != objects[i]->getName()){
			if(rectCollision(this, objects[i])==true){
				return true;
			}
		}
	}
	return false;
}
