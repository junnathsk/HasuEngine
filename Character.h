#pragma once

#include "GameObject.h"

class Character : public GameObject {
public : 
	Character(Properties props) : GameObject(props) {}

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

protected:
	std::string m_Name;
};

