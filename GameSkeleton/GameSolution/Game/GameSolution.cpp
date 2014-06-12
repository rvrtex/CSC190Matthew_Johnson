#include "GameSolution.h"
#include "Core.h"
#include "SpaceShip.h"
#include "LerpingRoid.h"
#include "DrawValues.h"
//#include "ProjectileManager.h"
#include "GameSolution.h"
#include "Profiler.h"
#include "CollisionManager.h"
#include "SpaceShip.h"

//ProjectileManager pm;

SpaceShip meShip;
//LerpingRoid meLerp;
//Timer* timer;
float myDT;
CollisionManager *cm;


DrawValues drawValues;
Vector2 startingPosition(500,275);

ParticleEffect listOfParticleEffects[20];
Vector2 Dimension[] = {
	Vector2(8.0f, 0.0f),
	Vector2(8.0f, 8.0f),
	Vector2(-8.0f, 8.0f),
	Vector2(-8.0f, 0.0f)

};
GameSolution::GameSolution()
{

	//timer =  new Timer();
	//FPSTimer.Initialize();
	Vector2 startPosition(512.0f,364.0f);
	Vector2 firstEnemyStartingPosition(0.0f,MyRandomNumber::RandomInRange(0.0f,728.0f));

	/*ParticleEffect* pe = new ParticleEffect(500,2,startPosition,startPosition,myDT);
	pe->TunnelEffect();
	AddToList(*pe);*/

	//Profiler::getInstance().startUp("ProfileTest.csv");

	meShip = SpaceShip(*this);


	meShip.position = Vector2(500,300);
	//meLerp.position = Vector2(+50.0f,50.0f);
	cm = new CollisionManager();

	for(int i = 0 ; i < 20; i++)
	{
		ParticleEffect pe(myDT,3);
		pe.isFinished = true;
		listOfParticleEffects[i] = pe;

	}


}
float GameSolution::GetDT()
{
	return myDT;
}

float gameScore = 0;

float myAngle = 0;

//
void GameSolution::update(float dt)
{	
	myDT = dt;
	cm->update(myDT,meShip.position);
}

void GameSolution::UseEffect(int effect, Vector2 position, Vector2 velocity)
{
	for(int i = 1; i < 20; i++)
	{
		if(listOfParticleEffects[i].isFinished)
		{	
			if(effect == 1)
			{
				listOfParticleEffects[i].effect = effect;
				listOfParticleEffects[i].position = position;
				listOfParticleEffects[i].velocity = velocity;
				listOfParticleEffects[i].BounceEffect();
				break;
			}
			else
			{
				listOfParticleEffects[0].effect = effect;
				listOfParticleEffects[0].position = startingPosition;
				listOfParticleEffects[0].velocity = startingPosition;
				listOfParticleEffects[0].TunnelEffect();
				break;
			}
		}

	}

}

void GameSolution::AddToScore(float incramentAmount)
{
	gameScore = gameScore+incramentAmount;
}


void GameSolution::draw(Core::Graphics& graphics)
{
	//timer->lap();
	//FPSTimer.lap();
	//Profiler::getInstance().newFrame();
	meShip.update(myDT);
	//meLerp.update(myDT);

	//float timerEleapsed;

	//timerEleapsed =  FPSTimer.lastLapTime();
	//graphics.DrawString(550,600,"SPF");
	//drawValues.DrawValue(graphics,600,600,timerEleapsed);
	//graphics.DrawString(550,650,"FPS");
	//drawValues.DrawValue(graphics,600,650,(1/timerEleapsed));

	//timer->Initialize();
	{

		//timer->Start();
		meShip.draw(graphics);
		//timer->Stop();
		//Profiler::getInstance().addEntry("Ship Draw", timer->lastLapTime());
	}

	{
		//timer->Start();
		//	meLerp.draw(graphics);
		//timer->Stop();
		//Profiler::getInstance().addEntry("Lerp Draw", timer->lastLapTime());

	}


	{
		//timer->Start();
		cm->draw(graphics,meShip.position);
		//timer->Stop();
		//Profiler::getInstance().addEntry("CM Draw", timer->lastLapTime());

	}


	Matrix3 initialMatrix;
	//squarePlanet sp = recusivePlanets(3,0,0,graphics,initialMatrix);
	{
		
		//timer->Start();
		
	


		for(int it = 0; it < 20; it++)
		{
			if(!listOfParticleEffects[it].isFinished)
			{
				if(it == 0)
				{
					int j;
			j = 5;
				}
				
				listOfParticleEffects[it].draw(graphics);

			}

		}


		//timer->Stop();
		//Profiler::getInstance().addEntry("PE Draw", timer->lastLapTime());

		//timer->shutdown();
	}

	drawValues.DrawValue(graphics);
	drawValues.DrawValue(graphics,"Score: ",gameScore);

}





//squarePlanet recusivePlanets(int n, int cn,float angle, Core::Graphics& g, Matrix3 myPosition)
//{
//	Matrix3 translation;
//	Matrix3 rotation;
//	Matrix3 finalLocation;
//
//	angle;
//	myAngle = myAngle + ((-.1f * (2.0f*3.14f)) /100.0f);
//
//
//	Vector2 newPosition(30.0f*((float)cn+1),30.0f*((float)cn+1));
//	translation.Translation(newPosition);
//	rotation.Rotation(myAngle);
//	finalLocation = rotation*translation;
//	finalLocation = finalLocation*myPosition;
//
//
//	if(cn == n)
//	{		
//		squarePlanet sp;
//		sp.position = startingPosition;
//
//		for(int i = 0; i < 4; i++)
//		{
//			sp.dimensions[i] = Dimension[i]*((float)cn)+sp.position;
//		}		
//		sp.draw(g);
//		return sp;	
//	}
//	else
//	{		
//		squarePlanet sp = recusivePlanets(n,cn+1,myAngle,g,finalLocation);		
//
//		for(int i = 0; i < 4; i++)
//		{
//			sp.dimensions[i] = Dimension[i]*((float)cn+1);
//		}
//
//		for(int i = 0; i < 4; i++)
//		{
//			sp.dimensions[i] = finalLocation*sp.dimensions[i];
//			sp.dimensions[i] = sp.dimensions[i]+sp.position;
//		}
//		sp.draw(g);
//		return sp;
//
//	}
//}
