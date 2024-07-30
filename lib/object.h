#include <SDL2/SDL.h>
#include <string>

class Object {
	public:
		int x; //Objects x position
		int y; //Objects y position
		int w; //Object width
		int h; //Object height
		std::vector<Object*> objects; //All objects in room
		bool c; //Controllable boolean
		std::string name; //Name of object
		SDL_Texture* texture; //Object sprite (texture)

		Object(int x_in, int y_in, int w_in, int h_in, bool c_in, std::string name_in); //Constructor
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

		//Draw object
		virtual void draw(SDL_Renderer* r);
		//Update object
		virtual void update(int x_in, int y_in);

		//Collision detection
		virtual bool isColliding(std::vector<Object*> objects);
		bool rectCollision(Object* obj1, Object* obj2);
		SDL_Texture* createTexture(char* p, SDL_Renderer* r_in);
};



