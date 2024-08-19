#include "CircleCollisionComp.h"
#include "Framework/Actor.h"

FACTORY_REGISTER(CircleCollisionComp)

void CircleCollisionComp::Initialize()
{
}

void CircleCollisionComp::Update(float dt)
{
}

bool CircleCollisionComp::CheckCollision(const CollisionComp* collision)
{
    float r1 = radius;
    float r2 = (dynamic_cast<const CircleCollisionComp*>(collision))->radius;
    float distance = owner->transform.position.Distance(collision->owner->transform.position);
    return (distance <= r1 + r2);
}

void CircleCollisionComp::Read(const json_t& value)
{
    READ_DATA(value, radius);
}

void CircleCollisionComp::Write(json_t& value)
{
}

