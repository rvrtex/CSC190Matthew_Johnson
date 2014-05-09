#include "LerpingRoid.h"



Vector2 lerpingPoints[] ={
	Vector2(+0.0f,8.0f),
	Vector2(-8.0f,0.0f),
	Vector2(+0.0f,-8.0f),
	Vector2(+8.0f,0.0f)
};

Vector2 pathToFollow[] = {
	Vector2(+50.0f,50.0f),
	Vector2(200.0f,50.0f),
	Vector2(50.0f,400.0f),
	Vector2(200.0f,200.0f)
};



void LerpingRoid::draw(Core::Graphics& g)
{
	const unsigned int NUM_LINES = sizeof(lerpingPoints)/sizeof(*lerpingPoints);
	for(unsigned int i = 0; i < NUM_LINES; i++)
	{
		const Vector2& firstPath = pathToFollow[i];
		const Vector2& secondPath = pathToFollow[(i+1)%NUM_LINES];
		g.DrawLine(firstPath.x,firstPath.y,secondPath.x,secondPath.y);

		const Vector2& first = position+lerpingPoints[i];
		const Vector2& second = position+lerpingPoints[(i+1)% NUM_LINES];
		g.DrawLine(first.x,first.y,second.x,second.y);
	;}
	
	
}
int curLocationInArray = 0;
float scaler = 0;

void LerpingRoid::update(float dt)
{



	Vector2 firstLerp = pathToFollow[curLocationInArray];
	Vector2 secondLerp = pathToFollow[(curLocationInArray+1)%4];
	float lenghtOfLerp = Length2Vectors(firstLerp,secondLerp);
	scaler += dt*200*(100/lenghtOfLerp);
	
	position = LERP(firstLerp,secondLerp,scaler);
	if(scaler >=1)
	{
		curLocationInArray++;		
		scaler = 0;
		firstLerp = secondLerp;
		secondLerp = pathToFollow[curLocationInArray];
		if(curLocationInArray == 4)
		{
			curLocationInArray =0;
		}
	}
}
