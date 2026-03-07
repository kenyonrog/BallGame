#include <raylib.h>
#include <functional>
#include "UiButton.h"

void UiButton::Draw() {
	DrawRectangle(m_position.x, m_position.y, int(m_width), int(m_height), m_color);
}

void UiButton::Update() {
	Vector2 mousePosition{ GetMousePosition() };

	bool isIntersectingX{ mousePosition.x >= m_position.x && mousePosition.x <= m_position.x + m_width };
	bool isIntersectingY{ mousePosition.y >= m_position.y && mousePosition.y <= m_position.y + m_height };

	if (isIntersectingX && isIntersectingY) {
		if (IsMouseButtonPressed(0)) {
			for (std::function<void()> connection : m_connections) {
				connection();
			}
		}
	}
}