#include <SDL2/SDL.h>
#include <string>

class Object {
	public:
		int x;
		int y;
		int w;
		int h;
		std::vector<Object*> objects;
		bool c;
		std::string name;

		Object(int x_in, int y_in, int w_in, int h_in, bool c_in, std::string name_in);
		int getX();
		int getY();
		int getW();
		int getH();
		void setX(int x_in);
		void setY(int y_in);
		void setObjects(std::vector<Object*> objects);
		bool playerControll();
		std::string getName();
		virtual void draw(SDL_Surface* s) const = 0;
		virtual void update(int x_in, int y_in) = 0;
		virtual bool isColliding(std::vector<Object*> objects) = 0;
};


class Player : public Object{
	public:
		Player(int x_in, int y_in, int w_in, int h_in, bool c_in, std::string name_in);
		void draw(SDL_Surface* s) const override;
		void update(int x_in, int y_in) override;
		bool isColliding(std::vector<Object*> objects) override;
};
