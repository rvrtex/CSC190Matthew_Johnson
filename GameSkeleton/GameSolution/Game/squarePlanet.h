#ifndef SQUAREPLANET_H
#define SQUAREPLANET_H

#include "Vector2.h"
#include "Matrix3.h"
#include "Core.h"

class squarePlanet
{
public:
	
	Vector2 position;
	Vector2 dimensions[4];
	void draw(Core::Graphics&);
};
#endif
