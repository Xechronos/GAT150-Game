#pragma once
#include "RenderComp.h"
#include "Renderer/Texture.h"


class TextureComp : public RenderComp {
public:
	CLASS_DECLARATION(TextureComp)
	CLASS_PROTOTYPE(TextureComp)

	void Initialize() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

public:
	std::string textureName;
	Rect source;
	res_t<Texture> texture;
};