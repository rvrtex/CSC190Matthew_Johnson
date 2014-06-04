#ifndef GAMESOLUTION_H
#define GAMESOLUTION_H

#include "Core.h"
#include "ProjectileManager.h"
#include "squarePlanet.h"
#include "ParticleEffect.h"
#include "Timer.h"
#include "Enemy.h"


class GameSolution
{
Enemy enemy;

public:
	

	GameSolution(void);
	Timer FPSTimer;
	
	static void AddToList(ParticleEffect&);
	void draw(Core::Graphics&);
	void update(float);
	float angle;
};
#endif
