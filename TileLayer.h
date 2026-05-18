#pragma once

#include "Layer.h"
#include <string>
#include <vector>

struct Tileset {
	int firstID_, lastID_;
	int rowCount_, colCount_;		// how many rows and columens
	int	tileCount_;					// how many tiles
	int tileSize_;					// size per tile 32x32
	std::string name_, source_;		
};

using TilesetList = std::vector<Tileset>;
using TileMap = std::vector<std::vector<int>>;

class TileLayer : public Layer{
public:
	TileLayer(int tileSize, int rowCount, int colCount, 
		TileMap tileMap, TilesetList tilesetList);
	virtual void Update();
	virtual void Render();

	inline TileMap GetTileMap() { return m_tileMap; }
private:
	int m_tileSize;
	int m_rowCount, m_colCount;
	TileMap m_tileMap;
	TilesetList m_tileSetList;			// tilesets
};

