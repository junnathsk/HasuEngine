#pragma once

#include <iostream>

class Vector2 {
public:
	float X, Y;

public:
	Vector2(float x = 0, float y = 0) : X(x), Y(y) {}

public:
	// addition +
	inline Vector2 operator+(const Vector2& v2) const {
		return Vector2(X + v2.X, Y + v2.Y);
	}

	// subtraction - 
	inline Vector2 operator-(const Vector2& v2) const {
		return Vector2(X - v2.X, Y - v2.Y);
	}

	// multiplication * 
	inline Vector2 operator*(const float scalar) const {
		return Vector2(X*scalar, Y*scalar);
	}

	// Debug Log
	void Log(std::string msg = "") {
		std::cout << msg << "(X Y) = (" << X << "," << Y << ")" << std::endl; 
	}
};

 