#include "Timer.h"
#include "SDL.h"

Timer* Timer::s_Instance = nullptr;


void Timer::Tick(){
	m_deltaTime = (SDL_GetTicks() - m_LastTime) * (TARGET_FPS / 1000.0f);
	// Make sure the delta time not get over 1.5ms
	if (m_deltaTime > TARGET_DELTATIME) {
		m_deltaTime = TARGET_DELTATIME;
	}

	m_LastTime = SDL_GetTicks();
}
