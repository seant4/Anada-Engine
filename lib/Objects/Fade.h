#pragma once
#include "../Object.h"

//class RoomName(s) here;

class Fade: public Object{
    public:
		//TODO: Debloat fade
		//xi = 255 to fade in (to transparent), 0 to fade out (to black)
		//yi = speed of transition
		//wi = Room to transition too (if you want the fader to handle that)
        Fade(int xi, int yi, int wi, int hi, bool ci, std::string namei, SDL_Renderer* r);
        ~Fade();
		Uint8 timer;
		int fade;
		int amount;
		int room;
		//Returns true when fading is complete
        bool update(int x, int y);
		void draw(SDL_Renderer* r) override;
};
