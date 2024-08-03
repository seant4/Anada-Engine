#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "Object.h"

class Room {
    public:
        std::vector<Object*> objects;
        int n;
        virtual void update(int key);
        virtual void create();
        virtual void draw();
		TTF_Font* font;
		SDL_Surface* text;
		SDL_Texture* text_texture;
        void addObject(Object* p);
        std::vector<Object*> getObjects();
};
