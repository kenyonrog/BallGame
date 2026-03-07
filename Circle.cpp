#include <iostream>
#include "Circle.h"
#include "Conversions.h"

void Circle::InitPhysics(b2BodyDef bodyDef, b2ShapeDef shapeDef) {
	m_body = b2CreateBody(m_world, &bodyDef);
	float angleStep = 2.0f * B2_PI / m_subdivisions;

	float radius = (m_radius);

	for (int angle{}; angle < m_subdivisions; ++angle) {
		float currentAngle = angle * angleStep;
		float nextAngle = (angle + 1) * angleStep;

		b2Vec2 p1{ cosf(currentAngle) * radius, sinf(currentAngle) * radius };
		b2Vec2 p2{ cosf(nextAngle) * radius, sinf(nextAngle) * radius };

		b2Segment segment{ p1 , p2 };
		b2ShapeId shapeId = b2CreateSegmentShape(m_body, &shapeDef, &segment);

		m_segments.push_back(shapeId);
	}
}

void Circle::Draw() {
	for (b2ShapeId shapeId : m_segments) {

		b2Vec2 b2SegP1{ b2Shape_GetSegment(shapeId).point1 };
		b2Vec2 b2SegP2{ b2Shape_GetSegment(shapeId).point2 };

		Vector2 pixelP1{(b2Vec2ToVector2(b2SegP1)) };
		Vector2 pixelP2{ (b2Vec2ToVector2(b2SegP2)) };

		b2Vec2 b2BodyPos{ b2Body_GetPosition(m_body) };
		Vector2 pixelBodyPos{ (b2Vec2ToVector2(b2BodyPos)) };

		//std::cout << pixelP1.x << '_' << pixelP1.y << '\n';

		//std::cout << pixelBodyPos.x << '_' << pixelBodyPos.y << '\n';

		Vector2 finalP1{pixelP1 + pixelBodyPos};
		Vector2 finalP2{pixelP2 + pixelBodyPos};

		DrawLineEx(finalP1, finalP2, m_width, m_color);
	}
}