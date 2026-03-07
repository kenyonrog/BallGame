#include <box2d/box2d.h>
#include <raymath.h>
#include "PhysicsManager.h"
#include "Conversions.h"

void PhysicsManager::Update() {
	b2World_Step(m_world, m_timestep, m_subStepCount);
}

PhysicsManager::~PhysicsManager() {
	b2DestroyWorld(m_world);
}