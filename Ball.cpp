#include "Ball.h"

void Ball::InitPhysics(const b2BodyDef bodyDef, const b2ShapeDef shapeDef) {
	m_body = b2CreateBody(m_world, &bodyDef);

	const b2Circle circle{{0, 0}, m_radius};
	b2CreateCircleShape(m_body, &shapeDef, &circle);
}

void Ball::Update() {
	
}

void Ball::Draw() {
	b2Vec2 b2Position{ b2Body_GetPosition(m_body) };
	Vector2 pixelPosition{ b2Vec2ToVector2(b2Position) };

	float pixelSize = m_radius / 2;

	float drawX = pixelPosition.x ;
	float drawY = pixelPosition.y;

	DrawCircle(int(drawX), int(drawY), m_radius, m_color);
}