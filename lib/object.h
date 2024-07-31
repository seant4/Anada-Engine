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
		bool c; //Controllable boolean
		std::string name; //Name of object
		int frame;        
        Object(int xi, int yi, int wi, int hi, bool ci, std::string namei);
        //Getters and setter
		int getX();
		int getY();
		int getW();
		int getH();
		void setX(int x_in);
		void setY(int y_in);
		void setObjects(std::vector<Object*> objects);
		bool playerControll();
		std::string getName();

		//Logic functions
        virtual void update();
        virtual void draw(SDL_Renderer* r);
        SDL_Texture* createTexture(char* p, SDL_Renderer* r);
		bool rectCollision(Object* obj1, Object* obj2);
		virtual bool isColliding(std::vector<Object*> objects);
		virtual std::vector<int> applyPhysics(Object* o, std::vector<int> force );
};
