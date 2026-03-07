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

private:
	float m_radius;
};