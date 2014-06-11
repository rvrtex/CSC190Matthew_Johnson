#include "MyRandomNumber.h"

ENGINE_SHARED float MyRandomNumber::RandomFloat()
{
	return (float) rand()/ RAND_MAX;
}

ENGINE_SHARED float MyRandomNumber::RandomInRange(float min, float max)
{
	return RandomFloat() * (max - min + 1) + min;
}
	