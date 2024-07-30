class Room1 : public Room{
	public:
		SDL_Texture* background;
		//Room specific fields can be used for game logic
		void draw(SDL_Renderer* r);
		void update(int key);
		void create(SDL_Renderer* r);
};
