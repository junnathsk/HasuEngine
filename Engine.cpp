#include "Engine.h"
#include "TextureManager.h"
#include "Warrior.h"
#include "Input.h"
#include "Timer.h"

Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;

Engine::Engine() {
	isRunning_ = false;
}

bool Engine::Init() {
// Initialize SDL
#pragma region INITIALIZE SDL
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
#pragma endregion

	TextureManager::GetInstance()->Load("player", "Resources/player.png");
	player = new Warrior(Properties("player", {100,200}, 80, 100));

	Transform tf(22,20);
	tf.Log();
	
	return isRunning_ = true;
}

void Engine::Update(){
	float dt = Timer::GetInstance()->GetDeltaTime();
	player->Update(dt);
}

void Engine::Render(){
	SDL_SetRenderDrawColor(renderer_, 205, 205, 255, 255);
	SDL_RenderClear(renderer_);
	// Draw Starts here
	player->Draw();

	// Draw Ends here
	SDL_RenderPresent(renderer_);
}

void Engine::Events(){
	Input::GetInstance()->Listen();
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

