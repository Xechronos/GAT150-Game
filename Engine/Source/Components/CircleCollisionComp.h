#pragma once
#include "CollisionComp.h"

class CircleCollisionComp : public CollisionComp {
public:
	CLASS_DECLARATION(CircleCollisionComp);
	CLASS_PROTOTYPE(CircleCollisionComp);

	// Inherited via CollisionComp
	void Initialize() override;

	void Update(float dt) override;

	bool CheckCollision(const CollisionComp* collision) override;

public:
	float radius{ 0 };

};