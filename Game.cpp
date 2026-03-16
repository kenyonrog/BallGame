#include <raylib.h>
#include <box2d/box2d.h>
#include <iostream>
#include <random>
#include "Game.h"
#include "Circle.h"
#include "Ball.h"
#include "UiElement.h"

Game::~Game() {
	CloseWindow();
}

void Game::Draw() {
	DrawFPS(10, 10);

	for (Shape* shape : m_shapes) {
		shape->Draw();
	}

	for (UiElement* uiElement : m_uiElements) {
		uiElement->Draw();
	}
}

void Game::Update() {
	m_physicsManager.Update();

	for (UiElement* uiElement : m_uiElements) {
		uiElement->Update();
	}
}

void Game::Render() {
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		Game::Draw();

		EndDrawing();

		Game::Update();
	}
}

std::vector<Ball*> Game::CreateBallsWithinCircle(Circle* circle, b2ShapeDef shapeDef, int amountOfBalls) {
	std::vector<Ball*> balls;

	float angleStep{ 2.0f * PI / 360 };
	
	for (int i = 0; i < amountOfBalls; ++i) {
		b2BodyId* body{ circle->GetBody() };
		b2Vec2 bodyPos{ b2Body_GetPosition(*body) };

		float circleRadius{ circle->GetRadius() };
		int ballRadius{ GetRandomValue(10, 20) };

		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_real_distribution<float> dist(0, 1);
		float r = circleRadius * sqrtf(dist(rng));
		float theta = dist(rng) * 2.0f * PI;

		float xPos{ bodyPos.x + r * cos(theta)};
		float yPos{ bodyPos.y + r * sin(theta)};

		b2BodyDef bodyDef = b2DefaultBodyDef();
		bodyDef.type = b2_dynamicBody;
		bodyDef.position = b2Vec2{ xPos, yPos };

		Ball* ball = new Ball(m_physicsManager.GetWorld(), bodyDef, shapeDef, (float)ballRadius);
		ball->SetColor(Color{ (unsigned char)GetRandomValue(100, 255), (unsigned char)GetRandomValue(100, 255), (unsigned char)GetRandomValue(100, 255), 255 });

		float forceX{ 1000 };
		float forceY{ 1000 };

		AddShape(ball);
		balls.push_back(ball);

		b2Body_ApplyLinearImpulseToCenter(*(ball->GetBody()), b2Vec2{forceX, forceY}, true);
	}

	return balls;
}