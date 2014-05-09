#include "SpaceShip.h"


const float SCREEN_WIDTH = 1024;
const float SCREEN_HEIGHT = 728;

Vector2 wallPieceOne(SCREEN_WIDTH/2,0.0f);
Vector2 wallPieceTwo(SCREEN_WIDTH,SCREEN_HEIGHT/2);
Vector2 wallPieceThree(SCREEN_WIDTH/2,SCREEN_HEIGHT);
Vector2 wallPieceFour(0.0f,SCREEN_HEIGHT/2);

Vector2 spaceShipPoints[] = 
{
	Vector2(+0.0f,8.0f),
	Vector2(-12.0f,0.0f),
	Vector2(+0.0f,-20.0f),
	Vector2(+12.0f,0.0f)
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
			;}
	}


}


void SpaceShip::update(float dt)
{
	bool outSideLine = false;

	float quadOneDotProd = 0;
	float quadTwoDotProd = 0;
	float quadThreeDotProd = 0;
	float quadFourDotProd = 0;

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
	//set initial position
	if(wallMode)
	{
		quadOneShipResultVector = position - wallPieceOne;
		quadOneWallTwoVector = wallPieceTwo - wallPieceOne;
		quadOneWallNorm = PerpCCW(quadOneWallTwoVector);
		quadOneNormalized =	normalized(quadOneWallNorm);

		quadOneDotProd = Dot(quadOneWallNorm,quadOneShipResultVector);
		if(quadOneDotProd < -8000 ) 
		{
			if(!outSideLine)
			outSideLine = true;			
		}		

		quadTwoShipResultVector = position - wallPieceTwo;
		quadTwoWallTwoVector = wallPieceThree - wallPieceTwo;
		quadTwoWallNorm = PerpCCW(quadTwoWallTwoVector);
		quadTwoNormalized =	normalized(quadTwoWallNorm);

		quadTwoDotProd = Dot(quadTwoWallNorm,quadTwoShipResultVector);

		if(quadTwoDotProd < -8000 ) 
		{
			if(!outSideLine)
			outSideLine = true;
		}	

		quadThreeShipResultVector = position - wallPieceThree;
		quadThreeWallTwoVector = wallPieceFour - wallPieceThree;
		quadThreeWallNorm = PerpCCW(quadThreeWallTwoVector);
		quadThreeNormalized = normalized(quadThreeWallNorm);

		quadThreeDotProd = Dot(quadThreeWallNorm,quadThreeShipResultVector);

		if(quadThreeDotProd < -8000 ) 
		{
			if(!outSideLine)
			outSideLine = true;
		}	

		quadFourShipResultVector = position - wallPieceFour;
		quadFourWallTwoVector =	 wallPieceOne - wallPieceFour;
		quadFourWallNorm = PerpCCW(quadFourWallTwoVector);	
		quadFourNormalized = normalized(quadFourWallNorm);

		quadFourDotProd = Dot(quadFourWallNorm,quadFourShipResultVector);
		
		if(quadFourDotProd < -8000 ) 
		{
			if(!outSideLine)
			outSideLine = true;
		}
	}
	dt = dt*4;

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
		wallMode = true;
	}

	//stear ship
	int timeDT =100;
	if(Core::Input::IsPressed(Core::Input::KEY_RIGHT))
	{

		if(velocity.x < 20)
		{
			velocity.x += dt*timeDT;
		}
	}
	if(Core::Input::IsPressed(Core::Input::KEY_LEFT))
	{
		if(velocity.x > -20)
		{
			velocity.x -= dt*timeDT;
		}
	}
	if(Core::Input::IsPressed(Core::Input::KEY_UP))
	{
		if(velocity.y > -20)
		{
			velocity.y -= dt*timeDT;
		}
	}
	if(Core::Input::IsPressed(Core::Input::KEY_DOWN))
	{

		if(velocity.y < 20)
		{
			velocity.y += dt*timeDT;
		}
	}

	//do the bounce
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

	if(wallMode && !outSideLine)
	{
		if(quadOneDotProd < 0 )
		{
			velocity = velocity - (2*(Dot(velocity,quadOneNormalized)*quadOneNormalized));

		}
		else if(quadTwoDotProd < 0)
		{
			velocity = velocity - (2*(Dot(velocity,quadTwoNormalized)*quadTwoNormalized));

		}
		else if( quadThreeDotProd < 0)
		{
			velocity = velocity - (2*(Dot(velocity,quadThreeNormalized)*quadThreeNormalized));

		}
		else if(quadFourDotProd < 0)
		{
			velocity = velocity - (2*(Dot(velocity,quadFourNormalized)*quadFourNormalized));

		}
	}

	position.x = position.x + velocity.x * dt;
	position.y = position.y + velocity.y * dt;

}

