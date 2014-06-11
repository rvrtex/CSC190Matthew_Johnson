#include "EnemyTypeOne.h"
#include "CollisionManager.h"

Vector2 enemyPoints[] = 
{
	Vector2(+8.0f,0.0f),
	Vector2(0.0f,8.0f),
	Vector2(-8.0f,0.0f),
	Vector2(+0.0f,-8.0f)
};

EnemyTypeOne::EnemyTypeOne(void)
{
	isAlive = true;
	Vector2 tempV2(0.0f,MyRandomNumber::RandomInRange(0.0f,728.0f));
	position = tempV2;
	velocity = Vector2(5.0f,0.0f);
	scoreValue = 1.0f;
	
}


void EnemyTypeOne::Draw(Core::Graphics& g)
{
	const unsigned int NUM_LINES = sizeof(enemyPoints)/sizeof(*enemyPoints);
	for(unsigned int i = 0; i < NUM_LINES; i++)
	{
		const Vector2& first = position+enemyPoints[i];
		const Vector2& second = position+enemyPoints[(i+1)% NUM_LINES];
		g.SetColor(RGB(255,204,0));
		g.DrawLine(first.x,first.y,second.x,second.y);
		g.SetColor(RGB(255,255,255));
	;}
			
}



void EnemyTypeOne::Update(Vector2 &shipPosition)
{
	shipPosition;
	position.x = velocity.x + position.x;
	position.y = velocity.y + position.y;
	if(position.x > 1024 || position.y > 728 || position.x < -1 || position.y < -1)
	{
		ResetPosition();
	}
}

void EnemyTypeOne::ResetPosition()
{
	Vector2 tempV2(0.0f,MyRandomNumber::RandomInRange(0.0f,728.0f));
	position = tempV2;
}

void EnemyTypeOne::HasDied()
{
	ResetPosition();
	EnemyTypeOne* em = new EnemyTypeOne();
	CollisionManager::AddEnemyShip(*em);

}