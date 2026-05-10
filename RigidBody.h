#pragma once
#include "Vector2.h"

#define UNI_MASS 1.0f
#define GRAVITY 9.8f

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
	inline void ApplyForce(Vector2 force) { m_force = force; }
	inline void ApplyForceX(float x) { m_force.X = x; }
	inline void ApplyForceY(float y) { m_force.Y = y; }
	inline void UnSetForce() { m_force = Vector2(0, 0); }

	// Friction
	inline void ApplyFriction(Vector2 friction) { m_friction = friction; }
	inline void ApplyFrictionX(float x) { m_friction.X = x; }
	inline void ApplyFrictionY(float y) { m_friction.Y = y; }
	inline void UnSetFriction() { m_friction = Vector2(0, 0); }

	// Getter
	inline float GetMass() { return m_mass; }
	inline Vector2 GetPosition() { return m_position; }
	inline Vector2 GetVelocity() { return m_velocity; }
	inline Vector2 GetAcceleration() { return m_acceleration; }

	void Update(float dt) {
		// Calculate Acceleration
		m_acceleration.X = (m_force.X + m_friction.X) / m_mass;
		m_acceleration.Y = m_gravity + m_force.Y / m_mass;
		// Calculate Velocity
		m_velocity = m_acceleration * dt;
		m_position = m_velocity * dt;
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