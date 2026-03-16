#include <raylib.h>
#include <iostream>
#include <vector>
#include <functional>
#include "UiButton.h"

void UiButton::Draw() {
	DrawRectangle(int(m_position.x), int(m_position.y), int(m_width), int(m_height), m_color);
}

void UiButton::Update() {
	Vector2 mousePosition{ GetMousePosition() };

	if (isMouseOverlappingUiElement()) {
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);

		if (IsMouseButtonPressed(0)) {
			Notify();
		}
	}
	else
	{
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	}
}