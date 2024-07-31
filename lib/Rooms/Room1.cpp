#include "Room1.h"
#include "../Objects/Frog.h"
#include "../Object.h"

Room1::Room1(){
    
}

void Room1::create(SDL_Renderer* r){
    printf("Room 1 create\n");
    frog1 = new Frog(50,50,400,400,false,"Sean", r);
    this->addObject(frog1);
	floor = new Object(0,720,1280,2,false,"Floor");
	this->addObject(floor);
	for(int i = 0; i < objects.size(); i++){
		objects[i]->setObjects(objects);
	}
    background = createTexture("./assets/sprites/background.bmp", r);
}

void Room1::draw(SDL_Renderer* r){
	//Make sure to render background first	
	SDL_RenderCopy(r, background, NULL, NULL);
	//Render everything else on top	
	frog1->draw(r);
	SDL_RenderPresent(r);
}


void Room1::update(int key){
	//Move frog 1
	int prev_x = frog1->getX();
	int prev_y = frog1->getY();
	//Send keyboard input to object
	switch(key){
		case 1: frog1->update(0, -3); break;
		case 2: frog1->update(0, +3); break;
		case 3: frog1->update(-3, 0); break;
		case 4: frog1->update(+3, 0); break;
		default: frog1->update(0, 0); break;
	}
}
