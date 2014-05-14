#ifndef MATRIX2_H
#define MATRIX2_H
#include "Vector2.h"
#include <cmath>


class Matrix2
{
	
public:
	
float matrix[4];

	Matrix2::Matrix2()
{
	matrix[0] = 1.0f;
	matrix[1] = 0.0f;
	matrix[2] = 0.0f;
	matrix[3] = 1.0f;
	
};
	Matrix2(Vector2 firstVector, Vector2 secondVector){
		matrix[0] = firstVector.x;
		matrix[1] = secondVector.x;
		matrix[2] = firstVector.y;
		matrix[3] = secondVector.y;
	};

inline Matrix2 Scale(float scaler)
{
	matrix[0] = matrix[0]*scaler;
	matrix[3] = matrix[3]*scaler;
};

inline Matrix2 ScaleX(float scaler)
{
	matrix[0] = matrix[0]*scaler;

};

inline Matrix2 ScaleY(float scaler)
{
	matrix[3] = matrix[3]*scaler;
};
};


inline Vector2 operator*(const Matrix2 matrix, const Vector2 vector)
{
	Vector2 tempVector;
	tempVector.x = (matrix.matrix[0] * vector.x) + (matrix.matrix[1] * vector.y);
	tempVector.y = (matrix.matrix[2] * vector.x) + (matrix.matrix[3] * vector.y);
	
	return tempVector;
};

inline Matrix2 operator*(const Matrix2 firstMatrix, const Matrix2 secondMatrix)
{
	

	Matrix2 tempMatrix;
	tempMatrix.matrix[0] = (firstMatrix.matrix[0]*secondMatrix.matrix[0]) +(firstMatrix.matrix[1]*secondMatrix.matrix[2]);
	tempMatrix.matrix[1] = (firstMatrix.matrix[0]*secondMatrix.matrix[1]) +(firstMatrix.matrix[1]*secondMatrix.matrix[3]);
	tempMatrix.matrix[2] = (firstMatrix.matrix[2]*secondMatrix.matrix[0]) +(firstMatrix.matrix[3]*secondMatrix.matrix[2]);
	tempMatrix.matrix[3] = (firstMatrix.matrix[2]*secondMatrix.matrix[1]) +(firstMatrix.matrix[3]*secondMatrix.matrix[3]);

	return tempMatrix;	
};

inline Matrix2 Rotation(float angle)
{
	Vector2 tempVectorOne(cos(angle),sin(angle));
	Vector2 tempVectorTwo(-sin(angle),cos(angle));

	Matrix2 returnMatrix(tempVectorOne,tempVectorTwo);
	return returnMatrix;
};


#endif // !MATRIX2_H
