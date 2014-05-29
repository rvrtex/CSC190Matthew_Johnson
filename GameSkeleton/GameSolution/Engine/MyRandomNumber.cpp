#include "MyRandomNumber.h"

float MyRandomNumber::RandomFloat()
{
	return (float) rand()/ RAND_MAX;
}

float MyRandomNumber::RandomInRange(float min, float max)
{
	return RandomFloat() * (max - min + 1) + min;
}
	