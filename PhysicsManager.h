#pragma once
#include <box2d/box2d.h>
#include <raymath.h>
#include "Conversions.h"

class PhysicsManager {
public:
	template <typename Vector>
	inline PhysicsManager(Vector gravity) {
		b2SetLengthUnitsPerMeter(PPMFactor);
		b2WorldDef worldDef = b2DefaultWorldDef();
		worldDef.gravity = (b2Vec2{ gravity.x, gravity.y });

		m_world = b2CreateWorld(&worldDef);
	}
	~PhysicsManager();

	void Update();
	inline b2WorldId* GetWorld() { return &m_world; }

private:
	b2WorldId m_world{};

	float m_timestep{ 1.0f / 60.0f };
	int m_subStepCount{ 4 };
};
	