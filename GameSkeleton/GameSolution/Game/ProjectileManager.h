#ifndef PROJECTILEMANAGER_H
#define PROJECTILEMANAGER_H

#include "Core.h"
#include "Missile.h"
#include <vector>
#include "Enemy.h"
#include "GameSolution.h"
#include "ParticleEffect.h"

class ProjectileManager
{
	Enemy enemy;

public:
	ProjectileManager(void);
	void makeEnemy(Enemy e);
	void MFired(Missile& m);
	std::vector<Missile>* getMisslesFired();

	void draw(Core::Graphics&, Vector2&);
	void update(float);

};

#endif
