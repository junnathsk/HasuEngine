#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"

Warrior::Warrior(Properties props) : Character (props){
	// Initialize Animation
	m_animation = new Animation();
	m_animation->SetProps(m_TextureID, 0, 8, 120);

	// Initialize RigidBody
	m_rigidBody = new RigidBody();
}

void Warrior::Update(float dt){
	// Update Animation
	m_animation->Update();

	m_Position.X += m_rigidBody->GetPosition().X;
	m_Position.Y += m_rigidBody->GetPosition().Y;
	

	m_rigidBody->Update(1);
}

void Warrior::Draw(){

	m_animation->Draw(m_Position.X, m_Position.Y, m_Width, m_Height);
	//TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Position.X, m_Position.Y, m_Width, m_Height, m_row, m_frame);
}

void Warrior::Clean(){
	TextureManager::GetInstance()->Clean();
}
