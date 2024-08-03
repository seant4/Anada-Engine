#include <vector>
#include "../../object.h"

std::vector<int> applyPhysics(Object* o, std::vector<int> force){	
	//Apply gravity
	o->vel[0] += force[0];
	o->vel[1] += (force[1] + 1); //gravity
	int x_fut = o->vel[0] + o->x;
	int y_fut = o->vel[1] + o->y;
	return std::vector<int>{x_fut, y_fut};
}

bool rectCollision(Object* obj1, Object* obj2){
	int x1r = obj1->x + obj1->w;
	int y1b = obj1->y + obj1->h;
	int x2r = obj2->x + obj2->w;
	int y2b = obj2->y + obj2->h;
	if(obj1->x >= x2r || obj2->x >= x1r){
		return false;
	}

	if(obj1->y >= y2b || obj2->y >= y1b){
		return false;
	}
	return true;
}

bool isColliding(Object* obj1, Object* obj2){
	return(rectCollision(obj1, obj2));
}
