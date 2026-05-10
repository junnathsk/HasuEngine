#pragma once

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"

class Warrior : public Character {
public:
	Warrior(Properties props);

	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void Clean() override;
private:
	Animation* m_animation;
	RigidBody* m_rigidBody;
};

