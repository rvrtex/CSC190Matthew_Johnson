#ifndef TURRET_H
#define TURRET_H

#include "Core.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "ProjectileManager.h"


class Turret
{
public:
	Turret();
	Turret(ProjectileManager&);
	void draw(Core::Graphics&, Vector2);

	void update();
	void FireButtonPressed(float);
};
#endif // !TURRET_H


