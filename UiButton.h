#pragma once
#include <functional>
#include "UiElement.h"

class UiButton : public UiElement {
public:
	inline UiButton(Vector2 position, float width, float height)
		: UiElement(position)
	{
		m_width = width;
		m_height = height;
	}

	virtual void Draw();
	virtual void Update();

	inline void OnButtonClicked(std::function<void()> f) { m_connections.push_back(f); }

private:
	std::vector<std::function<void()>> m_connections;

	float m_width;
	float m_height;
};