#pragma once
#include "SDL.h"
#include "Vector2.h"
#include "Engine.h"

class Camera{
public:
	inline static Camera* GetInstance() {
		if (s_Instance == nullptr) {
			s_Instance = new Camera();
		}
		return s_Instance;
	}

	inline SDL_Rect GetViewBox() { return m_viewBox; }
	inline Vector2 GetPosition() { return m_position; }
	inline void SetTarget(Vector2* target) { m_target = target; }

	void Update(float dt);
private:
	Camera() {
		m_viewBox = { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
	}
	Vector2* m_target;
	Vector2 m_position;

	SDL_Rect m_viewBox;
	static Camera* s_Instance;
};

