#include "GameSolution.h"
#include "Core.h"
#include "SpaceShip.h"
#include "LerpingRoid.h"
#include "DrawValues.h"
#include "ProjectileManager.h"
#include "GameSolution.h"
#include "Profiler.h"

ProjectileManager pm;
SpaceShip meShip;
LerpingRoid meLerp;
Timer* timer;
float myDT;


DrawValues drawValues;
Vector2 startingPosition(500,275);

std::vector<ParticleEffect*> listOfParticleEffects;
Vector2 Dimension[] = {
	Vector2(8.0f, 0.0f),
	Vector2(8.0f, 8.0f),
	Vector2(-8.0f, 8.0f),
	Vector2(-8.0f, 0.0f)

};
GameSolution::GameSolution()
{
	timer =  new Timer();
	FPSTimer.Initialize();
	Vector2 startPosition(512.0f,364.0f);

	ParticleEffect* pe = new ParticleEffect(500,2,startPosition,startPosition);
	pe->TunnelEffect();
	AddToList(*pe);

	Profiler::getInstance().startUp("ProfileTest.csv");
	meShip = SpaceShip(pm,*this, timer);


	meShip.position = Vector2(500,300);
	meLerp.position = Vector2(+50.0f,50.0f);
	enemy.position = Vector2(0,0);

}



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

void GameSolution::update(float dt)
{	
	
	myDT = dt;
}

void GameSolution::AddToList(ParticleEffect &pe)
{
	listOfParticleEffects.push_back(&pe);
}

void GameSolution::draw(Core::Graphics& graphics)
{
	timer->lap();
	FPSTimer.lap();
	Profiler::getInstance().newFrame();
	meShip.update(myDT);
	meLerp.update(myDT);

	float timerEleapsed;

	timerEleapsed =  FPSTimer.lastLapTime();
	graphics.DrawString(550,600,"SPF");
	drawValues.DrawValue(graphics,600,600,timerEleapsed);
	graphics.DrawString(550,650,"FPS");
	drawValues.DrawValue(graphics,600,650,(1/timerEleapsed));

	timer->Initialize();
	{

		timer->Start();
		meShip.draw(graphics);
		timer->Stop();
		Profiler::getInstance().addEntry("Ship Draw", timer->lastLapTime());
	}

	{
		timer->Start();
		meLerp.draw(graphics);
		timer->Stop();
		Profiler::getInstance().addEntry("Lerp Draw", timer->lastLapTime());

	}


	{
		timer->Start();
		pm.draw(graphics,meShip.position);
		timer->Stop();
		Profiler::getInstance().addEntry("PM Draw", timer->lastLapTime());

	}


	Matrix3 initialMatrix;
	squarePlanet sp = recusivePlanets(3,0,0,graphics,initialMatrix);
	{
		timer->Start();
		if(listOfParticleEffects.size() > 0)
		{
			std::vector<ParticleEffect*> tempListForDeleting;

			for(std::vector<ParticleEffect>::size_type  it = 0; it != listOfParticleEffects.size(); ++it)
			{
				if(!listOfParticleEffects[it]->isFinished)
				{
				
					listOfParticleEffects[it]->draw(graphics);
				}
				else
				{
					ParticleEffect pe = *listOfParticleEffects[it];
					tempListForDeleting.push_back(&pe);
				}
			}
			for(std::vector<ParticleEffect>::size_type  it = 0; it < tempListForDeleting.size(); ++it)
			{							
				ParticleEffect pe = *tempListForDeleting[it];
				listOfParticleEffects.erase(std::find(listOfParticleEffects.begin(), listOfParticleEffects.end(), &pe), listOfParticleEffects.end());
			}
		}
		timer->Stop();
		Profiler::getInstance().addEntry("PE Draw", timer->lastLapTime());
		
		timer->shutdown();
	}
	
}