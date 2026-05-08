#include "TextureManager.h"
#include "Engine.h"

TextureManager* TextureManager::s_instance_ = nullptr;

bool TextureManager::Load(std::string id, std::string filePath){
	// Load image using SDL_Surface
	SDL_Surface* surface = IMG_Load(filePath.c_str());
	if (surface == nullptr) {
		SDL_Log("Failed to load Texture: %s, %s", filePath.c_str(), SDL_GetError());
		return false;
	}
	// Create Texture from Surface
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	if (surface == nullptr) {
		SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
		return false;
	}
	
	textureMap_[id] = texture;
	return true;
}


void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip){
	SDL_Rect srcRect = { 0,0, width, height };
	SDL_Rect desRect = { x,y, width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), textureMap_[id], &srcRect, &desRect, 0, nullptr, flip);
}

void TextureManager::Drop(std::string id){
	SDL_DestroyTexture(textureMap_[id]);
	textureMap_.erase(id);
}

void TextureManager::Clean() {
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = textureMap_.begin(); it != textureMap_.end(); it++)
		SDL_DestroyTexture(it->second);
	textureMap_.clear();
	SDL_Log("Texture Cleaned!");
}