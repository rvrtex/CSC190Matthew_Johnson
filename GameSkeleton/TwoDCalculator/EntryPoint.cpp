#include "RenderUI.h"
#include "Engine.h"
#include "Vector2.h"


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







int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;
	renderUI.setBasicVectorEquationData(myBasicVectorEquationCallback, basicLeft, basicRight, basicReturnVector);
	renderUI.setPerpendicularData(perpOriginalVector, perpNormalizedVector, cwPerpendicularVector, ccwPerpendicularVector, myPerpendicularDataCallback);
	renderUI.setDotProductData(dotVectorOne, dotVectorTwo, projectionVector, rejectionVector, myDotProductDataCallback);
	renderUI.setLerpData(lerpAVector, lerpBVector, lerpAMinusBVector, aVectorLerpPortion, bVectorLerpPortion,lerpResultVector,myLerpDataCallback );

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}