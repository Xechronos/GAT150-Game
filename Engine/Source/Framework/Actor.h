#pragma once
#include "Math/Transform.h"
#include "Components/Component.h"
#include<string>
#include <vector>
#include <memory>
#include <functional>

class Renderer;
class Scene;

class Actor : public Object{
public:
	Actor() = default;
	Actor(const Transform& transform) : transform{ transform } {}
	Actor(const Actor& other);

	CLASS_DECLARATION(Actor)
	CLASS_PROTOTYPE(Actor)

	void Initialize() override;
	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer);

	std::function<void(Actor*)> OnCollisionEnter;
	std::function<void(Actor*)> OnCollisionExit;

	void AddComponent(std::unique_ptr<Component> component);

	template<typename T> T* GetComponent();
	template<typename T> T* GetComponent(const std::string& name);
	template<typename T> std::vector<T*> GetComponents();


	virtual void OnCollision(Actor* actor) {}

	friend class Scene;

public:
	std::string tag;
	float lifespan = 0.0f;
	bool destroyed = false;
	Transform transform;
	Scene* scene{ nullptr };

protected:
	std::vector<std::unique_ptr<Component>> components;

};

template<typename T>
inline T* Actor::GetComponent()
{
	for (auto& component : components)
	{
		T* result = dynamic_cast<T*>(component.get());
		if (result) return result;
	}
	return nullptr;
}

template<typename T>
inline T* Actor::GetComponent(const std::string& name)
{
	for (auto& component : components)
	{
		T* result = dynamic_cast<T*>(component.get());
		if (result && IsEqualIgnoreCase(name, result->name)) return result;
	}
	return nullptr;
}

template<typename T>

inline std::vector<T*> Actor::GetComponents()
{
	std::vector<T*> results;
	for (auto& component : components)
	{
		T* result = dynamic_cast<T*>(component.get());
		if (result) results.push_back(result);
	}
	return results;
}


	
