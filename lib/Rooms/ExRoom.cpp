#include "ExRoom.h"
#include "../../renderer.h"
#include "../Modules/Visuals/createTexture.h"
#include "../Modules/Visuals/fade.h"
#include "../Entities/Dude.h"

void createExRoom(ExRoom* room){
    room->background = createTexture("./assets/sprites/background.bmp");
	room->clouds = createTexture("./assets/sprites/cloud.bmp");
    room->d = {0,0,400,400,0,0,0,false,createTexture("./assets/sprites/frog_sheet.bmp"), std::vector<int>{0,0}};
    room->f = {255, 6, 0};
	room->scrollingOffset = 0;
	room->frame = 0;

}

void drawExRoom(ExRoom* room){
	SDL_Rect dstrect = {room->scrollingOffset, 0,1280,720};
	SDL_RenderCopy(renderer, room->clouds, NULL, &dstrect);
	dstrect.x += 1280;
	SDL_RenderCopy(renderer, room->clouds, NULL, &dstrect);
    SDL_RenderCopy(renderer, room->background, NULL, NULL);
	room->d.draw();
    //drawDude(room->d);
    drawFade(&(room->f));
}

void updateExRoom(ExRoom* room, int key){
	--room->scrollingOffset;
	if(room->scrollingOffset < -1280){
		room->scrollingOffset = 0;
	}
    updateFade(&(room->f));
	room->d.update();
    //updateDude(&(room->d));
}
