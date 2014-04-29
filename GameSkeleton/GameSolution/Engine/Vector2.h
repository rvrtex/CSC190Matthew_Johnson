#ifndef VECTOR_2
#define VECTOR_2;
#endif // !VECTOR2

#include<iostream>



struct Vector2
{
	float x;
	float y;
	
	Vector2(float x = 0, float y = 0) : x(x), y(y) {}
	
};

Vector2 operator+(const Vector2& left, const Vector2& right)
{
	Vector2 returnVector;
	returnVector.x = left.x + right.x;
	returnVector.y = left.y + right.y;

	return returnVector;

}

Vector2 operator-(const Vector2& left, const Vector2& right)
{
	Vector2 returnVector;
	returnVector.x = left.x - right.x;
	returnVector.y = left.y - right.y;

	return returnVector;
}

Vector2 operator*(const float& left, const Vector2& right)
{
	Vector2 returnVector;
	returnVector.x = left * right.x;
	returnVector.y = left * right.y;

	return returnVector;
}

Vector2 operator*(const Vector2& left, const float& right)
{
	Vector2 returnVector;
	returnVector.x = left.x * right;
	returnVector.y = left.y * right;

	return returnVector;
}


std::ostream& operator<<(std::ostream stream, const Vector2& right)
{
	std::cout << "{" << right.x << ", " << right.y << "}";
	return stream;
}
