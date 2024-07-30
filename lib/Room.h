#include <SDL2/SDL.h>
#include <string>

class Room{
	public:
		std::vector<Object*> objects; //All objects in room
		int n; //Number of objects in room
		SDL_Renderer* r; //Renderer

	Room();
	~Room();
	void update();
	void draw(SDL_Renderer* r);
	void addObject(Object* p);
	void create(SDL_Renderer* r);
	std::vector<Object*> getObjects();
};

