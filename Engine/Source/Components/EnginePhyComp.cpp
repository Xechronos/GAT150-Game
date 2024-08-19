#include "EnginePhyComp.h"
#include "Framework/Actor.h"

class RegisterEnginePhyComp {
public: RegisterEnginePhyComp() {
	Factory::Instance().Register<EnginePhyComp>("EnginePhyComp");
}
}; static RegisterEnginePhyComp register_instance;

void EnginePhyComp::Initialize()
{
}

void EnginePhyComp::Update(float dt)
{
	velocity += acceleration * dt;
	owner->transform.position += velocity * dt;
	velocity *= 1.0f / (1.0f + damping * dt);

	acceleration = Vector2{ 0,0 };
}

void EnginePhyComp::Read(const json_t& value)
{
	PhysicsComp::Read(value);
}

void EnginePhyComp::Write(json_t& value)
{
}
void EnginePhyComp::ApplyForce(const Vector2& force)
{
	assert(mass != 0);
	acceleration += force / mass;
}

void EnginePhyComp::SetPosition(const Vector2& position)
{
	owner->transform.position = position;
}
