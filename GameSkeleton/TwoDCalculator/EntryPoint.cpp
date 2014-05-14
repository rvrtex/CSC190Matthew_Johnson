#include "RenderUI.h"
#include "Engine.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix2.h"
#include "Matrix3.h"


Vector2 basicLeft;
Vector2 basicRight;
Vector2 basicReturnVector;

void myBasicVectorEquationCallback(const BasicVectorEquationInfo& data){
		
	basicLeft = data.scalar1 * Vector2(data.x1, data.y1);
	basicRight = data.scalar2 * Vector2(data.x2, data.y2);	

	if (data.add)
	{
		basicReturnVector = basicLeft + basicRight;
	}
	else
	{
		basicReturnVector = basicLeft - basicRight;
	}

};

Vector2 perpOriginalVector;
Vector2 perpNormalizedVector;
Vector2 cwPerpendicularVector;
Vector2 ccwPerpendicularVector;


void myPerpendicularDataCallback(const PerpendicularData& data)
{	
		perpOriginalVector = Vector2(data.x, data.y);
		perpNormalizedVector = normalized(perpOriginalVector);
		cwPerpendicularVector = PerpCW(perpOriginalVector);
		ccwPerpendicularVector = PerpCCW(perpOriginalVector);

};

Vector2 dotVectorOne;
Vector2 dotVectorTwo;
Vector2 projectionVector;
Vector2 rejectionVector;

void myDotProductDataCallback(const DotProductData& data){

	dotVectorOne = Vector2(data.v1i, data.v1j);
	dotVectorTwo = Vector2(data.v2i, data.v2j);
	if (data.projectOntoLeftVector)
	{
		
		projectionVector = ((Dot(dotVectorOne, dotVectorTwo) / Length(dotVectorOne)))*normalized(dotVectorOne);
		rejectionVector = dotVectorTwo - projectionVector;

	}
	else
	{
		projectionVector = ((Dot(dotVectorTwo, dotVectorOne) / Length(dotVectorTwo)))*normalized(dotVectorTwo);
		rejectionVector = dotVectorOne - projectionVector;

	}

};

Vector2 lerpAVector;
Vector2 lerpBVector;
Vector2 lerpAMinusBVector;
Vector2 aVectorLerpPortion;
Vector2 bVectorLerpPortion;
Vector2 lerpResultVector;

void myLerpDataCallback(const LerpData& data)
{
	lerpAVector = Vector2(data.a_i, data.a_j);
	lerpBVector = Vector2(data.b_i, data.b_j);
	lerpAMinusBVector = lerpBVector - lerpAVector;
	aVectorLerpPortion = (1 - data.beta)*lerpAVector;
	bVectorLerpPortion = data.beta*lerpBVector;
	lerpResultVector = aVectorLerpPortion + bVectorLerpPortion;

}

Vector2 LinearTransResultVector;

void myLinearTransformationCallback(const LinearTransformationData& data)
{
	Vector2 tempVector(data.m00,data.m10);
	Vector2 tempVector2(data.m01, data.m11);
	Vector2 multiplyVector(data.v0,data.v1);

	Matrix2 LinearTransMatrix(tempVector,tempVector2);
	
	LinearTransResultVector = LinearTransMatrix*multiplyVector;


}


Vector3 affineResult[5];
void myAffineTransformationCallback(const AffineTransformationData& data)
{
	Matrix3 mat3;
	mat3.matrix[0] = data.data[0];
	mat3.matrix[1] = data.data[1];
	mat3.matrix[2] = data.data[2];
	mat3.matrix[3] = data.data[3];
	mat3.matrix[4] = data.data[4];
	mat3.matrix[5] = data.data[5];
	mat3.matrix[6] = data.data[6];
	mat3.matrix[7] = data.data[7];
	mat3.matrix[8] = data.data[8];

	
	int count = 8;
	for(int i = 0; i < 5; i++)
	{
		count++;
		affineResult[i].x = data.data[count];
		count++;
		affineResult[i].y = data.data[count];
		count++;
	}

	for(int j = 0; j < 5; j++)
	{
		affineResult[j] = mat3*affineResult[j];
	}

}

const float span = 0.3f;
Vector2 bottomLeft(-span, -span);
Vector2 topLeft(-span, span);
Vector2 topRight(span, span);
Vector2 bottomRight(span, -span);
Vector2 roofTop(0, span + .25f);

Vector2 lines[] = {
bottomLeft, topLeft,
topLeft, topRight,
topRight, bottomRight,
bottomRight, bottomLeft,
topLeft, roofTop,
topRight, roofTop
};
int numLines = sizeof(lines) / (sizeof(*lines) * 2);

Matrix3 listOfMatrix[20];
Matrix3 MatrixTransformReturn;

void myMatrixTransformCallback2D(const MatrixTransformData2D& data)
{
	Matrix3 IDMatrixTransformReturn;
	Matrix3 currentMatrix;

	currentMatrix.ScaleX(data.scaleX);
	currentMatrix.ScaleY(data.scaleY);
	currentMatrix.Rotation(data.rotate);
	currentMatrix.Translation(data.translateX,data.translateY);

	listOfMatrix[data.selectedMatrix] = currentMatrix; 

	for(int i = 0; i < 20; i++)
	{
		IDMatrixTransformReturn = IDMatrixTransformReturn * listOfMatrix[i];
	}

	MatrixTransformReturn = IDMatrixTransformReturn;
}




int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;
	renderUI.setBasicVectorEquationData(myBasicVectorEquationCallback, basicLeft, basicRight, basicReturnVector);
	renderUI.setPerpendicularData(perpOriginalVector, perpNormalizedVector, cwPerpendicularVector, ccwPerpendicularVector, myPerpendicularDataCallback);
	renderUI.setDotProductData(dotVectorOne, dotVectorTwo, projectionVector, rejectionVector, myDotProductDataCallback);
	renderUI.setLerpData(lerpAVector, lerpBVector, lerpAMinusBVector, aVectorLerpPortion, bVectorLerpPortion,lerpResultVector,myLerpDataCallback );
	renderUI.setLinearTransformationData(LinearTransResultVector,myLinearTransformationCallback);
	renderUI.setAffineTransformationData(*affineResult,myAffineTransformationCallback);
	renderUI.set2DMatrixVerticesTransformData(*lines,numLines,*listOfMatrix,MatrixTransformReturn,myMatrixTransformCallback2D);


	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}