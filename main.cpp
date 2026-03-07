#include <raylib.h>
#include <box2d/box2d.h>
#include "Game.h"
#include "Square.h"
#include "Ball.h"
#include "Circle.h"
#include "UiButton.h"

int main() {
	Game game = Game(700, 800, "Ball Game", Vector2{0, 0});

	b2WorldId *world = game.GetPhysicsManager()->GetWorld();

	// Circle body def
	b2BodyDef bodyDef = b2DefaultBodyDef();
	bodyDef.type = b2_staticBody;
	bodyDef.position = Vector2Tob2Vec2(game.GetWindowCenter());

	b2ShapeDef shapeDef = b2DefaultShapeDef();
	b2SurfaceMaterial surfaceMaterial{ b2DefaultSurfaceMaterial() };
	surfaceMaterial.restitution = .96f;
	surfaceMaterial.friction = 0;
	surfaceMaterial.rollingResistance = 1;
	shapeDef.material = surfaceMaterial;
	shapeDef.density = 0.01f;

	Circle circle = Circle(world, bodyDef, shapeDef, 200, 1.0f, 360);
	UiButton button{ game.GetWindowCenter() + Vector2{-50, 300}, 100, 30};
	auto createBall = [&]()
	{
			auto print = []() {
				printf("Hekki");
			
			};

		game.CreateBallsWithinCircle(&circle, shapeDef, 1);
	};

	// UI button
	std::function<void(void)> func = createBall;
	button.OnButtonClicked(func);
	button.OnButtonClicked(func);

	game.AddUiElement(&button);
	game.AddShape(&circle);

	game.Render();

	return 0;
}