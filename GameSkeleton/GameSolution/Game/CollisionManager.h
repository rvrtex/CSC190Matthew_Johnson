#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "SpaceShip.h"
#include "Core.h"
#include "ParticleEffect.h"
#include "Enemy.h"
#include "Missile.h"
#include <vector>

class CollisionManager
{
	/*std::vector<Enemy> enemyShips;
	std::vector<Missile> missilesFired;
	*/

public:
	
	CollisionManager();
	static void AddEnemyShip(Enemy& e);
	static void MissileFired(Missile& m);
	void draw(Core::Graphics&, Vector2&);
	void update(float, Vector2&);

	
};

#endif // !COLLISIONMANAGER_H

