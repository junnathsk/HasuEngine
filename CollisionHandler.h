#pragma once
#include "SDL.h"
#include <vector>
#include "TileLayer.h"
#include "GameMap.h"
#include "Engine.h"

class CollisionHandler{
public:
	static CollisionHandler* GetInstance() {
		if (s_instance == nullptr) {
			s_instance = new CollisionHandler();
		}
		return s_instance;
	}

	bool CheckCollision(SDL_Rect a, SDL_Rect b);
	bool MapCollision(SDL_Rect a);

private:
	CollisionHandler();
	TileMap m_collisionTileMap;
	TileLayer* m_collisionLayer;
	static CollisionHandler* s_instance;
};

