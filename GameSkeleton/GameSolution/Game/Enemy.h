#ifndef ENEMY_H
#define ENEMY_H

#include "Vector2.h"
#include "Core.h"
class Enemy
{
public:
	Enemy(void);
	Vector2 position;
	Vector2 velocity;
	void draw(Core::Graphics&);
	void update(Vector2&);
	bool isAlive;
};

#endif // !ENEMY_H
