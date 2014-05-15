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
	
	meShip.draw(graphics);
	meLerp.draw(graphics);

	graphics.DrawString(50, 30, "DrawShip: "+meShip.outSideLine);
	//DrawValues::DrawValue(graphics,100,100,
	
	graphics.DrawString(50, 20, "1: Bounce, 2: Wrap, 3: Arbitray Walls, 4: Hammer Time");
	
}


void main()
{
	meShip.position = Vector2(500,300);
	meLerp.position = Vector2(+50.0f,50.0f);

	Core::Init("Matt's AWESOME Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();

	
}

