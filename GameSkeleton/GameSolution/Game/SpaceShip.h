#ifndef SpaceShip_H
#define SpaceShip_H

#include "Core.h"
#include "Vector2.h"

class SpaceShip
{
public:
	Vector2 position;
	Vector2 velocity;
	void draw(Core::Graphics&);
	void update(float dt);
	bool outSideLine;

};

#endif
