#include "Room1.h"
#include "../../renderer.h"
#include "../Modules/Visuals/createTexture.h"
#include "../Modules/Visuals/fade.h"
#include "../Objects/Dude.h"

Room1::~Room1(){
}

Room1::Room1(){    

}

void Room1::create(){
	background = createTexture("./assets/sprites/background.bmp");
	d = {0,0,400,400,0,0,0,false,createTexture("./assets/sprites/frog_sheet.bmp"), std::vector<int>{0,0}};
	f = {255, 6, 0};  
}

void Room1::draw(){
	SDL_RenderCopy(renderer, background, NULL, NULL);
	drawDude(d);
	drawFade(&f);
}

void Room1::update(int key){
	updateFade(&f);
	updateDude(&d);
}
