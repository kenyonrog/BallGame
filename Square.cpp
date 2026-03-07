#include <raylib.h>
#include <box2d/box2d.h>
#include <iostream>
#include "Square.h"
#include "Conversions.h"

void Square::InitPhysics(const b2BodyDef bodyDef, const b2ShapeDef shapeDef) {
	m_body = b2CreateBody(m_world, &bodyDef);
	b2Polygon square = b2MakeSquare((m_halfWidth));

	b2CreatePolygonShape(m_body, &shapeDef, &square);
}

void Square::Draw() {
	Vector2 bodyPos = b2Vec2ToVector2(b2Body_GetPosition(m_body));
	float totalSize = m_halfWidth * 2.0f;

	float drawX = bodyPos.x - totalSize/2.0f;
	float drawY = bodyPos.y - totalSize/2.0f;

	DrawRectangle(int(drawX), int(drawY), int(totalSize), int(totalSize), m_color);
}