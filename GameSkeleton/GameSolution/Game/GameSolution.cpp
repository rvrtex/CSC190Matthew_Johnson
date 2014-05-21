#include "GameSolution.h"


GameSolution::GameSolution(void)
{
	ProjectileManager pm;
}

Vector2 Dimension[] = {
	Vector2(8.0f, 0.0f),
	Vector2(8.0f, 8.0f),
	Vector2(-8.0f, 8.0f),
	Vector2(-8.0f, 0.0f)

};

Vector2 startingPosition(500,275);
float myAngle = 0;

squarePlanet recusivePlanets(int n, int cn,float angle, Core::Graphics& g, Matrix3 myPosition)
{
	Matrix3 translation;
	Matrix3 rotation;
	Matrix3 finalLocation;

	angle;
	myAngle = myAngle + ((-.1f * (2.0f*3.14f)) /100.0f);
	
	
	Vector2 newPosition(30.0f*((float)cn+1),30.0f*((float)cn+1));
	translation.Translation(newPosition);
	rotation.Rotation(myAngle);
	finalLocation = rotation*translation;
	finalLocation = finalLocation*myPosition;
	
	
	if(cn == n)
	{		
		squarePlanet sp;
		sp.position = startingPosition;

		for(int i = 0; i < 4; i++)
		{
			sp.dimensions[i] = Dimension[i]*((float)cn)+sp.position;
		}		
		sp.draw(g);
		return sp;	
	}
	else
	{		
		squarePlanet sp = recusivePlanets(n,cn+1,myAngle,g,finalLocation);		

		for(int i = 0; i < 4; i++)
		{
			sp.dimensions[i] = Dimension[i]*((float)cn+1);
		}
				
		for(int i = 0; i < 4; i++)
		{
			sp.dimensions[i] = finalLocation*sp.dimensions[i];
			sp.dimensions[i] = sp.dimensions[i]+sp.position;
		}
		sp.draw(g);
		return sp;

	}
}

void GameSolution::draw(Core::Graphics& g)
{
	Matrix3 initialMatrix;
	squarePlanet sp = recusivePlanets(5,0,0,g,initialMatrix);
}