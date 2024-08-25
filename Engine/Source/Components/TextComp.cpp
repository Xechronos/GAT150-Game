#include "TextComp.h"
#include "Resources/ResourceManager.h"
#include "Renderer/Font.h"
#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Framework/Actor.h"

FACTORY_REGISTER(TextComp)

void TextComp::Initialize()
{
	if (!m_text && !fontName.empty()) {
		auto font = ResourceManager::Instance().Get<Font>(fontName, fontSize);
		m_text = std::make_unique<Text>(font);
	}
}

TextComp::TextComp(const TextComp& other)
{
	text = other.text;
	fontName = other.fontName;
	fontSize = other.fontSize;
	color = other.color;

	textChanged = true;
	m_text = std::make_unique<Text>(*other.m_text.get());
}

void TextComp::Read(const json_t& value)
{
	READ_DATA(value, text);
	READ_DATA(value, fontSize);
	READ_DATA(value, fontName);
	READ_DATA(value, color);
}

void TextComp::Write(json_t& value)
{
}


void TextComp::Update(float dt)
{
}

void TextComp::Draw(Renderer& renderer)
{
	if (textChanged) {
		textChanged = false;
	m_text->Create(renderer, text, color);
	}

	renderer.DrawTexture(m_text->GetTexture(), owner->transform);
}

void TextComp::SetText(const std::string& text)
{
	if (this->text != text) {
	this->text = text;
	textChanged = true;
	}
}
