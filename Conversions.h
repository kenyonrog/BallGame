#pragma once
#include <box2d/box2d.h>
#include <raymath.h>

inline float PPMFactor{ 100.0f };

inline Vector2 b2Vec2ToVector2(b2Vec2 vector) { return Vector2{ vector.x, vector.y }; }
inline b2Vec2 Vector2Tob2Vec2(Vector2 vector) { return b2Vec2{ vector.x, vector.y }; }