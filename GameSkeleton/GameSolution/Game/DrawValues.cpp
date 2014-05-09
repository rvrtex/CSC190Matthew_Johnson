#include "DrawValues.h"


void DrawValues::DrawValue( Core::Graphics& graphics, int x, int y, float num )
{
	std::stringstream ss;
	ss << num;
	graphics.DrawString( x, y, ss.str().c_str());
};

void DrawValues::DrawValue( Core::Graphics& graphics, int x, int y, Vector2 vector )
{
	std::stringstream ss;
	ss << "Vector x: " << vector.x << " " << "Vector y: " << vector.y;
	graphics.DrawString( x, y, ss.str().c_str());
};

void DrawValues::DrawValue( Core::Graphics& graphics, int x, int y, int num )
{
	std::stringstream ss;
	ss << num;
	graphics.DrawString( x, y, ss.str().c_str());
};
