#ifndef SpaceShip_H
#define SpaceShip_H

#include "Core.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "Turret.h"
#include "GameSolution.h"

class SpaceShip
{

public:
	SpaceShip(GameSolution&);
	SpaceShip(void);
	Vector2 position;
	Vector2 velocity;
	bool outSideLine;
	Matrix3 rotatedMatirx;
	static void setIsAlive(bool isAlive);
	void draw(Core::Graphics&);
	void update(float dt);
	void ModeKeyPressed(Vector2&);


};

#endif
