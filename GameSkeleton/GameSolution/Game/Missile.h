#ifndef MISSILE_H
#define MISSILE_H

#include "Vector2.h"
#include "Core.h"
#include "Matrix3.h"



class Missile
{
public:
	Missile(void);
	Missile(float);
	Vector2 destructPoint;
	Vector2 startingPoint;
	Vector2 lastPosition;
	Vector2 velocity;
	Vector2 vectorOfTurretToMouseClickLocation;
	Vector2 normolizedVector;
	float missileDt;
	unsigned int quickTurnAround;
	Matrix3 missileTransform;
	float dotProd;
	float lastDotProd;
	float myScaler;
Vector2 resultVector;

	Vector2 myCurrentPosition;

	bool isAlive;


	void draw(Core::Graphics&);
	void update(float);
};

#endif // !MISSILE_H

