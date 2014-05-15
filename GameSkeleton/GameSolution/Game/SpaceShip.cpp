#include "SpaceShip.h"
#include "DrawValues.h"


const float SCREEN_WIDTH = 1024;
const float SCREEN_HEIGHT = 728;

Vector2 wallPieceOne(SCREEN_WIDTH/2,0.0f);
Vector2 wallPieceTwo(SCREEN_WIDTH,SCREEN_HEIGHT/2);
Vector2 wallPieceThree(SCREEN_WIDTH/2,SCREEN_HEIGHT);
Vector2 wallPieceFour(0.0f,SCREEN_HEIGHT/2);

Vector2 spaceShipPoints[] = 
{
	Vector2(+0.0f,14.0f),
	Vector2(-18.0f,0.0f),
	Vector2(+0.0f,-28.0f),
	Vector2(+18.0f,0.0f)
};

Vector2 wallPoints[] =
{
	wallPieceOne,
	wallPieceTwo,
	wallPieceThree,
	wallPieceFour
};

unsigned int currentMode;
bool wallMode;

void SpaceShip::draw(Core::Graphics& g)
{
	const unsigned int NUM_LINES = sizeof(spaceShipPoints)/sizeof(*spaceShipPoints);
	for(unsigned int i = 0; i < NUM_LINES; i++)
	{
		const Vector2& first = position+spaceShipPoints[i];
		const Vector2& second = position+spaceShipPoints[(i+1)% NUM_LINES];
		g.DrawLine(first.x,first.y,second.x,second.y);
		;}
	if(wallMode)
	{
		for(unsigned int i = 0; i < 4; i++)
		{
			const Vector2& first = wallPoints[i];
			const Vector2& second = wallPoints[(i+1)% NUM_LINES];
			g.DrawLine(first.x,first.y,second.x,second.y);			
		}
	}
}

Vector2 quadOneShipResultVector; 
Vector2 quadOneWallTwoVector; 
Vector2 quadOneWallNorm; 		
Vector2 quadOneNormalized; 		

Vector2 quadTwoShipResultVector; 
Vector2 quadTwoWallTwoVector; 
Vector2 quadTwoWallNorm; 		
Vector2 quadTwoNormalized;		

Vector2 quadThreeShipResultVector;
Vector2 quadThreeWallTwoVector;
Vector2 quadThreeWallNorm;
Vector2 quadThreeNormalized;

Vector2 quadFourShipResultVector;
Vector2 quadFourWallTwoVector;	
Vector2 quadFourWallNorm;		
Vector2 quadFourNormalized;	



void initializeVectors()
{
	quadOneWallTwoVector = wallPieceTwo - wallPieceOne;
	quadOneWallNorm = PerpCCW(quadOneWallTwoVector);
	quadOneNormalized =	normalized(quadOneWallNorm);

	quadTwoWallTwoVector = wallPieceThree - wallPieceTwo;
	quadTwoWallNorm = PerpCCW(quadTwoWallTwoVector);
	quadTwoNormalized =	normalized(quadTwoWallNorm);

	quadThreeWallTwoVector = wallPieceFour - wallPieceThree;
	quadThreeWallNorm = PerpCCW(quadThreeWallTwoVector);
	quadThreeNormalized = normalized(quadThreeWallNorm);

	quadFourWallTwoVector =	 wallPieceOne - wallPieceFour;
	quadFourWallNorm = PerpCCW(quadFourWallTwoVector);	
	quadFourNormalized = normalized(quadFourWallNorm);
}


Vector2 initialPosition;
Vector2 bounceSooner;
int ousideLineNum = 0;
void SpaceShip::update(float dt)
{

float quadOneDotProd = 0;
float quadTwoDotProd = 0;
float quadThreeDotProd = 0;
float quadFourDotProd = 0;

float quadLastOneDotProd = 0;
float quadLastTwoDotProd = 0;
float quadLastThreeDotProd = 0;
float quadLastFourDotProd = 0;
//set initial position

	outSideLine = false;

	if(wallMode)
	{
		bounceSooner = Vector2(18.0f,-28.0f);
		quadOneShipResultVector = (position+bounceSooner) - wallPieceOne;
		quadOneDotProd = Dot(quadOneWallNorm,quadOneShipResultVector);	
		quadOneShipResultVector = (initialPosition+bounceSooner) - wallPieceOne;
		quadLastOneDotProd = Dot(quadOneWallNorm,quadOneShipResultVector);	

		bounceSooner = Vector2(18.0f,14.0f);		
		quadTwoShipResultVector = (position+bounceSooner) - wallPieceTwo;
		quadTwoDotProd = Dot(quadTwoWallNorm,quadTwoShipResultVector);
		quadTwoShipResultVector = (initialPosition+bounceSooner) - wallPieceTwo;
		quadLastTwoDotProd = Dot(quadTwoWallNorm,quadTwoShipResultVector);	

		bounceSooner = Vector2(-18.0f,14.0f);		
		quadThreeShipResultVector = (position+bounceSooner) - wallPieceThree;
		quadThreeDotProd = Dot(quadThreeWallNorm,quadThreeShipResultVector);
		quadThreeShipResultVector = (initialPosition+bounceSooner) - wallPieceThree;
		quadLastThreeDotProd = Dot(quadThreeWallNorm,quadThreeShipResultVector);	

		bounceSooner = Vector2(-18.0f,-28.0f);		
		quadFourShipResultVector = (position+bounceSooner) - wallPieceFour;
		quadFourDotProd = Dot(quadFourWallNorm,quadFourShipResultVector);
		quadFourShipResultVector = (initialPosition+bounceSooner) - wallPieceFour;
		quadLastFourDotProd = Dot(quadFourWallNorm,quadFourShipResultVector);	

	}
	dt = dt*2;

	//Pick mode
	if(Core::Input::IsPressed('1'))
	{
		currentMode = 1;
		wallMode = false;
	}
	if(Core::Input::IsPressed('2'))
	{
		currentMode = 2;
		wallMode = false;
	}
	if(Core::Input::IsPressed('3'))
	{
		initializeVectors();
		wallMode = true;
	}
	if(Core::Input::IsPressed('H'))
	{
		velocity.x = velocity.y = 0;

	}

	//stear ship
	unsigned int quickTurnAround = 10;
	int maxSpeed = 100;
	if(Core::Input::IsPressed(Core::Input::KEY_RIGHT))
	{

		if(velocity.x < maxSpeed)
		{
			velocity.x += dt*quickTurnAround;
		}
	}
	if(Core::Input::IsPressed(Core::Input::KEY_LEFT))
	{
		if(velocity.x > -maxSpeed)
		{
			velocity.x -= dt*quickTurnAround;
		}
	}
	if(Core::Input::IsPressed(Core::Input::KEY_UP))
	{
		if(velocity.y > -maxSpeed)
		{
			velocity.y -= dt*quickTurnAround;
		}
	}
	if(Core::Input::IsPressed(Core::Input::KEY_DOWN))
	{

		if(velocity.y < maxSpeed)
		{
			velocity.y += dt*quickTurnAround;
		}
	}

	//do the bounce of outside walls
	if(currentMode == 1)
	{
		if(position.x < 0)
		{
			velocity.x *= -1;
		}
		if(position.x > 1020)
		{
			velocity.x *= -1;
		}
		if(position.y < 4)
		{
			velocity.y *= -1;
		}
		if(position.y > 720)
		{
			velocity.y *= -1;
		}
	}
	//wrap the ship
	else if (currentMode == 2)
	{
		if(position.x < -8)
		{
			position.x = 1020;
		}
		if(position.x > 1028)
		{
			position.x = 0;
		}
		if(position.y < -8)
		{
			position.y = 720;
		}
		if(position.y > 728)
		{
			position.y = 0;
		}
	}

	//wall are on
	if(wallMode)
	{
		

		if(quadOneDotProd < 0 && quadLastOneDotProd > 0 )
		{
			position = initialPosition;
			velocity = velocity - (2*(Dot(velocity,quadOneNormalized)*quadOneNormalized));

		}
		else if(quadTwoDotProd < 0 && quadLastTwoDotProd > 0)
		{
			position = initialPosition;
			velocity = velocity - (2*(Dot(velocity,quadTwoNormalized)*quadTwoNormalized));

		}
		else if( quadThreeDotProd < 0 && quadLastThreeDotProd > 0)
		{
			position = initialPosition;
			velocity = velocity - (2*(Dot(velocity,quadThreeNormalized)*quadThreeNormalized));

		}
		else if(quadFourDotProd < 0 && quadLastFourDotProd > 0)
		{
			position = initialPosition;
			velocity = velocity - (2*(Dot(velocity,quadFourNormalized)*quadFourNormalized));

		}

	}

	initialPosition = position;	

	position.x = position.x + velocity.x * dt*quickTurnAround;
	position.y = position.y + velocity.y * dt*quickTurnAround;

}

