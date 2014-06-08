#include "Turret.h"

//ProjectileManager turretPM;

//Turret::Turret(ProjectileManager& pm)
//{
//	turretPM = pm;
//}

Turret::Turret(){};


Vector2 turretPoints[] = 
{
	Vector2(+6.0f,6.0f),
	Vector2(-6.0f,6.0f),
	Vector2(-3.0f,-9.0f),
	Vector2(3.0f,-9.0f)
};
Vector2 myPosition;	

Vector2 rotatedTurretPoint[] =
{
	Vector2(+6.0f,6.0f),
	Vector2(-6.0f,6.0f),
	Vector2(-3.0f,-9.0f),
	Vector2(3.0f,-9.0f)
};
const float SCREEN_WIDTH = 1024;
const float SCREEN_HEIGHT = 728;


	Matrix3 transform;

void Turret::draw(Core::Graphics& g, Vector2 position)
{
	myPosition = position;
	transform.Translation(myPosition);

	const unsigned int NUM_LINES = sizeof(turretPoints)/sizeof(*turretPoints);
	for(unsigned int i = 0; i < NUM_LINES; i++)
	{
		
		const Vector2& first = transform*rotatedTurretPoint[i];
		const Vector2& second = transform*rotatedTurretPoint[(i+1)% NUM_LINES];
		g.DrawLine(first.x,first.y,second.x,second.y);
		;}
	
}
Vector2 mousePosition;


void Turret::FireButtonPressed(float dt)
{

	Missile* m = new Missile(dt);
	m->destructPoint = mousePosition;
	m->startingPoint = myPosition;
	m->myCurrentPosition = myPosition;
	CollisionManager::MissileFired(*m);
}

void Turret::update()
{	
int mouseX, mouseY;
	
	Core::Input::GetMousePos(mouseX,mouseY);
	mousePosition.x = (float)mouseX;
	mousePosition.y = (float)mouseY;
	Vector2 vectorOfShipToMouse = myPosition - mousePosition;
	Vector2 normolizedVectore = normalized(vectorOfShipToMouse);
	Vector2 perpVector = PerpCW(normolizedVectore);

	Matrix3 rotationMatrix(perpVector,normolizedVectore);
	

	for(int i = 0; i < 4; i++)
	{
		rotatedTurretPoint[i] = rotationMatrix*turretPoints[i];
	}

}