#ifndef MATRIX3_H
#define MATRIX3_H
#include "Vector2.h"
#include "Vector3.h"
#include <cmath>

class Matrix3
{

public:

	float matrix[9];


	Matrix3()
	{
		matrix[0] = 1.0f;
		matrix[1] = 0.0f;
		matrix[2] = 0.0f;
		matrix[3] = 0.0f;
		matrix[4] = 1.0f;
		matrix[5] = 0.0f;
		matrix[6] = 0.0f;
		matrix[7] = 0.0f;
		matrix[8] = 1.0f;
	};

	Matrix3(Vector2 firstVector, Vector2 secondVector){
		matrix[0] = firstVector.x;
		matrix[1] = secondVector.x;
		matrix[2] = 0;
		matrix[3] = firstVector.y;
		matrix[4] = secondVector.y;
		matrix[5] = 0;
		matrix[6] = 0;
		matrix[7] = 0;
		matrix[8] = 1;


	};
	operator float*(){ return &matrix[0]; }	


	inline void Scale(float scaler)
	{
		matrix[0] = matrix[0]*scaler;
		matrix[4] = matrix[4]*scaler;
	};

	inline void ScaleX(float scaler)
	{
		 matrix[0] = matrix[0]*scaler;

	};

	inline void ScaleY(float scaler)
	{
		matrix[4] = matrix[4]*scaler;
	};

	inline void Translation(float x, float y)
	{
		matrix[2] =  x;
		matrix[5] = y;		
	}

	inline void Translation(Vector2& t)
	{
		matrix[2] = t.x;
		matrix[5] = t.y;	
	}

	inline void Rotation(float angle);

};
inline Matrix3 operator*(const Matrix3 firstMatrix, const Matrix3 secondMatrix);

	inline void Matrix3::Rotation(float angle)
{
	Vector2 tempVectorOne(cos(angle),sin(angle));
	Vector2 tempVectorTwo(-sin(angle),cos(angle));

	
	Matrix3 returnMatrix(tempVectorOne,tempVectorTwo);
	*this = *this*returnMatrix;
	//return returnMatrix;
}
inline Vector2 operator*(const Matrix3 matrix, const Vector2 vector)
{
	Vector2 tempVector;
	tempVector.x = (matrix.matrix[0] * vector.x) + (matrix.matrix[1] * vector.y)+ (matrix.matrix[2]);
	tempVector.y = (matrix.matrix[3] * vector.x) + (matrix.matrix[4] * vector.y) + (matrix.matrix[5]);
	
	return tempVector;
};

inline Vector3 operator*(const Matrix3 matrix, const Vector3 vector)
{
	Vector3 tempVector;
	tempVector.x = (matrix.matrix[0] * vector.x) + (matrix.matrix[1] * vector.y)+ (matrix.matrix[2]);
	tempVector.y = (matrix.matrix[3] * vector.x) + (matrix.matrix[4] * vector.y) + (matrix.matrix[5]);
	tempVector.z = 1;
	
	return tempVector;
};

inline Matrix3 operator*(const Matrix3 firstMatrix, const Matrix3 secondMatrix)
{
	

	Matrix3 tempMatrix;
	tempMatrix.matrix[0] = (firstMatrix.matrix[0]*secondMatrix.matrix[0]) +(firstMatrix.matrix[1]*secondMatrix.matrix[3]);
	tempMatrix.matrix[1] = (firstMatrix.matrix[0]*secondMatrix.matrix[1]) +(firstMatrix.matrix[1]*secondMatrix.matrix[4]);
	tempMatrix.matrix[2] = (firstMatrix.matrix[0]*secondMatrix.matrix[2]) +(firstMatrix.matrix[1]*secondMatrix.matrix[5])+ (firstMatrix.matrix[2]);
	tempMatrix.matrix[3] = (firstMatrix.matrix[3]*secondMatrix.matrix[0]) +(firstMatrix.matrix[4]*secondMatrix.matrix[3]);
	tempMatrix.matrix[4] = (firstMatrix.matrix[3]*secondMatrix.matrix[1]) +(firstMatrix.matrix[4]*secondMatrix.matrix[4]);
	tempMatrix.matrix[5] = (firstMatrix.matrix[3]*secondMatrix.matrix[2]) +(firstMatrix.matrix[4]*secondMatrix.matrix[5])+ (firstMatrix.matrix[5]);
	tempMatrix.matrix[6] = 0;
	tempMatrix.matrix[7] = 0;
	tempMatrix.matrix[8] = 1;
	

	return tempMatrix;	
};

#endif