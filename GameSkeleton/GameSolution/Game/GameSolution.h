#ifndef GAMESOLUTION_H
#define GAMESOLUTION_H

#include "Core.h"
#include "ProjectileManager.h"
#include "squarePlanet.h"
#include "ParticleEffect.h"

class GameSolution
{

public:
	

	GameSolution(void);
	
	void AddToList(ParticleEffect&);
	void draw(Core::Graphics&);
	void update(float);
	float angle;
};
#endif
