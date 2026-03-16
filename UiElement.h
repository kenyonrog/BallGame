#pragma once
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "Subject.h"

class UiElement : public Subject {
public:
	inline UiElement(Vector2 position, float width, float height) {
		m_position = position;
		m_width = width;
		m_height = height;
	}
	virtual ~UiElement() = default;

	virtual void Update() = 0;
	virtual void Draw() = 0;

	inline virtual void SetColor(Color color) { m_color = color; }

protected:
	Vector2 m_position;
	Color m_color{ 255, 255, 255, 255 };
	float m_width;
	float m_height;
};