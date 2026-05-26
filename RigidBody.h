#pragma once
#include "Vector2.h"

#define UNI_MASS 1.0f
#define GRAVITY 0.68f

#define FORWARD 1
#define BACKWARD -1

#define UPWARD -1
#define DOWNWARD 1

class RigidBody {
public:
	RigidBody() {
		m_mass = UNI_MASS;
		m_gravity = GRAVITY;
	};

	// Setter
	inline void SetMass(float mass) { m_mass = mass; }
	inline void SetGravity(float gravity) { m_gravity = gravity; }

	// Force
	inline void SetForce(Vector2 force) { m_force = force; }
	inline void SetForceX(float x) { m_force.X = x; }
	inline void SetForceY(float y) { m_force.Y = y; }
	inline void ResetForce() { m_force = Vector2(0, 0); }

	// Friction
	inline void SetFriction(Vector2 friction) { m_friction = friction; }
	inline void SetFrictionX(float x) { m_friction.X = x; }
	inline void SetFrictionY(float y) { m_friction.Y = y; }
	inline void ResetFriction() { m_friction = Vector2(0, 0); }

	// Acceleration
	inline void SetAcceleration(Vector2 acc) { m_acceleration = acc; }
	inline void UpdateAcceleration() { m_velocity = m_acceleration; }
	inline void UpdateAccelerationX() { m_velocity.X += m_acceleration.X; }
	inline void UpdateAccelerationY() { m_velocity.Y += m_acceleration.Y; }
	inline void ResetAcceleration() { m_acceleration = Vector2(0, 0); }
	inline void ResetAccelerationX() { m_acceleration.X = 0.0f; }
	inline void ResetAccelerationY() { m_acceleration.Y = 0.0f; }

	inline void ApplyVelocity(Vector2 vel) { m_velocity = vel; }
	inline void ApplyVelocityX(float x) { m_velocity.X = x; }
	inline void ApplyVelocityY(float y) { m_velocity.Y = y; }
	inline void ResetVelocity() { m_velocity = Vector2(0, 0); }
	inline void ResetVelocityX() { m_velocity.X = 0.0f; }
	inline void ResetVelocityY() { m_velocity.Y = 0.0f; }

	inline void SetPosition(Vector2 pos) { m_position = pos; }

	// Getter
	inline float GetMass() { return m_mass; }
	inline Vector2 GetPosition() { return m_position; }
	inline Vector2 GetVelocity() { return m_velocity; }
	inline Vector2 GetAcceleration() { return m_acceleration; }
	inline float GetPositionX() const { return m_position.X; }
	inline float GetPositionY() const { return m_position.Y; }

	void Update() {
		m_acceleration.X = (m_force.X + m_friction.X) / m_mass;
	}

	void UpdateGravity() {
		m_acceleration.Y = m_gravity + m_force.Y / m_mass;
	}

private:
	Vector2 m_position;

	float m_mass;			// mass
	float m_gravity;		// gravity

	Vector2 m_force;		// force
	Vector2 m_friction;		// friction

	Vector2 m_velocity;
	Vector2 m_acceleration;
};