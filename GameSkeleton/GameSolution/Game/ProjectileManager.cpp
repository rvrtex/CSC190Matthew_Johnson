#include "ProjectileManager.h"


ProjectileManager::ProjectileManager(void)
{

}

std::vector<Missile> missilesFired;

void ProjectileManager::MFired(Missile& m )
{
	missilesFired.push_back(m);
}

void ProjectileManager::draw(Core::Graphics& g){
	for(std::vector<Missile>::size_type  it = 0; it != missilesFired.size(); ++it)
	{
		
		if(missilesFired[it].isAlive)
		{
			missilesFired[it].draw(g);
			
		}
	}
}
