#pragma once
#include "IObject.h"
#include "Transform.h"
#include "SDL.h"

/**
 * Structure (Properties) to initialize
 * the attributes of the class (GameObject)
 */
struct Properties {
	std::string TextureID;
	float Width, Height;
	Vector2 Pos;
	SDL_RendererFlip Flip;

	Properties(std::string textureID, Vector2 pos, float width, float height,
		SDL_RendererFlip flip = SDL_FLIP_NONE)
		: TextureID(textureID), Width(width), Height(height), Pos(pos),
		Flip(flip) {
	}
};

class GameObject : public IObject{
public :
	GameObject(const Properties& props)
		: m_Position(props.Pos), m_Width(props.Width),
		m_Height(props.Height), m_TextureID(props.TextureID),
		m_Flip(props.Flip) {
	}

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Clean() override;

protected:
	Vector2 m_Position = {};
	float m_Width = 0;
	float m_Height = 0;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
};

