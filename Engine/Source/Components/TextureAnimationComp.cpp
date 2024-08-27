#include "TextureAnimationComp.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Resources/ResourceManager.h"
#include "Engine.h"

FACTORY_REGISTER(TextureAnimationComp);

void TextureAnimationComp::Initialize()
{
	TextureComp::Initialize();
}

void TextureAnimationComp::Update(float dt)
{
	TextureComp::Update(dt);
	frameTimer - dt;
	if (frameTimer <= 0) {
		frameTimer = 1.0f / fps;
		frame++;
		if (frame > endFrame && loop == true) frame = startFrame;
	}

	Vector2 size = texture.
}

void TextureAnimationComp::Read(const json_t& value)
{
}

void TextureAnimationComp::Write(json_t& value)
{
}

