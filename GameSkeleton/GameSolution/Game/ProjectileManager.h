#ifndef PROJECTILEMANAGER_H
#define PROJECTILEMANAGER_H

#include "Core.h"
#include "Missile.h"
#include <vector>

class ProjectileManager
{
public:
	ProjectileManager(void);
	
	void MFired(Missile& m);

	void draw(Core::Graphics&);
	void update(float);

};

#endif
