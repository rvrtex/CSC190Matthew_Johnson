#include "VaryColor.h"

using Util::Colors;

static int r;
static int g;
static int b;

Core::RGB Colors::VeryColor(Core::RGB color, float variance){

	
	r = GetRValue(color);
	r = r + int(Colors::RandomInRange(-(float)variance, (float)variance+1));
	r = r < 0 ? 0 : r;
	r = r > 255 ? 255 : r;

	g = GetGValue(color);
	g = g + int(Colors::RandomInRange(-(float)variance, (float)variance+1));
	g = g < 0 ? 0 : g;
	g = g > 255 ? 255 : g;

	b = GetBValue(color);
	b = b + int(Colors::RandomInRange(-(float)variance, (float)variance+1));
	b = b < 0 ? 0 : b;
	b = b > 255 ? 255 : b;

	return RGB(r,g,b);
}
Core::RGB Colors::Brightness (Core::RGB color, float brightValue){
	r = int(GetRValue(color) * brightValue);
	g = int(GetGValue(color) * brightValue);
	b = int(GetBValue(color) * brightValue);

	return RGB(r,g,b);
}

float Colors::RandomFloat()
{
	return (float) rand()/ RAND_MAX;
}

float Colors::RandomInRange(float min, float max)
{
	return RandomFloat() * (max - min + 1) + min;
}
	