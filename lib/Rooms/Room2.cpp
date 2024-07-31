#include "Room2.h"
#include "../Objects/Frog.h"

Room2::Room2(){
    
}

void Room2::create(SDL_Renderer* r){
    printf("Room 2 create\n");
    frog1 = new Frog(50,50,50,50,false,"Sean", r);
    this->addObject(frog1);
    //This ensures objects have access to the other objects in the room
	for(int i = 0; i < objects.size(); i++){
		objects[i]->setObjects(objects);
	}
    background = createTexture("./assets/sprites/background.bmp", r);
}

void Room2::draw(SDL_Renderer* r){
	//Make sure to render background first	
	SDL_RenderCopy(r, background, NULL, NULL);
	//Render everything else on top	
	frog1->draw(r);
	SDL_RenderPresent(r);
}


void Room2::update(int key){
	//Move frog 1
	int prev_x = frog1->getX();
	int prev_y = frog1->getY();
	//Send keyboard input to object
	if(key == 1){
		if(!((prev_y-3) <= 0)){
			frog1->update(prev_x, prev_y-3);
		}
	}else if(key == 2){
		if(!((prev_y+3) >= 720)){	
			frog1->update(prev_x, prev_y+3);
		}
	}else if(key == 3){
		if(!((prev_x-3) <= 0)){
			frog1->update(prev_x-3, prev_y);
		}
	}else if(key == 4){
		if(!((prev_x+3) >= 1280)){	
			frog1->update(prev_x+3, prev_y);
		}
	}else{
		frog1->update(prev_x, prev_y);
	}
}
