#pragma once
#include "SDL.h"
#include "SDL_image.h"

#include "GameMap.h"

#define SCREEN_WIDTH 1280		// Window Width size
#define SCREEN_HEIGHT 720		// Window Height size

class Engine {
public:
	static Engine* GetInstance(){
		if (s_Instance == nullptr) {
			s_Instance = new Engine();
		}
		return s_Instance;
	}

	bool Init();
	bool Clean();
	void Quit();

	void Update();
	void Render();
	void Events();

	inline bool IsRunning() { return isRunning_; }
	inline SDL_Renderer* GetRenderer() { return renderer_; }

private:
	Engine();
	bool isRunning_;
	
	SDL_Window* window_;
	SDL_Renderer* renderer_;

	static Engine* s_Instance;

	GameMap* m_levelMap;
};

