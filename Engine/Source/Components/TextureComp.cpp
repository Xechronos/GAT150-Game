#include "TextureComp.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Resources/ResourceManager.h"
#include "engine.h"

FACTORY_REGISTER(TextureComp)

void TextureComp::Initialize()
{
	if (!textureName.empty()) {
		texture = ResourceManager::Instance().Get<Texture>(textureName, owner->scene->engine->GetRenderer());
	}
}

void TextureComp::Update(float dt)
{
}

void TextureComp::Draw(Renderer& renderer)
{
	Transform transform = owner->transform;
	renderer.DrawTexture(texture, transform, true);
}

void TextureComp::Read(const json_t& value)
{
	READ_DATA_REQUIRED(value, textureName);
}

void TextureComp::Write(json_t& value)
{
}