#pragma once

#include <raylib.h>
#include <string>
#include "UiElement.h"

class UiTextLabel : public UiElement {
public:
	inline UiTextLabel(Vector2 position, const char* text, float width, float height)
		: UiElement(position, width, height)
	{
		m_text = text;
	}

	void Draw();
	void Update();

	inline void ChangeText(std::string text) { m_text = text; }
	inline void ChangeTextColor(Color color) { m_textColor = color; }
	inline void ChangeFontSize(int fontSize) { m_fontSize = fontSize; }

private:
	std::string m_text;
	Color m_textColor{ 100, 100, 100, 255 };
	int m_fontSize{ 24 };
};