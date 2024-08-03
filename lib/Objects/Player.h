#pragma once
#include "../Object.h"

class Room1;

class Player: public Object{
    public:
        SDL_Texture* texture;
		SDL_Rect spriteClips[2];
		int woffset;
        Player(int xi, int yi, int wi, int hi, int woffset, std::string namei);
        ~Player();
		int frame;
		int animSpeed;
		int animFrame;
		bool blink;
		bool airborne;
        void update(int x_in, int y_in);
		void draw();
};

