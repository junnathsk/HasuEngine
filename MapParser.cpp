#include "MapParser.h"
#include <iostream>

MapParser* MapParser::s_Instance = nullptr;

bool MapParser::Load(){
    // Load map level 1
    if (!Parse("MAP", "Resources/maps/map1.tmx")) {
        return false;
    }
    return true;
}

void MapParser::Clean() {
    std::map<std::string, GameMap*>::iterator it;
    for (it = m_mapDict.begin(); it != m_mapDict.end(); it++) {
        it->second = nullptr;
    }
    m_mapDict.clear();
}

bool MapParser::Parse(std::string id, std::string source){
    TiXmlDocument xml;
    xml.LoadFile(source);

    // check if load error
    if (xml.Error()) {
        std::cerr << "Failed to load : " << source << std::endl;
        return false;
    }

    // Set column count, row count and tile width
    TiXmlElement* root = xml.RootElement();
    int rowCount, colCount;
    int tileSize = 0;

    root->Attribute("width", &colCount);
    root->Attribute("height", &rowCount);
    root->Attribute("tilewidth", &tileSize);

    // Parse tile sets
    TilesetList tileSets;
    for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("tileset")) {
            tileSets.push_back(ParseTileSet(e));
        }
    }

    // Parse Layers
    GameMap* gameMap = new GameMap();
    for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("layer")) {
            TileLayer* tileLayer = ParseTileLayer(e, tileSets, tileSize, rowCount, colCount);
            gameMap->m_mapLayers.push_back(tileLayer);
        }
    }

    m_mapDict[id] = gameMap;
    return true;
}

Tileset MapParser::ParseTileSet(TiXmlElement* xmlTileset){
    Tileset tileSet;
    // Set map name
    tileSet.name_ = xmlTileset->Attribute("name");
    // Set map first ID
    xmlTileset->Attribute("firstgid", &tileSet.firstID_);
    // Set tile count
    xmlTileset->Attribute("tilecount", &tileSet.tileCount_);
    // Set last ID from first ID and tile count
    tileSet.lastID_ = (tileSet.firstID_ + tileSet.tileCount_) - 1;
    // Set amount of columns
    xmlTileset->Attribute("columns", &tileSet.colCount_);
    // Set amount of rows 
    tileSet.rowCount_ = tileSet.tileCount_ / tileSet.colCount_;
    // Set tile size
    xmlTileset->Attribute("tilewidth", &tileSet.tileSize_);
    // Set tile image
    TiXmlElement* image = xmlTileset->FirstChildElement();      // "source" is child element
    tileSet.source_ = image->Attribute("source");

    return tileSet;
}

TileLayer* MapParser::ParseTileLayer(TiXmlElement* xmlLayer, TilesetList tilesets, 
    int tileSize, int rowCount, int colCount){
    TiXmlElement* data{};
    // Check until find "data" in xml map file
    for (TiXmlElement* e = xmlLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("data")) {
            data = e;
            // break after found 
            break;
        }
    }

    if (!data) {
        return nullptr;
    }

    // Get the matrix
    std::string matrix(data->GetText());
    std::istringstream iss(matrix);
    std::string id;

    TileMap tileMap(rowCount, std::vector<int>(colCount, 0));

    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) {
            std::getline(iss, id, ',');
            std::stringstream converter(id);
            converter >> tileMap[row][col];

            if (!iss.good()) {
                break;
            }
        }
    }

    return (new TileLayer(tileSize, rowCount, colCount, tileMap, tilesets));
}


