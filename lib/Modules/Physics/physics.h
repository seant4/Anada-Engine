#pragma once
#include "../../object.h"

std::vector<int> applyPhysics(Object* o, std::vector<int> force);
bool rectCollision(Object* obj1, Object* obj2);
