class Room1 : public Room{
	public:
		//Room specific fields can be used for game logic
		void update(int key);
		void create(SDL_Renderer* r);
};
