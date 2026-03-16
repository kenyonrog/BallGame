#pragma once
#include <functional>
#include "UiElement.h"

class UiButton : public UiElement {
public:
	inline UiButton(Vector2 position, float width, float height)
		: UiElement(position, width, height)
	{}

	virtual void Draw();
	virtual void Update();

	inline bool isMouseOverlappingUiElement() {
		Vector2 cursorPos{ GetMousePosition() };
		bool isOverlappingX{ cursorPos.x >= m_position.x && cursorPos.x <= m_position.x + m_width };
		bool isOverlappingY{ cursorPos.y >= m_position.y && cursorPos.y <= m_position.y + m_height };
		return (isOverlappingX && isOverlappingY);
	}

	inline void OnButtenClicked(Observer* obserever) { AddObserver(obserever); }
};