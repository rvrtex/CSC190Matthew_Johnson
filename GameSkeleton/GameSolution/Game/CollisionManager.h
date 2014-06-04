#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "ProjectileManager.h"
#include "SpaceShip.h"
#include "EnemyManager.h"
#include "Core.h"
#include "ParticleEffect.h"

class CollisionManager
{
public:
	ProjectileManager* pm;
	EnemyManager* em;
	SpaceShip* ss;
	GameSolution* gm;
	CollisionManager(SpaceShip& spaceShip, ProjectileManager& projectileManager, EnemyManager& enemyManager, GameSolution& gm);
	void draw(Core::Graphics&);
	void update(float, Vector2&);

	
};

#endif // !COLLISIONMANAGER_H

