#pragma once

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5f;	// 1.5ms

class Timer{
public:
	inline static Timer* GetInstance() {
		if (s_Instance == nullptr) {
			s_Instance = new Timer();
		}
		return s_Instance;
	}

	void Tick();
	inline float GetDeltaTime() const { return m_deltaTime; }

private:
	Timer() {};
	static Timer* s_Instance;
	float m_deltaTime;
	float m_LastTime;
};

