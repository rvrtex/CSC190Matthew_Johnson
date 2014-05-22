#include "DrawValues.h"



void DrawValues::DrawValue( Core::Graphics& graphics, int x, int y, float num )
{
	std::stringstream ss;
	ss << num;
	graphics.DrawString( x, y, ss.str().c_str());
};

void DrawValues::DrawValue( Core::Graphics& graphics, int x, int y, Vector2 vector )
{
	std::stringstream ss;
	ss << "Vector x: " << vector.x << " " << "Vector y: " << vector.y;
	graphics.DrawString( x, y, ss.str().c_str());
};

void DrawValues::DrawValue( Core::Graphics& graphics, int x, int y, int num )
{
	std::stringstream ss;
	ss << num;
	graphics.DrawString( x, y, ss.str().c_str());
};

void DrawValues::DrawValue( Core::Graphics& graphics, int x, int y, Matrix3 m)
{

	const int length = 9;
	std::stringstream ss[length];
	int tempX = x;

	for(int i = 0; i < length; i++)
	{

		if(i%3 == 0)
		{
			tempX = x;	
			y += 20;
		}
		
		float trunc = floor((m.matrix[i] * 1000)/1000);
		ss[i] << trunc;
		graphics.DrawString(tempX,y,ss[i].str().c_str());
		tempX +=20;
	}






}
