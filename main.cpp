#include <string>
#include <iostream>
#include <raylib.h>
#include <box2d/box2d.h>
#include <box2d/collision.h>
#include "Game.h"
#include "MoneyManager.h"
#include "Square.h"
#include "Ball.h"
#include "Circle.h"
#include "UiButton.h"
#include "UiTextLabel.h"
#include "ItemAmounts.h"

int main() {
	Game game = Game(700, 800, "Ball Game", Vector2{0, 0});
	PhysicsManager* physicsManager = game.GetPhysicsManager();
	b2WorldId *world = physicsManager->GetWorld();
	MoneyManager* moneyManager = game.GetMoneyManager();
		 
	// Circle body def
	b2BodyDef bodyDef = b2DefaultBodyDef();
	bodyDef.type = b2_staticBody;
	bodyDef.position = Vector2Tob2Vec2(game.GetWindowCenter());

	// Shape def for all objects
	b2ShapeDef shapeDef = b2DefaultShapeDef();
	b2SurfaceMaterial surfaceMaterial{ b2DefaultSurfaceMaterial() };
	surfaceMaterial.restitution = .90f;
	surfaceMaterial.friction = 0.1;
	surfaceMaterial.rollingResistance = 10;
	shapeDef.material = surfaceMaterial;
	shapeDef.density = 0.01f;
	shapeDef.enableContactEvents = true;

	// Create circle
	Circle circle = Circle(world, bodyDef, shapeDef, 200, 1.0f, 360);

	// Text label
	UiTextLabel label{ Vector2{50, 100}, "Money : $10", 75, 30 };
	label.SetColor(Color{ 0, 0, 0, 0 });
	label.ChangeTextColor(Color{ 255, 255, 255, 255 });

	int ballCost{ 10 };

	// UI button
	UiButton button{ game.GetWindowCenter() + Vector2{-50, 300}, 100, 30};
	CallbackObserver* addBall = new CallbackObserver([&]() {
		if (moneyManager->GetMoney() >= ballCost) {
			game.CreateBallsWithinCircle(&circle, shapeDef, 1);
			moneyManager->SubtractMoney(ballCost);
			label.ChangeText("Money: $" + std::to_string(moneyManager->GetMoney()));
		}
	});

	CallbackObserver* ballCollision = new CallbackObserver([&]() {
		moneyManager->AddMoney(1);
		label.ChangeText("Money: $" + std::to_string(moneyManager->GetMoney()));
	});


	button.OnButtenClicked(addBall);
	physicsManager->OnShapeCollision(ballCollision);

	// Adding things to game
	game.AddUiElement(&label);
	game.AddUiElement(&button);
	game.AddShape(&circle);

	game.Render();

	return 0;
}