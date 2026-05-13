#pragma once

#include "SDL.h"

class Input{
public:
	static Input* GetInstance() {
		if (s_Instance == nullptr) {
			s_Instance = new Input();
		}
		return s_Instance;
	}

	void Listen();
	
	/// <summary>
	/// Check if the key is pushed or not
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	bool GetKeyDown(SDL_Scancode key);

private:
	Input();
	void KeyUp();
	void KeyDown();

	const Uint8* m_keyStates;		// if 1 key is pushed if 0 not pushed
	static Input* s_Instance;
};

