#ifndef MYRANDOMNUMBER_H
#define MYRANDOMNUMBER_H

#include <stdlib.h>
#include "ExportHeader.h"


class ENGINE_SHARED MyRandomNumber
{
public:
	float MyRandomNumber::RandomFloat();
	float MyRandomNumber::RandomInRange(float min, float max);
};

#endif // !MYRANDOMNUMBER_H
