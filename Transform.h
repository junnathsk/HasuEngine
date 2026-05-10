#pragma once
#include "Vector2.h"

class Transform{
public:
	float X, Y;

public:
	Transform(float x = 0, float y = 0) : X(x), Y(y) {}
	// Debug Log
	void Log(std::string msg = "") {
		std::cout << msg << "(X Y) = (" << X << "," << Y << ")" << std::endl;
	}
public:
	inline void TranslateX(float x) { X += x; }
	inline void TranslateY(float y) { Y += y; }
	inline void Translate(Vector2 v) { X += v.X; Y += v.Y; }
};

