#ifndef GAMESOLUTION_H
#define GAMESOLUTION_H

#include "Core.h"
#include "ProjectileManager.h"
#include "squarePlanet.h"

class GameSolution
{
public:
	GameSolution(void);
	void draw(Core::Graphics&);
	void update(float);
	float angle;
};
#endif
