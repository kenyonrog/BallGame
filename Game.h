#pragma once
#include <box2d/collision.h>
#include <type_traits>
#include <vector>
#include <memory>
#include <raymath.h>
#include <math.h>
#include "PhysicsManager.h"
#include "Square.h"
#include "Circle.h"
#include "Ball.h"
#include "UiElement.h"
#include "MoneyManager.h"

class Game : public Subject {
public:
	inline Game(int windowWidth, int windowHeight, const char* windowTitle, Vector2 gravity)
		: m_windowWidth{ windowWidth },
		m_windowHeight{ windowHeight },
		m_windowTitle{ windowTitle },
		m_physicsManager{ gravity},
		m_moneyManager{ 10 }
	{
		InitWindow(windowWidth, windowHeight, windowTitle);
		SetTargetFPS(60);
	}
	~Game();
	
	void Render();

	inline PhysicsManager* GetPhysicsManager() { return &m_physicsManager; }
	inline MoneyManager* GetMoneyManager() { return &m_moneyManager; }

	inline void AddShape(Shape* shape) { m_shapes.push_back(shape); }
	inline void AddUiElement(UiElement* uiElement) { m_uiElements.push_back(uiElement); }

	std::vector<Ball*> CreateBallsWithinCircle(Circle* circle, b2ShapeDef shapeDef, int amountOfBalls);

	inline int GetWindowWidth() { return m_windowWidth; }
	inline int GetWindowHeight() { return m_windowHeight; }
	inline Vector2 GetWindowCenter() { return Vector2{ roundf((float)GetWindowWidth()/2.0f), (float)GetWindowHeight()/2.0f}; }
	
private:
	int m_windowWidth;
	int m_windowHeight;
	const char* m_windowTitle;

	std::vector<Shape*> m_shapes;
	std::vector<UiElement*> m_uiElements;

	PhysicsManager m_physicsManager;
	MoneyManager m_moneyManager;

	void Draw();
	void Update();
};