#ifndef SpaceShip_H
#define SpaceShip_H

#include "Core.h"
#include "Vector2.h"
#include "Matrix3.h"

class SpaceShip
{
public:
	Vector2 position;
	Vector2 velocity;
	bool outSideLine;
	
	void draw(Core::Graphics&);
	void update(float dt);
	void ModeKeyPressed(Vector2&);

};

#endif
