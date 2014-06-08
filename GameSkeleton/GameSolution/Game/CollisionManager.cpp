#include "CollisionManager.h"



CollisionManager::CollisionManager()
{

}


static std::vector<Missile> missilesFired;
static std::vector<Enemy> enemyShips;


void CollisionManager::AddEnemyShip(Enemy& e)
{
	enemyShips.push_back(e);
};

void CollisionManager::MissileFired(Missile& m)
{
	missilesFired.push_back(m);
};
void CollisionManager::draw(Core::Graphics& g, Vector2& shipPostion)
{
	Vector2 distance;
	float lenghOfdistance;
	for(std::vector<Missile>::size_type  i = 0; i < missilesFired.size(); ++i)
	{
		for(std::vector<Enemy>::size_type j = 0; j < enemyShips.size(); j++)
		{

			if(missilesFired[i].isAlive && enemyShips[j].isAlive)
			{			
				distance = missilesFired[i].myCurrentPosition - enemyShips[j].position;
				lenghOfdistance = Length(distance);
				if(lenghOfdistance < 7)
				{
					ParticleEffect* pe = new ParticleEffect(500,1,enemyShips[j].position,enemyShips[j].velocity);
					pe->BounceEffect();
					GameSolution::AddToList(*pe);
					missilesFired[i].isAlive = false;
					enemyShips[j].position = Vector2(0,0);
					
				}	
				
			}
			enemyShips[j].draw(g);
			
		}
		if(missilesFired[i].isAlive)
			{
				missilesFired[i].draw(g);
			}
	}
	shipPostion;
	};
void CollisionManager::update(float dt, Vector2& shipPosition){dt;shipPosition;};


