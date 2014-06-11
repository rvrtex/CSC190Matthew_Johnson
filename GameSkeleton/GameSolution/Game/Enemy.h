#ifndef ENEMY_H
#define ENEMY_H

#include "Vector2.h"
#include "Core.h"
#include "MyRandomNumber.h"
class Enemy
{
protected:

public:
	bool isAlive;
	Vector2 position;
	Vector2 velocity;
	float scoreValue;
	virtual void Draw(Core::Graphics&);
	virtual void Update(Vector2&);
	virtual void ResetPosition();
	virtual void HasDied();

};

#endif // !ENEMY_H
