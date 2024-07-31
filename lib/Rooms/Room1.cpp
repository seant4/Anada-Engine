#include "Room1.h"
#include "../Objects/Frog.h"
#include "../Object.h"

Room1::~Room1(){
	delete frog1;
	delete floor;
}

Room1::Room1(){
    
}

void Room1::create(SDL_Renderer* r){
	for(int i = 0; i < 5; i++){ //set inputs to 0
		inputArray[i] = 0;
	}
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
	int speed = 10;
	switch(key){
		case 1: inputArray[1] = 1; break;
		case 2: inputArray[2] = 1; break;
		case 3: inputArray[3] = 1; break;
		case 4: inputArray[4] = 1; break;
		case 5: break;
		case 6: inputArray[1] = 0; break;
		case 7: inputArray[2] = 0; break;
		case 8: inputArray[3] = 0; break;
		case 9: inputArray[4] = 0; break;
	}
	int x_vel = (inputArray[4] + (-1 * inputArray[3])) * speed;
	int y_vel = (inputArray[2] + (-1 * inputArray[1])) * speed;
	frog1->update(x_vel, y_vel);

}
