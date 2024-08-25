#pragma once
#include "RenderComp.h"

class TextComp : public RenderComp {
public:
	TextComp() = default;
	TextComp(const TextComp& other);

	CLASS_DECLARATION(TextComp);
	CLASS_PROTOTYPE(TextComp);

	// Inherited via RenderComp
	void Initialize() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	void SetText(const std::string& text);

public:
	std::string text;
	std::string fontName;
	int fontSize = 0;
	Color color{ 1,1,1,1 };

private:
	std::unique_ptr<class Text> m_text;
	bool textChanged = true;
};