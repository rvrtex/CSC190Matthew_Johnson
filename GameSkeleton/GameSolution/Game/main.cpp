#include "Engine.h"
#include "Core.h"
#include "SpaceShip.h"
#include "LerpingRoid.h"
#include "DrawValues.h"

using Core::Input;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 728;

bool red = true;
SpaceShip meShip;
LerpingRoid meLerp;
DrawValues drawValues;

bool Update(float dt)
{	
	meShip.update(dt);
	meLerp.update(dt);
	if (Input::IsPressed(Input::KEY_ESCAPE))
		return true;
	return false;
}


void Draw(Core::Graphics& graphics)
{
	/*graphics.SetColor(RGB(255, 255, 255));*/
	/*meShip.position = Vector2(75,75);*/
	meShip.draw(graphics);
	meLerp.draw(graphics);
	drawValues.DrawValue(graphics, 300, 50, meShip.position);
	
	//graphics.DrawString(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 20, "Hello World");
	//graphics.DrawLine(400, 300, 10, 10);
}


void main()
{
	meShip.position = Vector2(70,70);
	meLerp.position = Vector2(+50.0f,50.0f);

	Core::Init("Matt's AWESOME Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();

	//Engine::sampleFunctionThatReturnsTrue();
}

