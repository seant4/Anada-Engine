#pragma once
#include "../Object.h"

class Room1;

class Frog: public Object{
    public:
        SDL_Texture* texture;
		bool airborne;
        Frog(int xi, int yi, int wi, int hi, bool ci, std::string namei, SDL_Renderer* r);
        ~Frog();
        void update(int x, int y);
		void draw(SDL_Renderer* r) override;
};
