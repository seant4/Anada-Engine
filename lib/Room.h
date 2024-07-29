#include <SDL2/SDL.h>
#include <string>

class Room{
	public:
		std::vector<Object*> objects;
		int n;

	Room();
	void create();
	void draw(SDL_Surface* s);
	void addObject(Object* p);
	std::vector<Object*> getObjects();
};

