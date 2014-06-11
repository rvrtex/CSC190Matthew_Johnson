#pragma once
#include "enemy.h"
//#include "CollisionManager.h"

class EnemyTypeOne :
	public Enemy
{
private:
	
public:
	
	EnemyTypeOne(void);
	virtual void Draw(Core::Graphics&);
	virtual void Update(Vector2&);
	virtual void ResetPosition();
	virtual void HasDied();
		


};

