#pragma once
#include <raylib.h>
#include <raymath.h>

class UiElement {
public:
	inline UiElement(Vector2 position) {
		m_position = position;
	}
	virtual ~UiElement() = default;

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	Vector2 m_position;
	Color m_color{ 255, 255, 255, 255 };
};