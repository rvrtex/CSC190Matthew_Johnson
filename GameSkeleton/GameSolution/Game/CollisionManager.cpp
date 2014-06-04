//#include "CollisionManager.h"
//
//ProjectileManager* pm;
//EnemyManager* em;
//SpaceShip* ss;
//GameSolution* gm;
//
//CollisionManager::CollisionManager(SpaceShip& spaceShip, ProjectileManager& projectileManager, EnemyManager& enemyManager, GameSolution& gameSolution)
//{
//	ss = &spaceShip;
//	pm = &projectileManager;
//	em = &enemyManager;
//	gm = &gameSolution;
//}
//
//void CollisionManager::draw(Core::Graphics& g)
//{
//	Vector2 distance;
//	Vector2 newPosition(200.0f,200.0f);
//	
//
//
//	float myLength;
//	for(std::vector<Missile>::size_type  i = 0; i != pm -> missilesFired->size(); ++i)
//	{
//		for(std::vector<Enemy>::size_type  j = 0; j != em->enemyShips.size(); ++j)
//		{
//			distance = (&missilesFired[i]).myCurrentPosition) - (em->enemyShips[j].position);
//			myLength = Length(distance);
//			if(myLength < 5)
//			{
//				em->enemyShips[j].isAlive = false;
//				Enemy ememy;
//				ememy.position = newPosition;
//				em->enemyShips.push_back(ememy);
//				ParticleEffect pe(50,2,em->enemyShips[j].position,em->enemyShips[j].velocity);
//				pe.BounceEffect();
//				gm->AddToList(pe);
//
//				em->draw(g);
//
//			}
//		}
//		pm->draw(g);
//	}
//}
//
//
