#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"

Warrior::Warrior(Properties props) : Character (props){
	m_row = 0;
	m_frame = 0;
	m_frameCount = 8;			// max frame
	m_animationSpeed = 120;		// change every 60 frame
}

void Warrior::Update(){
	m_frame = (SDL_GetTicks() / m_animationSpeed) % m_frameCount;
}

void Warrior::Draw(){
	TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Position.X, m_Position.Y, m_Width, m_Height, m_row, m_frame);
}

void Warrior::Clean(){
	TextureManager::GetInstance()->Clean();
}
