#pragma once

#include <map>
#include <string>
#include "GameMap.h"
#include "TileLayer.h"
#include "tinyxml.h"

class MapParser{
public:
	bool Load();
	void Clean();

	inline GameMap* GetMap(std::string id) {	return m_mapDict[id];}
	inline static MapParser* GetInstance() {
		if (s_Instance == nullptr) {
			s_Instance = new MapParser();
		}
		return s_Instance;
	}

private:
	// Load xml file
	bool Parse(std::string id, std::string source);
	Tileset ParseTileSet(TiXmlElement* xmlTileset);
	TileLayer* ParseTileLayer(TiXmlElement* xmlLayer, TilesetList tilesets, 
		int tileSize, int rowCount, int colCount);
private:
	MapParser() {};
	static MapParser* s_Instance;
	std::map<std::string, GameMap*> m_mapDict;		// Map Dictionary
};

