#include "SpaceShip.h"
#include "DrawValues.h"
#include "ParticleEffect.h"
#include "Profiler.h"
#include "Timer.h"

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

Vector2 rotatedSpaceShipPoint[] = 
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

unsigned int currentMode = 1;
ProjectileManager myPm;
bool wallMode;
float angle = 0;
float myDt;
Turret myTurret;
float reload;
DrawValues dv;
GameSolution* myGm;

SpaceShip::SpaceShip(void){}

SpaceShip::SpaceShip(ProjectileManager& pm, GameSolution& gm, Timer* timer)
{
	timer;
	//Profiler::getInstance().addEntry("SpaceShip",timer->Interval());
	myPm =pm;
	myGm = &gm;

	myTurret = Turret(myPm);
}


void SpaceShip::ModeKeyPressed(Vector2& velocity)
{

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
		/*initializeVectors();*/
		wallMode = true;
	}
	if(Core::Input::IsPressed('H'))
	{
		velocity.x = velocity.y = 0;
	}
	if(Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{		
		if(reload > 1)
		{
			myTurret.FireButtonPressed(myDt);
			reload = 0.0f;
		}

	}
	reload += myDt*2;
}
bool impact = false;

void SpaceShip::draw(Core::Graphics& g)
{
	const unsigned int NUM_LINES = sizeof(rotatedSpaceShipPoint)/sizeof(*rotatedSpaceShipPoint);
	//matrix transform
	Matrix3 transform;
	Matrix3 finalMatrix;

	myTurret.draw(g,position);

	for(unsigned int i = 0; i < NUM_LINES; i++)
	{
		transform.Translation(position);
		const Vector2 first = transform* rotatedSpaceShipPoint[i];
		const Vector2 second = transform * rotatedSpaceShipPoint[(i+1)% NUM_LINES];
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
	finalMatrix =transform*rotatedMatirx;
	dv.DrawValue(g,200,200,finalMatrix);

}

Vector2 quadShipResultVector; 
Vector2 quadWallTwoVector; 
Vector2 quadWallNorm; 		
Vector2 quadNormalized; 		

Vector2 initialPosition;
Vector2 bounceSooner;
int ousideLineNum = 0;

void SpaceShip::update(float dt)
{
//	Profiler::getInstance().newFrame();
	myDt = dt;
	float quadDotProd = 0;
	float quadLastDotProd = 0;
	outSideLine = false;

	if(wallMode)
	{
		for(int i = 4; i > -1; i--)
		{
			if(i == 0)
			{
				quadWallTwoVector = wallPoints[0]- wallPoints[3];

			}
			else
			{
				quadWallTwoVector = wallPoints[i]- wallPoints[i-1];
			}

			quadWallNorm = PerpCCW(quadWallTwoVector);
			quadNormalized = normalized(quadWallNorm);
			quadShipResultVector = (position) - wallPoints[i];
			quadDotProd = Dot(quadWallNorm,quadShipResultVector);	
			quadShipResultVector = (initialPosition) - wallPoints[i];
			quadLastDotProd = Dot(quadWallNorm,quadShipResultVector);	

			if(quadDotProd < 0 && quadLastDotProd > 0 )
			{
				ParticleEffect* part = new ParticleEffect(5000,1,position,velocity);
				part->BounceEffect();
				myGm ->AddToList(*part);
				position = initialPosition;
				velocity = velocity - (2*(Dot(velocity,quadNormalized)*quadNormalized));
			}
		}

	}
	dt = dt*2;
	//pick mode
	ModeKeyPressed(velocity);


	//stear ship
	unsigned int quickTurnAround = 10;
	//	int maxSpeed = 100;
	Matrix3 tempMatrix;
	Vector2 tempVector;
	rotatedMatirx = tempMatrix;
	if(Core::Input::IsPressed(Core::Input::KEY_LEFT))
	{
		angle = angle + ((-1 * (2.0f*3.14f)) /100.0f);
		tempMatrix.Rotation(angle);
		for(int i = 0; i < 4; i++)
		{
			rotatedSpaceShipPoint[i] = tempMatrix*spaceShipPoints[i];
		}


	}
	if(Core::Input::IsPressed(Core::Input::KEY_RIGHT))
	{
		angle = angle + ((1 * (2.0f*3.14f)) /100.0f);

		tempMatrix.Rotation(angle);

		for(int i = 0; i < 4; i++)
		{
			rotatedSpaceShipPoint[i] = tempMatrix*spaceShipPoints[i];
		}			

	}

	if(Core::Input::IsPressed(Core::Input::KEY_UP))
	{
		Vector2 acceleration(0.f,-dt*quickTurnAround);			
		tempMatrix.Rotation(angle);

		acceleration = tempMatrix*acceleration;
		velocity = velocity+acceleration;

	}
	if(Core::Input::IsPressed(Core::Input::KEY_DOWN))
	{
		Vector2 acceleration(0.f,dt*quickTurnAround);				
		tempMatrix.Rotation(angle);

		acceleration = tempMatrix*acceleration;
		velocity = velocity+acceleration;	
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

	rotatedMatirx.Rotation(angle);


	initialPosition = position;	

	position.x = position.x + velocity.x * dt*quickTurnAround;
	position.y = position.y + velocity.y * dt*quickTurnAround;
	myTurret.update();


}