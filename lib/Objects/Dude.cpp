/* Example of an Entity implementation
 *
 * This Entity has an animation cycle, and is affected by physics
 *
 * The goal of this is to proide context as to how to design entities
 */
#include <vector>
#include "../Modules/Visuals/createTexture.h" //Allows us to give it a texture
#include "../../renderer.h" //Required for drawing to the screen
#include "../Modules/Physics/physics.h" //Uses the physics module for physics support
#include "Dude.h" //Header file of entity

void drawDude(Dude d){
	/* Destination of texture from sprite
	 * x = x position: X position of where to draw the sprite
	 * y = y position: Y position of where to draw the sprite
	 * w = width: Width of the sprite to draw
	 * h = height: Height of sprite to draw
	 */
	SDL_Rect dstrect = {d.x,d.y,d.w,d.h};
	/* Source of texture from sprite sheet
	 * O = offset: X offset of image in our spritesheet
	 * A = animation frame: determines which frame we are on
	 * H = height: When multiplied by a, allows us to move up and down the spritesheet for our animation
	 * w = width
	 */
	SDL_Rect srcrect = {d.o,d.a * d.h,d.w,d.h};
	/* Adds the frame to the render stack
	 * Renderer: The global renderer stack
	 * d.Texture: Texture to draw
	 */
	SDL_RenderCopy(renderer, d.texture, &srcrect, &dstrect);
}

void updateDude(Dude* d){
	/* This animation logic allows us to have the frog blink every 4th frame, 
	 * 	creating a more natural blinking animation (instead of a steady constant one)
	 *
	 * Our spritesheet contains 3 animations frames, so our variable a allows us to keep track of
	 * which frame we are on. The f variable keeps track of which frame of the game we are on, to 
	 * determine how many frames have past so we know when we are on every 4th. b is a boolean that
	 * tells us whether we are currently animating our blink. This may be unecisarry.
	 */
	if(d->a == 2){
		d->a = 0;
		d->b = false;
	}
	if((d->f % 25) == 0){
		d->b = true;
	}
	if(d->b){
		d->a++;
	}
	d->f++;

	/* This allows us to apply physics to the object. 
	 * The entityPhysics function will give us a updated velocity vector based on 
	 * our current velocity, positions and a force vector. (For this exaple our force is <0,0>
	 * 	though, it will still be affected by phsysics. This could be updated to apply a 
	 * 	horizontal or vertical force based on player input
	 */
	std::vector<int> acc = entityPhysics(d->x,d->y, d->vel, std::vector<int>{0,0});

	/* By applying the physics to a different object, we can check if it collides with the floor, and 
	 * update our current objects position accordingly
	 */
	int x_fut = acc[0] + d->x;
	int y_fut = acc[1] + d->y;
	if(rectCollision(x_fut, y_fut, d->w, d->h, 0,720,1280,1)){ // If we collide with the floor
		d->vel=std::vector<int>{acc[0], 0}; //Move in the x direction, but halt our Y velocity
		d->x = x_fut;
	}else{ //We must be in the air
		d->vel = acc; // Update our velocity
		d->x = x_fut; // Set our positino to the newly calculated ones
		d->y = y_fut;
	}
}
