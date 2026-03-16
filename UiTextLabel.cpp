#include <iostream>
#include "UiTextLabel.h"

void UiTextLabel::Update() {

}

void UiTextLabel::Draw() {
	DrawRectangle(m_position.x, m_position.y, int(m_width), int(m_height), m_color);
	DrawText(m_text.c_str(), m_position.x, m_position.y, m_fontSize, m_textColor);
}