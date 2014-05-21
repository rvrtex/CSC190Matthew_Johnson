#include "Missile.h"

Vector2 missileShape[] = {
	Vector2(0.0f,1.0f),
	Vector2(0.0f,0.0f)
};

Vector2 rotatedMissileShape[] = {
	Vector2(0.0f,1.0f),
	Vector2(0.0f,0.0f)
};



Missile::Missile(float dt)
{
	missileDt = dt;
	isAlive = true;
	myScaler = .9f;
	quickTurnAround = 10;	
}
void Missile::draw(Core::Graphics& g)
{	 
	myScaler += missileDt *.9f;
	vectorOfTurretToMouseClickLocation = startingPoint - destructPoint;
	normolizedVector = normalized(vectorOfTurretToMouseClickLocation);
	normolizedVector = normolizedVector*myScaler;
	myCurrentPosition = myCurrentPosition - normolizedVector;
	missileTransform.Translation(myCurrentPosition);
	Vector2 acceleration(0.f,-missileDt*quickTurnAround);			

	if(myScaler > 4)
	{
		isAlive = false;
	}
	
	const unsigned int NUM_LINES = sizeof(missileShape)/sizeof(*missileShape);
	for(unsigned int i = 0; i < NUM_LINES; i++)
	{
		
		const Vector2& first = missileTransform*rotatedMissileShape[i];
		const Vector2& second = missileTransform*rotatedMissileShape[(i+1)% NUM_LINES];
		g.DrawLine(first.x,first.y,second.x,second.y);
		}
	lastPosition = myCurrentPosition;
	myCurrentPosition.x = myCurrentPosition.x + velocity.x * missileDt*quickTurnAround;
	myCurrentPosition.y = myCurrentPosition.y + velocity.y * missileDt*quickTurnAround;
}



