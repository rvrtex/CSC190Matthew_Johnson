#include "squarePlanet.h"

Vector2 dimensions[4];

void squarePlanet::draw(Core::Graphics& g)
{
for(unsigned int i = 0; i < 4; i++)
	{		
		const Vector2 first = dimensions[i];
		const Vector2 second = dimensions[(i+1)% 4];
		g.DrawLine(first.x,first.y,second.x,second.y);
		;}
}




