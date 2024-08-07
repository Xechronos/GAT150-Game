#pragma once
#include "RenderComp.h"
#include "Renderer/Texture.h"

class TextureComp : public RenderComp {
public:
	void Initialize() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

public:
	std::string textureName;
	res_t<Texture> texture;
};