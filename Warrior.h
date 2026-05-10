#pragma once

#include "Character.h"

class Warrior : public Character {
public:
	Warrior(Properties props);

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;
private:
	int m_row, m_frame, m_frameCount;
	int m_animationSpeed;
};

