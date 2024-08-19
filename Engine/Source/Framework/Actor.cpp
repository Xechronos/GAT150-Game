#include "Actor.h"
#include "Components/RenderComp.h"
#include "Core/Factory.h"
#include <iostream>

FACTORY_REGISTER(Actor)

void Actor::Initialize()
{
	for (auto& component : components) {
		component->Initialize();
	}
}

void Actor::Read(const json_t& value)
{
	Object::Read(value);

	READ_DATA(value, tag);
	READ_DATA(value, lifespan);

	if (HAS_DATA(value, transform)) transform.Read(GET_DATA(value, transform));

	if (HAS_DATA(value, components) && GET_DATA(value, components).IsArray()) {
		for (auto& compValue : GET_DATA(value, components).GetArray()) {
			std::string type;
			READ_DATA(compValue, type);

			auto component = Factory::Instance().Create<Component>(type);
			if (!component) {
				std::cerr << "Could not create component:" << type << std::endl;
				continue;
			}
			component->Read(compValue);

			AddComponent(std::move(component));
		}
	}
}

void Actor::Write(json_t& value)
{
}

void Actor::Update(float dt)
{
	if (lifespan != 0) {
		lifespan -= dt;
		if (lifespan <= 0) {
			destroyed = true;
		}
	}

	for (auto& component : components) {
		component->Update(dt);
	}


	/*transform.position += (m_velocity * dt);
	m_velocity *= 1.0f / (1.0f + m_damping * dt);*/
}

void Actor::Draw(Renderer& renderer)
{
	for (auto& component : components) {
		RenderComp* renderComp = dynamic_cast<RenderComp*>(component.get());
		if (renderComp) {
			renderComp->Draw(renderer);
		}
	}
}

void Actor::AddComponent(std::unique_ptr<Component> component)
{
	component->owner = this;
	components.push_back(std::move(component));
}

