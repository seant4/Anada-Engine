bool rectCollision(Object* obj1, Object* obj2){
	int x1r = obj1->getX() + obj1->getW();
	int y1b = obj1->getY() + obj1->getH();
	int x2r = obj2->getX() + obj2->getW();
	int y2b = obj2->getY() + obj2->getH();

	if(obj1->getX() >= x2r || obj2->getX() >= x1r){
		return false;
	}

	if(obj1->getY() >= y2b || obj2->getY() >= y1b){
		return false;
	}

	return true;
}
