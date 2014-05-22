#ifndef DRAWVALUES_H
#define DRAWVALUES_H

#include <sstream>
#include "Vector2.h"
#include "Core.h"
#include "Matrix3.h"
#include <math.h>

class DrawValues
{
public:
	void DrawValue( Core::Graphics& graphics, int x, int y, float num );
	void DrawValue( Core::Graphics& graphics, int x, int y, Vector2 vector );
	void DrawValue( Core::Graphics& graphics, int x, int y, int num );
	void DrawValue( Core::Graphics& graphics, int x, int y,  Matrix3 m);


};
#endif // !DRAWVALUES_H



