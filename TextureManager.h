#pragma once

#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <map>

class TextureManager{
public:
	static TextureManager* GetInstance() { 
		if (s_instance_ == nullptr) {
			s_instance_ = new TextureManager();
		}
		return s_instance_;
	}

	bool Load(std::string id, std::string filePath);
	// Called when not needed
	void Drop(std::string id);
	// Called when quitting program
	void Clean();

	void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
private:
	TextureManager() {};
	std::map<std::string, SDL_Texture*> textureMap_;
	static TextureManager* s_instance_;
};

