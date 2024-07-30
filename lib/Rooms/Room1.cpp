#include "Room1.h"
#include "../Objects/Frog.cpp"
/* Example room implementation
 * 
 * This room loads our Frog object
 */
// Room 1 logic -------------------------------------------------------------

void Room1::create(SDL_Renderer* r_in){	
	r = r_in;	
	//Add objects to my room
	Frog* frog1 = new Frog(400,400,50,50,true,"Frog", r_in);
	this->addObject(frog1);
	//This ensures objects have access to the other objects in the room
	for(int i = 0; i < objects.size(); i++){
		objects[i]->setObjects(objects);
	}
}

void Room1::update(int key){
	//Room update happens each frame
	for(int i = 0; i < n; i++){
		//Handle player controlled object
		if(objects[i]->playerControll()){
			int prev_x = objects[i]->getX();
			int prev_y = objects[i]->getY();
			//Send keyboard input to object
			if(key == 1){
				if(!((prev_y-3) <= 0)){
					objects[i]->update(prev_x, prev_y-3);
				}
			}else if(key == 2){
				if(!((prev_y+3) >= 720)){	
					objects[i]->update(prev_x, prev_y+3);
				}
			}else if(key == 3){
				if(!((prev_x-3) <= 0)){
					objects[i]->update(prev_x-3, prev_y);
				}
			}else if(key == 4){
				if(!((prev_x+3) >= 1280)){	
					objects[i]->update(prev_x+3, prev_y);
				}
			}else{
				objects[i]->update(prev_x, prev_y);
			}
		}
	}
}