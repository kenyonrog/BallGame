#pragma once
#include <box2d/box2d.h>
#include "Shape.h"

class Square : public Shape {
public:
	Square(b2WorldId *worldId, b2BodyDef bodyDef, b2ShapeDef shapeDef, float halfWidth)
		: Shape(worldId, bodyDef, shapeDef)
	{
		m_halfWidth = halfWidth;
		InitPhysics(bodyDef, shapeDef);
	}

	void InitPhysics(b2BodyDef bodyDef, b2ShapeDef shapeDef);

	void Draw();

private:
	float m_halfWidth;
};