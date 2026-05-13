#include "Engine.h"
#include "Timer.h"

int main(int argc, char** argv) {
	Engine::GetInstance()->Init();

	while (Engine::GetInstance()->Engine::IsRunning()) {
		Engine::GetInstance()->Engine::Events();
		Engine::GetInstance()->Engine::Update();
		Engine::GetInstance()->Engine::Render();
		Timer::GetInstance()->Timer::Tick();
	}

	Engine::GetInstance()->Engine::Clean();
	return 0;
}