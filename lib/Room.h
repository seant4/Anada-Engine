#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Object.h"

class Room {
    public:
        SDL_Renderer* renderer;
        std::vector<Object*> objects;
        int n;
        virtual void update(int key);
        virtual void create(SDL_Renderer* r);
        virtual void draw(SDL_Renderer* r);
        void addObject(Object* p);
        std::vector<Object*> getObjects();
        SDL_Texture* createTexture(char* p, SDL_Renderer* r_in);
};
