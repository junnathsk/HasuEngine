#include "TileLayer.h"
#include "TextureManager.h"

TileLayer::TileLayer(int tileSize, int rowCount, int colCount, 
	TileMap tileMap, TilesetList tilesetList) : 
	m_tileSize(tileSize), m_colCount(colCount), m_rowCount(rowCount), m_tileMap(tileMap), m_tileSetList(tilesetList) {
	// Initialize everything

	for (unsigned int i = 0; i < m_tileSetList.size(); i++) {
		TextureManager::GetInstance()->Load(m_tileSetList[i].name_, "Resources/maps/" + m_tileSetList[i].source_);
	}

}

void TileLayer::Update() {

}

void TileLayer::Render() {
	for (unsigned int i = 0; i < m_rowCount; i++) {
		for (unsigned int j = 0; j < m_colCount; j++) {
			int tileID = m_tileMap[i][j];

			if (tileID == 0) {
				// Empty tile, draw nothing
				continue;
			} else {
				int index{};		// ID
				if (m_tileSetList.size() > 1) {
					// Normalize if tile ID is bigger than first ID or smaller than last ID
					for (unsigned int k = 1; k < m_tileSetList.size(); k++) {
						if (tileID > m_tileSetList[k].firstID_ && tileID < m_tileSetList[k].lastID_) {
							tileID = tileID + m_tileSetList[k].tileCount_ - m_tileSetList[k].lastID_;
							index = k;
							break;
						}
					}
				}
				Tileset ts = m_tileSetList[index];
				int tileRow = tileID / ts.colCount_;
				int tileCol = tileID - (tileRow * ts.colCount_) - 1;

				// if this tile is on the last columns
				if (tileID % ts.colCount_ == 0) {
					tileRow--;
					tileCol = ts.colCount_ - 1;
				}

				// Draw tiles
				TextureManager::GetInstance()->DrawTile(ts.name_,j * ts.tileSize_, i * ts.tileSize_, ts.tileSize_, tileRow, tileCol);
			}	
		}
	}
}