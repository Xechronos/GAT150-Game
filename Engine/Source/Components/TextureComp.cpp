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
	if (texture && source.w == 0 && source.h == 0) {
		source.x = 0;
		source.y = 0;
		source.w = (int)texture->GetSize().x;
		source.h = (int)texture->GetSize().y;
	}
}

void TextureComp::Update(float dt)
{
}

void TextureComp::Draw(Renderer& renderer)
{
	Transform transform = owner->transform;
	renderer.DrawTexture(texture, transform, source);
}

void TextureComp::Read(const json_t& value)
{
	READ_DATA_REQUIRED(value, textureName);
	READ_DATA(value, source);
}

void TextureComp::Write(json_t& value)
{
}