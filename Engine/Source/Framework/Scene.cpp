#include "Scene.h"
#include "Actor.h"
#include "Core/Factory.h"
#include "Components/CollisionComp.h"
#include "Core/EAssert.h"
#include <algorithm>

void Scene::Initialize()
{
	for (auto& actor : actors) {
		actor->Initialize();
	}
}

Scene::Scene(const Scene& other)
{
	ASSERT(false);
}

void Scene::Read(const json_t& value)
{
	if (HAS_DATA(value, actors) && GET_DATA(value, actors).IsArray()) {
		for (auto& actorValue : GET_DATA(value, actors).GetArray()) {
			auto actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
			actor->Read(actorValue);

			bool prototype = false;
			READ_DATA(actorValue, prototype);

			if(prototype){
				std::string name = actor->name;
				Factory::Instance().RegisterPrototype<Actor>(name, std::move(actor));
			}
			else {
				AddActor(std::move(actor));
			}
		}
	}
}

void Scene::Write(json_t& value)
{

}

void Scene::Update(float dt)
{

	for (auto& actor : actors) {
		if (actor->active) actor->Update(dt);
	}

	/*for (auto& actor1 : actors) {
		CollisionComp* collision1 = actor1->GetComponent<CollisionComp>();
		if (!collision1) continue;

		for (auto& actor2 : actors) {
			if (actor1 == actor2) continue;

			CollisionComp* collision2 = actor2->GetComponent<CollisionComp>();
			if (!collision2) continue;

			if (collision1->CheckCollision(collision2)) {
				if (actor1->OnCollisionEnter) actor1->OnCollisionEnter(actor2.get());
				if (actor2->OnCollisionEnter) actor2->OnCollisionEnter(actor1.get());
			}
		}
	}*/

	/*auto iter = m_actors.begin();
	while (iter != m_actors.end()) {
		iter = ((*iter)->m_destroyed) ? m_actors.erase(iter) : iter++;
	}*/

	std::erase_if(actors, [](auto& actor) {return actor->destroyed;});


	for (auto& actor1 : actors) {
		for (auto& actor2 : actors) {
			if (actor1 == actor2 || (actor1->destroyed || actor2->destroyed)) continue;
			Vector2 direction = actor1->transform.position - actor2->transform.position;
			float distance = direction.Length();
		}

	}
}

void Scene::Draw(Renderer& renderer)
{
	for (auto& actor : actors) {
		actor->Draw(renderer);
	}
}

void Scene::AddActor(std::unique_ptr<Actor> actor, bool initialize)
{
	actor->scene = this;
	if (initialize) actor->Initialize();
	actors.push_back(std::move(actor));
}

void Scene::RemoveAll()
{
	actors.clear();
}

