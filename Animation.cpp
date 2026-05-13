#include "Animation.h"
#include "TextureManager.h"

Animation::Animation(){

}

void Animation::Update() {
	m_spriteFrame = (SDL_GetTicks() / m_animSpeed) % m_maxFrameCount;
}

void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight){
	TextureManager::GetInstance()->DrawFrame(m_textureID, x, y, spriteWidth, spriteHeight, m_spriteRow, m_spriteFrame, m_flip);
}

void Animation::SetProps(std::string textureID, int spriteRow, int maxFrameCount, int animSpeed, SDL_RendererFlip flip){
	m_textureID = textureID;
	m_spriteRow = spriteRow;
	m_maxFrameCount = maxFrameCount;
	m_animSpeed = animSpeed;
	m_flip = flip;
}

