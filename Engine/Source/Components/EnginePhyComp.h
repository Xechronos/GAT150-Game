#pragma once
#include "PhysicsComp.h"

class EnginePhyComp : public PhysicsComp {
public:
	CLASS_DECLARATION(EnginePhyComp)
	// Inherited via PhysicsComp
	void Initialize() override;
	void Update(float dt) override;
	void ApplyForce(const Vector2& force) override;
	void SetPosition(const Vector2& position) override;
	void SetVelocity(const Vector2& velocity) override { this->velocity = velocity; }
};