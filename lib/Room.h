#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

class Room {
    public:
        int n;
        virtual void update(int key);
        virtual void create();
        virtual void draw();
		TTF_Font* font;
		SDL_Surface* text;
		SDL_Texture* text_texture;
};
