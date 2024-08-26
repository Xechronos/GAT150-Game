#include "TileMapComp.h"
#include "Framework/Actor.h"
#include "Framework/Scene.h"

FACTORY_REGISTER(TileMapComp)

void TileMapComp::Initialize()
{
	for (int i = 0; i < tiles.size(); i++) {
		int tileIndex = tiles[i];
		if (tileIndex == 0) continue;

		std::string tileName = tileNames[tileIndex];
		auto tile = Factory::Instance().Create<Actor>(tileName);
		if (tile) {
			int x = i % numColumns;
			int y = i / numColumns;

			tile->transform.position = owner->transform.position + Vector2{ x,y } * tileSize;
			owner->scene->AddActor(std::move(tile), true);
		}
	}
}

void TileMapComp::Update(float dt)
{
}

void TileMapComp::Read(const json_t& value)
{
	READ_DATA(value, numColumns);
	READ_DATA(value, numRows);
	READ_DATA(value, tileSize);
	READ_DATA(value, tileNames);
	READ_DATA(value, tiles);
}

void TileMapComp::Write(json_t& value)
{
}

