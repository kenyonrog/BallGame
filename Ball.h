#pragma once
#include "Shape.h"

class Ball : public Shape {
public:
	inline Ball(b2WorldId *worldId, b2BodyDef bodyDef, b2ShapeDef shapeDef, float radius) :
		Shape(worldId, bodyDef, shapeDef)
	{
		m_radius = radius;
		InitPhysics(bodyDef, shapeDef);
	}

	void InitPhysics(b2BodyDef bodyDef, b2ShapeDef shapeDef);

	void Draw();
	void Update();

	inline float GetRadius() { return m_radius; }

	inline void OnBallCollision(Observer* observer) { AddObserver(observer); }

private:
	float m_radius;
};