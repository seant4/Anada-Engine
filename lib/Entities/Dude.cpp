/* Example of an Entity implementation
 *
 * This Entity has an animation cycle, and is affected by physics
 *
 * The goal of this is to proide context as to how to design entities
 */
#include <vector>
#include "../Modules/Visuals/createTexture.h" //Allows us to give it a texture
#include "../Modules/Visuals/renderSprite.h"
#include "../../renderer.h" //Required for drawing to the screen
#include "../Modules/Physics/physics.h" //Uses the physics module for physics support
#include "Dude.h" //Header file of entity

void Dude::draw(){
	/* Draw routine
	 * srcrect = array containing the source position of sprite in sprite sheet
	 * dstrect = array containing the destination position of sprite on screen
	 */
	int srcrect[] = {o,a*h,w,h};
	int dstrect[] = {x,y,w,h};
	renderSprite(srcrect, dstrect, texture);
}

void Dude::update(){
	/* This animation logic allows us to have the frog blink every 4th frame, 
	 * 	creating a more natural blinking animation (instead of a steady constant one)
	 *
	 * Our spritesheet contains 3 animations frames, so our variable a allows us to keep track of
	 * which frame we are on. The f variable keeps track of which frame of the game we are on, to 
	 * determine how many frames have past so we know when we are on every 4th. b is a boolean that
	 * tells us whether we are currently animating our blink. This may be unecisarry.
	 */
	if(a == 2){
		a = 0;
		b = false;
	}
	if((f % 25) == 0){
		b = true;
	}
	if(b){
		a++;
	}
	f++;

	/* This allows us to apply physics to the object. 
	 * The entityPhysics function will give us a updated velocity vector based on 
	 * our current velocity, positions and a force vector. (For this exaple our force is <0,0>
	 * 	though, it will still be affected by phsysics. This could be updated to apply a 
	 * 	horizontal or vertical force based on player input
	 */
	std::vector<int> acc = entityPhysics(x,y, vel, std::vector<int>{0,0});

	/* By applying the physics to a different object, we can check if it collides with the floor, and 
	 * update our current objects position accordingly
	 */
	int x_fut = acc[0] + x;
	int y_fut = acc[1] + y;
	if(rectCollision(x_fut, y_fut, w, h, 0,720,1280,1)){ // If we collide with the floor
		vel=std::vector<int>{acc[0], 0}; //Move in the x direction, but halt our Y velocity
		x = x_fut;
	}else{ //We must be in the air
		vel = acc; // Update our velocity
		x = x_fut; // Set our positino to the newly calculated ones
		y = y_fut;
	}
}

