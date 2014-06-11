#pragma once
#include "enemy.h"
class EnemyTypeTwo :
	public Enemy
{
public:
	EnemyTypeTwo(void);
	virtual void Draw(Core::Graphics&);
	virtual void Update(Vector2&);
	virtual void ResetPosition();
	virtual void HasDied();
		
};

