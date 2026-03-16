#include <box2d/box2d.h>
#include <iostream>
#include <raymath.h>
#include "PhysicsManager.h"
#include "Conversions.h"

void PhysicsManager::Update() {
	b2World_Step(m_world, m_timestep, m_subStepCount);

	b2ContactEvents events = b2World_GetContactEvents(m_world);
	bool f = false;
	for (int i = 0; i < events.endCount; ++i) {
		f = true;
		b2ContactEndTouchEvent* event = events.endEvents + i;

		b2ShapeId shapeA = event->shapeIdA;
		b2ShapeId shapeB = event->shapeIdB;
	}

	if (f) {
		Notify();
	}
}

PhysicsManager::~PhysicsManager() {
	b2DestroyWorld(m_world);
}