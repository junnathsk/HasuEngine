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
	void DrawTile(std::string tileSetID, int x, int y, int tileSize, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
	/// <summary>
	/// Draw Animation
	/// </summary>
	/// <param name="id"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="width"></param>
	/// <param name="height"></param>
	/// <param name="row"></param>
	/// <param name="frame"></param>
	/// <param name="flip"></param>
	void DrawFrame(std::string id, float x, float y, float width, float height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
private:
	TextureManager() {};
	std::map<std::string, SDL_Texture*> textureMap_;
	static TextureManager* s_instance_;
};

