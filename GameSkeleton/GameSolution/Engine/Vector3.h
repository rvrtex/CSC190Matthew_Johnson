#ifndef VECTOR_3
#define VECTOR_3
#include<iostream>
#include<cmath>

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

	operator float*(){ return &x; }	

};

#endif