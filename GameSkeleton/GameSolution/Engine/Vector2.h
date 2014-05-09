
#ifndef VECTOR_2
#define VECTOR_2
#include<iostream>
#include<cmath>

struct Vector2
{
	float x;
	float y;

	Vector2(float x = 0, float y = 0) : x(x), y(y) {}

	operator float*(){ return &x; }

	
	float Dot(const Vector2& a, const Vector2& b)
	{
		return ((a.x)*(b.x)) + ((a.y)*(b.y));

	};

};



inline Vector2 operator+(const Vector2& left, const Vector2& right)
{
	Vector2 returnVector;
	returnVector.x = left.x + right.x;
	returnVector.y = left.y + right.y;

	return returnVector;

}


inline Vector2 operator-(const Vector2& left, const Vector2& right)
{
	Vector2 returnVector;
	returnVector.x = left.x - right.x;
	returnVector.y = left.y - right.y;

	return returnVector;
}

inline Vector2 operator*(const float& left, const Vector2& right)
{
	Vector2 returnVector;
	returnVector.x = left * right.x;
	returnVector.y = left * right.y;

	return returnVector;
}

inline Vector2 operator*(const Vector2& left, const float& right)
{
	Vector2 returnVector;
	returnVector.x = left.x * right;
	returnVector.y = left.y * right;

	return returnVector;
}

inline Vector2 operator/(const Vector2& left, const float& right)
{
	Vector2 returnVector;
	returnVector.x = left.x / right;
	returnVector.y = left.y / right;

	return returnVector;
}

inline float Length(const Vector2& data)
{
	return sqrt(pow(data.x, 2) + pow(data.y, 2));
}

inline float Length2Vectors(const Vector2 dataOne, const Vector2 dataTwo)
{
	float xTimesx= dataOne.x * dataTwo.x;
	float yTimesy = dataOne.y * dataTwo.y;
	float rad = xTimesx*yTimesy;
	return sqrt(rad);
	
}

inline float LengthSquared(const Vector2& data)
{
	return pow(Length(data),2);
}


inline Vector2 normalized(const Vector2& preNormalizedVector)
{
	float length = Length(preNormalizedVector);

	Vector2 normVector;
	normVector = preNormalizedVector / length;
	return normVector;
}

inline std::ostream& operator<<(std::ostream stream, const Vector2& right)
{
	return std::cout << "{" << right.x << ", " << right.y << "}";
	
	//return stream;
}



inline Vector2 PerpCW(const Vector2& data)
{
Vector2 cwPerpVector;
Vector2 cwNewData;
	if (data.x == 0 && data.y == 0)
	{
		cwNewData = Vector2(.0000001f, .0000001f);
		cwPerpVector = Vector2((cwNewData.y), -cwNewData.x);
	}
	else{
		cwPerpVector = Vector2((data.y), -data.x);
	}
	return cwPerpVector;
}


inline Vector2 PerpCCW(const Vector2& data)
{
Vector2 ccwPerpVector;
Vector2 ccwNewData;
	if (data.x == 0 && data.y == 0)
	{
		ccwNewData = Vector2(.0000001f, .0000001f);
		ccwPerpVector = Vector2(-ccwNewData.y, (ccwNewData.x));

	}
	else{
		ccwPerpVector = Vector2(-data.y, (data.x));
	}
	return ccwPerpVector;

}


inline Vector2 LERP(Vector2 data, Vector2 data2, float beta){
float lerpAVector;
float lerpBVector;
	lerpAVector = ((1-beta)* data.x) + (beta*data2.x);
	lerpBVector = ((1-beta)* data.y) + (beta*data2.y);
	Vector2 myLerpVector(lerpAVector, lerpBVector);
	
	return myLerpVector;
}

inline float Dot(const Vector2& a, const Vector2& b)
{
	return ((a.x)*(b.x)) + ((a.y)*(b.y));
	
};

#endif // !VECTOR2
