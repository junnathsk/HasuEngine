#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Input.h"

Warrior::Warrior(Properties props) : Character (props){
	// Initialize Animation
	m_animation = new Animation();
	// SetAnimation
	m_animation->SetProps(m_TextureID, 0, 8, 120);

	// Initialize RigidBody
	m_rigidBody = new RigidBody();
}

void Warrior::Update(float dt){

	// Set Force to 0 when not moving
	m_rigidBody->UnSetForce();
	m_rigidBody->SetGravity(0);

	// Move Left
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		m_animation->SetProps(m_TextureID, 0, 8, 120, SDL_FLIP_HORIZONTAL);
		m_rigidBody->ApplyForceX(2 * BACKWARD);
	}
	// Move Right
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		m_animation->SetProps(m_TextureID, 0, 8, 120);
		m_rigidBody->ApplyForceX(2 * FORWARD);
	}
	// Move Up
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W)) {
		m_animation->SetProps(m_TextureID, 0, 8, 120);
		m_rigidBody->ApplyForceY(2 * UPWARD);
	}
	// Move Down
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_S)) {
		m_animation->SetProps(m_TextureID, 0, 8, 120);
		m_rigidBody->ApplyForceY(2 * DOWNWARD);
	}

	// Update Rigidbody
	m_rigidBody->Update(dt);

	m_transform.X += m_rigidBody->GetPosition().X;
	m_transform.Y += m_rigidBody->GetPosition().Y;

	// Update Animation
	m_animation->Update();
}

void Warrior::Draw(){

	m_animation->Draw(m_transform.X, m_transform.Y, m_Width, m_Height);
	//TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Position.X, m_Position.Y, m_Width, m_Height, m_row, m_frame);
}

void Warrior::Clean(){
	TextureManager::GetInstance()->Clean();
}
