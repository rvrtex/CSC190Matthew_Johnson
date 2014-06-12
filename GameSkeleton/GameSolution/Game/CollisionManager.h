#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "SpaceShip.h"
#include "Core.h"
#include "ParticleEffect.h"
#include "Enemy.h"
#include "Missile.h"
#include <vector>
#include "EnemyTypeOne.h"
#include "EnemyTypeTwo.h"


class CollisionManager
{
	/*
	std::vector<Enemy *> enemyShips;
	std::vector<Missile *> missilesFired;
	*/
	bool spaceShipLives;
public:
	CollisionManager();
	
	static void AddEnemyShip(Enemy& e);
	static void MissileFired(Vector2&, Vector2&);
	void draw(Core::Graphics&, Vector2&);
	void update(float, Vector2&);
	void ShutDown();
	
};

#endif // !COLLISIONMANAGER_H