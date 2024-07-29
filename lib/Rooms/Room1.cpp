#include "Room1.h"

// Room 1 logic -------------------------------------------------------------

void Room1::create(){	
	//Add objects to my room
	Player* sean = new Player(50,50,50,50,true,"Sean");
	Player* joe = new Player(101,101,50,50,false,"Joe");
	this->addObject(sean);
	this->addObject(joe);

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
			if(key == 1){
				if(!((prev_y-3) <= 0)){
					objects[i]->update(prev_x, prev_y-3);
				}
			}else if(key == 2){
				if(!((prev_y+3) >= 480)){	
					objects[i]->update(prev_x, prev_y+3);
				}
			}else if(key == 3){
				if(!((prev_x-3) <= 0)){
					objects[i]->update(prev_x-3, prev_y);
				}
			}else if(key == 4){
				if(!((prev_x+3) >= 640)){	
					objects[i]->update(prev_x+3, prev_y);
				}
			}else{
				objects[i]->update(prev_x, prev_y);
			}
		}
	}
}
