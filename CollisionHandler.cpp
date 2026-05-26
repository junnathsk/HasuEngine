#include "CollisionHandler.h"

CollisionHandler* CollisionHandler::s_instance = nullptr;

CollisionHandler::CollisionHandler() {
    m_collisionLayer = (TileLayer*)Engine::GetInstance()->GetMap()->GetMapLayers().front();
    m_collisionTileMap = m_collisionLayer->GetTileMap();
}

bool CollisionHandler::CheckCollision(SDL_Rect a, SDL_Rect b){
    bool x_coll = (a.x < b.x + b.w) && (a.x + a.w > b.x);
    bool y_coll = (a.y < b.y + b.h) && (a.y + a.h > b.y);
    return (x_coll && y_coll);
}

bool CollisionHandler::MapCollision(SDL_Rect a){
    int tileSize = 32;
    int rowCount = 20;
    int colCount = 60;

    int leftTile = a.x / tileSize;
    int rightTile = (a.x + a.w) / tileSize;

    int topTile = a.y / tileSize;
    int bottomTile = (a.y + a.h) / tileSize;

    if (leftTile < 0) leftTile = 0;
    if (rightTile > colCount) rightTile = colCount;

    if (topTile < 0) topTile = 0;
    if (bottomTile > rowCount) bottomTile = rowCount;

    for (int i = leftTile; i <= rightTile; ++i) {
        for (int j = topTile; j <= bottomTile; ++j) {
            if (m_collisionTileMap[j][i] > 0) {
                return true;
            }
        }
    }
    return false;
}
