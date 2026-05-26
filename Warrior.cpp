#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Input.h"
#include "Camera.h"

#include "CollisionHandler.h"

Warrior::Warrior(Properties props) : Character (props){
	// Initialize Animation
	m_animation = new Animation();
	m_animation->SetProps(m_TextureID, 0, 4, 120);
	// Initialize RigidBody
	m_rigidBody = new RigidBody();
	m_rigidBody->SetGravity(6.2f);

	pos_ = { 100.0f, 200.0f };
	//m_rigidBody->ApplyVelocity({ 2.0f, 0.0f });
	

	m_collider = new Collider;
	m_collider->SetBuffer(0, 0, 0, 0);

	m_jumpTime = JUMP_TIME;
	m_jumpForce = JUMP_FORCE;

}

void Warrior::Update(float dt){

	// Set Force to 0 when not moving
	m_rigidBody->ResetForce();
	m_animation->SetProps(m_TextureID, 0, 4, 120);

	// Move Left
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		m_animation->SetProps(m_TextureID, 1, 4, 120, SDL_FLIP_HORIZONTAL);
		m_rigidBody->SetForceX(4 * BACKWARD);
	}
	// Move Right
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		m_animation->SetProps(m_TextureID, 1, 4, 120);
		m_rigidBody->SetForceX(4 * FORWARD);
	}

	//// Move Up
	//if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W)) {
	//	m_rigidBody->SetForceY(4 * UPWARD);
	//}
	//// Move Down
	//if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_S)) {
	//	m_rigidBody->SetForceY(4 * DOWNWARD);
	//}

	// Jump
	if (Input::GetInstance()->GetIsTrigger(SDL_SCANCODE_J) 
		&& m_isOnGround) {
		m_isJumping = true;
		m_isOnGround = false;
		m_rigidBody->SetForceY(UPWARD * m_jumpForce);
	}
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_J) && m_isJumping && m_jumpTime > 0) {
		m_jumpTime -= dt;
		m_rigidBody->SetForceY(UPWARD * m_jumpForce);
	}
	else {
		// falling
		m_animation->SetProps(m_TextureID, 3, 2, 120);
		m_isJumping = false;
		m_jumpTime = JUMP_TIME;
	}

	m_lastSafePosition = pos_;
	m_rigidBody->Update();
	m_rigidBody->UpdateGravity();
	m_rigidBody->UpdateAcceleration();

	// map collision
	pos_.X += m_rigidBody->GetVelocity().X;
	m_collider->Set(pos_.X, pos_.Y, 58, 72);
	if (CollisionHandler::GetInstance()->MapCollision(m_collider->Get())) {
		pos_.X = m_lastSafePosition.X;
	}

	pos_.Y += m_rigidBody->GetVelocity().Y;
	m_collider->Set(pos_.X, pos_.Y, 58, 72);
	/*if (CollisionHandler::GetInstance()->MapCollision(m_collider->Get())) {
		pos_.Y = m_lastSafePosition.Y;
	}*/

	if (CollisionHandler::GetInstance()->MapCollision(m_collider->Get())) {
		m_isOnGround = true;
		pos_.Y = m_lastSafePosition.Y;
	}
	else {
		m_isOnGround = false;
	}

	if (m_isJumping) {
		m_animation->SetProps(m_TextureID, 2, 2, 120);
	}

	//m_rigidBody->Update(dt);
	m_origin->X = pos_.X + m_Width / 2;
	m_origin->Y = pos_.Y + m_Height / 2;
	// Update Animation
	m_animation->Update();

	//SDL_Log("Pos %0.2f %0.2f", m_rigidBody->GetAcceleration().Y, m_rigidBody->GetVelocity().Y);
	//SDL_Log("Acc %0.2f %0.2f", m_rigidBody->GetAcceleration().X, m_rigidBody->GetAcceleration().Y);
}

void Warrior::Draw(){

	m_animation->Draw(pos_.X, pos_.Y, m_Width, m_Height);
	//TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Position.X, m_Position.Y, m_Width, m_Height, m_row, m_frame);

	Vector2 cam = Camera::GetInstance()->GetPosition();
	SDL_Rect hitBox = m_collider->Get();
	// insert camera into the hitbox
	hitBox.x -= cam.X;
	hitBox.y -= cam.Y;
	SDL_RenderDrawRect(Engine::GetInstance()->GetRenderer(), &hitBox);
}

void Warrior::Clean(){
	TextureManager::GetInstance()->Drop(m_TextureID);
}
