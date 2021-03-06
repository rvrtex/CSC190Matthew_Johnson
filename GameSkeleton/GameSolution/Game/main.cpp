#include "Engine.h"
#include "Core.h"
#include "SpaceShip.h"
#include "LerpingRoid.h"
#include "DrawValues.h"
#include "ProjectileManager.h"
#include "GameSolution.h"
#include "Profiler.h"
#include "Logger.h"
#include "Leek.h"

using Core::Input;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 728;

bool red = true;

GameSolution gs;

bool Update(float dt)
{	

	gs.update(dt);
	if (Input::IsPressed(Input::KEY_ESCAPE))
	{
		//Profiler::getInstance().shutDown();

		gs.ShutDown();
		return true;
	}
	return false;
}


void Draw(Core::Graphics& graphics)
{
	//ASSERT(true == false);
	
	gs.draw(graphics);

	//DrawValues::DrawValue(graphics,100,100,
	
	graphics.DrawString(50, 20, "1: Bounce, 2: Wrap, 3: Arbitray Walls, H: Hammer Time, Left Mouse button fires the missle; turret follows the mouse");
	
}


void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	Leek* l = new Leek();
	l;
	//delete l;
	Core::Init("Matt's AWESOME Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();

}

