#include "Engine.h"
#include "Core.h"
#include "SpaceShip.h"
#include "LerpingRoid.h"
#include "DrawValues.h"
#include "ProjectileManager.h"
#include "GameSolution.h"


using Core::Input;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 728;

bool red = true;
ProjectileManager pm;
SpaceShip meShip(pm);
LerpingRoid meLerp;
DrawValues drawValues;
GameSolution gs;

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
	pm.draw(graphics);
	gs.draw(graphics);

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

