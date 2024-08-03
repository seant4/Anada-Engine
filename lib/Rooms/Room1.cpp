#include "Room1.h"
#include "../Object.h"
#include "../Objects/Player.h"
#include "../../renderer.h"
#include "../Modules/Visuals/createTexture.h"

Room1::~Room1(){
}

Room1::Room1(){    

}

void Room1::create(){
	background = createTexture("./assets/sprites/background.bmp");
	player = new Player(640, 100, 400, 400, 0, "Player");
	floor = new Object(0, 720, 1280, 1, "Floor");
	this->addObject(player);
	this->addObject(floor);
	for(int i = 0; i < objects.size(); i++){
		objects[i]->setObjects(objects);
	}
}

void Room1::draw(){
	SDL_RenderCopy(renderer, background, NULL, NULL);
	player->draw();
}

void Room1::update(int key){
	player->update(0,0);
}
