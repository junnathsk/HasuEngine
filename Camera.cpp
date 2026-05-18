#include "Camera.h"

Camera* Camera::s_Instance = nullptr;

void Camera::Update(float dt) {
	if (m_target != 0) {

		// Start moving the camera when 
		// the player on the middle of the screen
		m_viewBox.x = m_target->X - SCREEN_WIDTH / 2;
		m_viewBox.y = m_target->Y - SCREEN_HEIGHT / 2;

		// Set the minimal camera movement
		if (m_viewBox.x < 0) {
			m_viewBox.x = 0;
		}
		if (m_viewBox.y < 0) {
			m_viewBox.y = 0;
		}

		// Set the max camera movement based on the map width
		if (m_viewBox.x > (2 * SCREEN_WIDTH - m_viewBox.w)) {
			m_viewBox.x = (2 * SCREEN_WIDTH - m_viewBox.w);
		}
		if (m_viewBox.y > (2 * SCREEN_WIDTH - m_viewBox.h)) {
			m_viewBox.y = (2 * SCREEN_WIDTH - m_viewBox.h);
		}

		// Update camera Position
		m_position = Vector2(m_viewBox.x, m_viewBox.y);
	}
}