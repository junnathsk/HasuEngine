#include "Engine.h"
#include "TextureManager.h"
#include "Transform.h"

Engine* Engine::s_Instance = nullptr;

Engine::Engine() {
	isRunning_ = false;
}

bool Engine::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 0) {
		SDL_Log("Failed to Initialized SDL : %s", SDL_GetError());
		return false;
	}

	window_ = SDL_CreateWindow("TITLE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
	if (window_ == nullptr) {
		SDL_Log("Failed to Create SDL Window : %s", SDL_GetError());
		return false;
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer_ == nullptr) {
		SDL_Log("Failed to Create SDL Renderer: %s", SDL_GetError());
		return false;
	}
	
	TextureManager::GetInstance()->Load("Magnet", "Resources/magnet.png");

	Transform tf(10,20);
	tf.Log();
	
	return isRunning_ = true;
}

void Engine::Update(){
}

void Engine::Render(){
	SDL_SetRenderDrawColor(renderer_, 205, 205, 255, 255);
	SDL_RenderClear(renderer_);
	TextureManager::GetInstance()->Draw("Magnet", 60,60,32,32);
	SDL_RenderPresent(renderer_);
}

void Engine::Events(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		Quit();
		break;
	default:

		break;
	}
}

bool Engine::Clean() {
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	IMG_Quit();
	SDL_Quit();
	return false;
}

void Engine::Quit() {
	isRunning_ = false;
	SDL_Log("Quit");
}

