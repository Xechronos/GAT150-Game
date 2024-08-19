#pragma once
#include "Component.h"

class CollisionComp : public Component {
public:
	virtual bool CheckCollision(const CollisionComp* collision) = 0;
};