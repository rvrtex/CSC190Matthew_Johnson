#include "EnemyTypeTwo.h"
#include "CollisionManager.h"

Vector2 enemyTwoPoints[] = 
{
	Vector2(+8.0f,0.0f),
	Vector2(0.0f,8.0f),
	Vector2(-8.0f,0.0f),
	Vector2(+0.0f,-8.0f)
};


EnemyTypeTwo::EnemyTypeTwo(void)
{
	isAlive = true;
	scoreValue = 2.0f;
	Vector2 tempV2(0.0f,MyRandomNumber::RandomInRange(1024.0f,0.0f));
	position = tempV2;
	velocity = Vector2(5.0f,5.0f);
}

void EnemyTypeTwo::Draw(Core::Graphics& g)
{
	const unsigned int NUM_LINES = sizeof(enemyTwoPoints)/sizeof(*enemyTwoPoints);
	for(unsigned int i = 0; i < NUM_LINES; i++)
	{
		const Vector2& first = position+enemyTwoPoints[i];
		const Vector2& second = position+enemyTwoPoints[(i+1)% NUM_LINES];
		g.SetColor(RGB(255,153,0));
		g.DrawLine(first.x,first.y,second.x,second.y);
		g.SetColor(RGB(255,255,255));
	;}
			
}



void EnemyTypeTwo::Update(Vector2 &shipPosition)
{
	Vector2 result;
	result = shipPosition - position;
	result = normalized(result);
	velocity = result;
	position.x = velocity.x + position.x;
	position.y = velocity.y + position.y;

	if(position.x > 1024 || position.y > 728 || position.x < -1 || position.y < -1)
	{
		ResetPosition();
	}
}

void EnemyTypeTwo::ResetPosition()
{
	Vector2 tempV2(0.0f,MyRandomNumber::RandomInRange(1024.0f,0.0f));
	position = tempV2;
}

void EnemyTypeTwo::HasDied()
{
	ResetPosition();
	EnemyTypeTwo* em = new EnemyTypeTwo();
	CollisionManager::AddEnemyShip(*em);

}