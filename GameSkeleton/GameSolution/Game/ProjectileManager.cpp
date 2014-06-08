//#include "ProjectileManager.h"
//
//Enemy enemy;
//ProjectileManager::ProjectileManager(void)
//{
//	enemy.position = Vector2(0,0);
//
//}
//
//
//std::vector<Missile> missilesFired;
//
//
//
//
//void ProjectileManager::MFired(Missile& m )
//{
//	missilesFired.push_back(m);
//}
//
//
//
//void ProjectileManager::draw(Core::Graphics& g, Vector2& shipPosition)
//{
//	enemy.update(shipPosition);
//	enemy.draw(g);
//	Vector2 distance;
//	float lenghOfdistance;
//	for(std::vector<Missile>::size_type  it = 0; it != missilesFired.size(); ++it)
//	{
//
//		if(missilesFired[it].isAlive)
//		{			
//			distance = missilesFired[it].myCurrentPosition - enemy.position;
//			lenghOfdistance = Length(distance);
//			if(lenghOfdistance < 7)
//			{
//			
//				ParticleEffect* pe = new ParticleEffect(500,1,enemy.position,enemy.velocity);
//				pe->BounceEffect();
//				GameSolution::AddToList(*pe);
//				missilesFired[it].isAlive = false;
//				enemy.position = Vector2(0,0);
//
//			}
//
//
//			missilesFired[it].draw(g);
//
//		}
//	}
//}
