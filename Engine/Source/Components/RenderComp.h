#pragma once
#include "Component.h"

class RenderComp : public Component {
public:
	virtual void Draw(class Renderer& renderer) = 0;
};