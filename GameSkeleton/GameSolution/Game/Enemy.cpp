#include "Enemy.h"

Vector2 enemyPoints[] = 
{
	Vector2(+8.0f,0.0f),
	Vector2(0.0f,8.0f),
	Vector2(-8.0f,0.0f),
	Vector2(+0.0f,-8.0f)
};


Enemy::Enemy(void)
{
	isAlive = true;

}

void Enemy::draw(Core::Graphics& g)
{
	const unsigned int NUM_LINES = sizeof(enemyPoints)/sizeof(*enemyPoints);
	for(unsigned int i = 0; i < NUM_LINES; i++)
	{
		const Vector2& first = position+enemyPoints[i];
		const Vector2& second = position+enemyPoints[(i+1)% NUM_LINES];
		g.DrawLine(first.x,first.y,second.x,second.y);
	;}
			
}

void Enemy::update(Vector2 &shipPosition)
{
	
	Vector2 result;
	result = shipPosition - position;
	result = normalized(result);
	velocity = result;
	position.x = velocity.x + position.x;
	position.y = velocity.y + position.y;

}


