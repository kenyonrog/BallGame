#pragma once
#include <vector>
#include "Shape.h"

class Circle : public Shape {
public:
	Circle(b2WorldId* worldId, b2BodyDef bodyDef, b2ShapeDef shapeDef, float radius, float width, int subdivisions) :
		Shape(worldId, bodyDef, shapeDef)
	{
		m_radius = radius;
		m_width = width;
		m_subdivisions = subdivisions;
		InitPhysics(bodyDef, shapeDef);
	}

	void Draw();

	void InitPhysics(b2BodyDef bodyDef, b2ShapeDef shapeDef);

	inline float GetRadius() { return m_radius; }

private:
	float m_radius;
	float m_width;
	int m_subdivisions;

	std::vector<b2ShapeId> m_segments;
};