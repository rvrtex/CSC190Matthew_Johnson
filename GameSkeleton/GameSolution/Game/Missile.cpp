#include "Missile.h"
#include "DebugMemory.h"


Vector2 missileShape[] = {
	Vector2(0.0f,5.0f),
	Vector2(0.0f,0.0f)
};

Vector2 rotatedMissileShape[] = {
	Vector2(0.0f,5.0f),
	Vector2(0.0f,0.0f)
};

Missile::Missile()
{
	isAlive = false;
	myScaler = 1.5f;
	quickTurnAround = 10;	
}


Missile::Missile(float dt)
{
	missileDt = dt;
	isAlive = false;
	myScaler = 1.5f;
	quickTurnAround = 10;	
}

void Missile::setMissileVelocity()
{



}
void Missile::draw(Core::Graphics& g)
{	 
	missileDt = GameSolution::GetDT();

	myScaler += missileDt *2.0f;
	
	vectorOfTurretToMouseClickLocation = startingPoint - destructPoint;
	normolizedVector = normalized(vectorOfTurretToMouseClickLocation);
	normolizedVector = normolizedVector*myScaler;
	myCurrentPosition = myCurrentPosition - normolizedVector;
	missileTransform.Translation(myCurrentPosition);
	Vector2 acceleration(0.f,-missileDt*quickTurnAround);			

	if(myScaler > 6)
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
	velocity.x = missileDt*quickTurnAround;
	velocity.y = missileDt*quickTurnAround;
	myCurrentPosition.x = myCurrentPosition.x + velocity.x;
	myCurrentPosition.y = myCurrentPosition.y + velocity.y;
}



