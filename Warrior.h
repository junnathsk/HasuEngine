#pragma once

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"
#include "Collider.h"

#define JUMP_TIME 8.0f
#define JUMP_FORCE 16.0f

class Warrior : public Character {
public:
	Warrior(Properties props);

	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void Clean() override;
private:
	Animation* m_animation;
	RigidBody* m_rigidBody;

	Collider* m_collider;
	Vector2 m_lastSafePosition;		// pre-position

	bool m_isJumping;
	bool m_isOnGround;

	float m_jumpTime;
	float m_jumpForce;


	Vector2 pos_;
};

