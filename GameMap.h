#pragma once

#include "Layer.h"
#include <vector>

class GameMap {
public:
	void Render() {
		for (unsigned int i = 0; i < m_mapLayers.size(); i++) {
			m_mapLayers[i]->Render();
		}
	}

	void Update() {
		for (unsigned int i = 0; i < m_mapLayers.size(); i++) {
			m_mapLayers[i]->Update();
		}
	}

	std::vector<Layer*>GetMapLayers() { return m_mapLayers; }

private:
	friend class MapParser;
	std::vector<Layer*> m_mapLayers;
};
