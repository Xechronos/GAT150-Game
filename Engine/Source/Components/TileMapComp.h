#pragma once
#include "Component.h"
#include <vector>

class TileMapComp : public Component {
public:
	TileMapComp() = default;

	CLASS_DECLARATION(TileMapComp)
	CLASS_PROTOTYPE(TileMapComp)

	void Initialize() override;
	void Update(float dt) override;

public:
	int numColumns;
	int numRows;
	Vector2 tileSize{ 0,0 };

	std::vector<std::string> tileNames;
	std::vector<int> tiles;
};