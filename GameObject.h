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
	Transform Pos;
	SDL_RendererFlip Flip;

	/// <summary>
	/// Set Object Properties
	/// </summary>
	/// <param name="textureID">object ID</param>
	/// <param name="width">Object Width</param>
	/// <param name="height">Object Height</param>
	/// <param name="flip">SDL FLIP</param>
	Properties(std::string textureID, float width, float height,
		SDL_RendererFlip flip = SDL_FLIP_NONE)
		: TextureID(textureID), Width(width), Height(height), Flip(flip) {
	}
};

class GameObject : public IObject{
public :
	GameObject(const Properties& props)
		: m_Width(props.Width),
		m_Height(props.Height), m_TextureID(props.TextureID),
		m_Flip(props.Flip) {
		float px = props.Pos.X + props.Width/2;
		float py = props.Pos.Y + props.Height/2;
		m_origin = new Vector2(px, py);
	}

	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void Clean() override;

	inline Vector2* GetOrigin() { return m_origin; }

protected:
	Vector2* m_origin;
	float m_Width = 64;
	float m_Height = 64;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
};

