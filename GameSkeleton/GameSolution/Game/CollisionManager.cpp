#include "CollisionManager.h"
#include "DrawValues.h"
#include "DebugMemory.h"


Missile missiles[10];


SpaceShip * myShip;


CollisionManager::CollisionManager(){

	EnemyTypeOne* eto = new EnemyTypeOne();
	
	AddEnemyShip(*eto);
	

	for(int i = 0; i < 10; i++)
	{
		Missile m;
		m.isAlive = false;
		missiles[i] = m;
	}
}



static std::vector<Enemy*> enemyShips;


void CollisionManager::AddEnemyShip(Enemy& e)
{

	enemyShips.push_back(&e);
};

void CollisionManager::MissileFired(Vector2& shipPosition, Vector2& endPosition)
{
	for(int i = 0; i < 10; i++)
	{
		if(!missiles[i].isAlive)
		{
			missiles[i].isAlive = true;
			missiles[i].startingPoint = shipPosition;
			missiles[i].destructPoint = endPosition;
			missiles[i].myCurrentPosition = shipPosition;
			missiles[i].myScaler = 1.5f;
			missiles[i].setMissileVelocity();
			break;
		}
	}
};
void CollisionManager::draw(Core::Graphics& g, Vector2& shipPostion)
{
	Vector2 distance;
	
	float lenghOfdistance;



	for(int i = 0; i < 10; ++i)
	{
		for(std::vector<Enemy>::size_type j = 0; j < enemyShips.size(); j++)
		{
			
			distance = shipPostion - enemyShips[j]->position;
			lenghOfdistance = Length(distance);
			if(lenghOfdistance < 30 && spaceShipLives)
			{
				enemyShips[j]->HasDied();
				SpaceShip::setIsAlive(false);
				spaceShipLives = false;

			}

			if(missiles[i].isAlive && enemyShips[j]->isAlive)
			{			
				distance = missiles[i].myCurrentPosition - enemyShips[j]->position;
				lenghOfdistance = Length(distance);
				if(lenghOfdistance < 7)
				{
					float tempScore = enemyShips[j]->scoreValue;
					GameSolution::AddToScore(tempScore);				
					GameSolution::UseEffect(1,enemyShips[j]->position,enemyShips[j]->velocity);
					missiles[i].isAlive = false;
					enemyShips[j]->HasDied();

				}	

			}
			
			enemyShips[j]->Draw(g);

		}
		if(missiles[i].isAlive)
		{
			missiles[i].draw(g);
		}
	}
	
	shipPostion;

};

void CollisionManager::update(float dt, Vector2& shipPosition){dt; shipPosition;

for(std::vector<Enemy>::size_type j = 0; j < enemyShips.size(); j++)
{
	enemyShips[j]->Update(shipPosition);
}

};


void CollisionManager::ShutDown()
{
	//for(int i =0; i < 10; i++)
	//{
	//	Missile *m =  &missiles[i];
	//	delete &m;
	//}

	int sizeOfEnemyShips = enemyShips.size();

	for(int j = 0; j < sizeOfEnemyShips; j++)
	{
		delete enemyShips[j];
	}
	enemyShips.clear();
}
