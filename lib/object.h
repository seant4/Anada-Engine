#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <vector>

class RoomManager;
class Room;

class Object{
    public:
		int x; //Objects x position
		int y; //Objects y position
		int w; //Object width
		int h; //Object height
		std::vector<Object*> objects; //All objects in room
		std::vector<int> vel; //velocity
		std::string name; //Name of object
        Object(int xi, int yi, int wi, int hi, std::string namei);
        //Getters and setter
		void setObjects(std::vector<Object*> objects);
		std::string getName();
		//Logic functions
        virtual void update();
        virtual void draw(SDL_Renderer* r);
};
