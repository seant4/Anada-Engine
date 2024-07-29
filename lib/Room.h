#include <SDL2/SDL.h>
#include <string>

class Room{
	public:
		std::vector<Object*> objects;
		int n;

	Room();
	~Room();
	void update();
	void draw(SDL_Surface* s);
	void addObject(Object* p);
	virtual void create() = 0;
	std::vector<Object*> getObjects();
};

