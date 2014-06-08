//#include "EnemyManager.h"
//
//
//EnemyManager::EnemyManager(void)
//{
//}
//std::vector<Enemy> enemyShips;
//
//void EnemyManager::EnemyShipCreated(Enemy& e )
//{
//	enemyShips.push_back(e);
//}
//
//void EnemyManager::draw(Core::Graphics& g){
//	Vector2 startingPosition(500,275);
//
//	for(std::vector<Enemy>::size_type  it = 0; it != enemyShips.size(); ++it)
//	{
//		
//		if(enemyShips[it].isAlive)
//		{
//			enemyShips[it].draw(g);
//			
//		}
//		else
//		{
//			enemyShips[it].position = startingPosition;
//			enemyShips[it].isAlive = true;
//		}
//	}
//}
//
