class Frog : public Object{
	public:
		Frog(int x_in, int y_in, int w_in, int h_in, bool c_in, std::string name_in, SDL_Renderer* r);
		void draw(SDL_Renderer* r) const;
		void update(int x_in, int y_in) override;
		bool isColliding(std::vector<Object*> objects) override;
};
