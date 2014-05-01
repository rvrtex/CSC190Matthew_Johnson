#include<iostream>
#include<cmath>
#ifndef VECTOR_2
#define VECTOR_2


struct Vector2
{
	float x;
	float y;

	Vector2(float x = 0, float y = 0) : x(x), y(y) {}

	operator float*(){ return &x; }

	float dotReturn;
	float Dot(const Vector2& a, const Vector2& b)
	{
		return ((a.x)*(b.x)) + ((a.y)*(b.y));

	};

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

Vector2 operator/(const Vector2& left, const float& right)
{
	Vector2 returnVector;
	returnVector.x = left.x / right;
	returnVector.y = left.y / right;

	return returnVector;
}

float Length(const Vector2& data)
{
	return sqrt(pow(data.x, 2) + pow(data.y, 2));
}

float LengthSquared(const Vector2& data)
{
	return pow(Length(data),2);
}


Vector2 normalized(const Vector2& preNormalizedVector)
{
	float length = Length(preNormalizedVector);

	Vector2 normVector;
	normVector = preNormalizedVector / length;
	return normVector;
}

std::ostream& operator<<(std::ostream stream, const Vector2& right)
{
	std::cout << "{" << right.x << ", " << right.y << "}";
	return stream;
}
float zeroCatch = .000000001;

Vector2 cwPerpVector;
Vector2 cwNewData;
Vector2 PerpCW(const Vector2& data)
{
	if (data.x == 0 && data.y == 0)
	{
		cwNewData = Vector2(zeroCatch, zeroCatch);
		cwPerpVector = Vector2(-(cwNewData.y), cwNewData.x);
	}
	else{
		cwPerpVector = Vector2(-(data.y), data.x);
	}
	return cwPerpVector;
}

Vector2 ccwPerpVector;
Vector2 ccwNewData;
Vector2 PerpCCW(const Vector2& data)
{
	if (data.x == 0 && data.y == 0)
	{
		ccwNewData = Vector2(zeroCatch, zeroCatch);
		ccwPerpVector = Vector2(ccwNewData.x, -(ccwNewData.y));

	}
	else{
		ccwPerpVector = Vector2(data.x, -(data.y));
	}
	return ccwPerpVector;

}

float dotReturn;
float Dot(const Vector2& a, const Vector2& b)
{
	return ((a.x)*(b.x)) + ((a.y)*(b.y));
	
};

#endif // !VECTOR2
