#ifndef GAMESOLUTION_H
#define GAMESOLUTION_H

#include "Core.h"
#include "ProjectileManager.h"
#include "squarePlanet.h"
#include "ParticleEffect.h"
#include "Timer.h"
#include "Enemy.h"
#include <vector>


class GameSolution
{
public:
	

	GameSolution(void);
	Timer FPSTimer;
	
	static float GetDT();
	static void AddToList(ParticleEffect&);
	static void AddToScore(float incramentAmount);

	void draw(Core::Graphics&);
	void update(float);
	float angle;
};
#endif
