#ifndef MYRANDOMNUMBER_H
#define MYRANDOMNUMBER_H

#include <stdlib.h>
#include "ExportHeader.h"


class MyRandomNumber
{
public:
	ENGINE_SHARED static float MyRandomNumber::RandomFloat();
	ENGINE_SHARED static float MyRandomNumber::RandomInRange(float min, float max);

};

#endif // !MYRANDOMNUMBER_H
