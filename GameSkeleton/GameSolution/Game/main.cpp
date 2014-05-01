#include "Engine.h"
#include"Core.h"

using Core::Input;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 728;

bool red = true;

bool Update(float dt)
{

	dt;	
	if (Input::IsPressed(Input::KEY_ESCAPE))
		return true;
	return false;
}

void Draw(Core::Graphics& graphics)
{
	graphics.SetColor(RGB(255, 255, 255));
	graphics.DrawString(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 20, "Hello World");
	graphics.DrawLine(400, 300, 10, 10);
}

void Flash(Core::Graphics& graphics)
{
	
}
void main()
{
	Core::Init("Matt's AWESOME Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();

	Engine::sampleFunctionThatReturnsTrue();
}

