#include "TextureComp.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Resources/ResourceManager.h"

void TextureComp::Initialize()
{
	if (!textureName.empty()) {
		/*texture = ResourceManager::Instance().Get<Texture>();*/
	}
}

void TextureComp::Update(float dt)
{
}

void TextureComp::Draw(Renderer& renderer)
{
	Transform transform = owner->GetTransform();
	renderer.DrawTexture(texture.get(), transform.position.x, transform.position.y, transform.rotation);
}
