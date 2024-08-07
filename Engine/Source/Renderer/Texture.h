#pragma once
#include"Resources/Resource.h"
#include "Math/Vector2.h"
#include "Renderer/Renderer.h"
#include <string>

class Texture : public Resource
{
public:
	Texture() = default;
	~Texture();

	// Inherited via Resource
	bool Create(std::string name, ...) override;
	bool Load(const std::string& filename, class Renderer& renderer);

	Vector2 GetSize();

	friend class Renderer;

private:
	struct SDL_Texture* m_texture{ nullptr };

};