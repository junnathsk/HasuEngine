#pragma once

#include "SDL.h"
#include <string>

class Animation{
public:
	Animation();

	void Update();
	void Draw(float x, float y, int spriteWidth, int spriteHeight);
	void SetProps(std::string textureID, int spriteRow, int maxFrameCount, int animSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	int m_spriteRow;
	int m_spriteFrame;
	int m_animSpeed;
	int m_maxFrameCount;
	std::string m_textureID;
	SDL_RendererFlip m_flip;
};

