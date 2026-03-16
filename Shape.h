#pragma once
#include <raylib.h>
#include <raymath.h>
#include <box2d/box2d.h>
#include "Conversions.h"
#include "Subject.h"

class Shape : public Subject {
public:
	Shape(b2WorldId *worldId, b2BodyDef bodyDef, b2ShapeDef shapeDef) {
		m_world = *worldId;
		m_bodyDef = bodyDef;
		m_shapeDef = shapeDef;
	}

	inline virtual ~Shape() { b2DestroyBody(m_body); }
	virtual void InitPhysics(b2BodyDef bodyDef, b2ShapeDef shapeDef) = 0;

	virtual void Draw() = 0;

	inline virtual void SetColor(Color color) { m_color = color; };
	inline virtual b2BodyId* GetBody() { return &m_body; }

protected:
	Vector2 m_initialPosition{};
	Color m_color{255, 255, 255, 255};

	b2WorldId m_world;
	b2BodyDef m_bodyDef;
	b2ShapeDef m_shapeDef;

	b2BodyId m_body{};

};