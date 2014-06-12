#include "Particle.h"

Vector2 particulate(3.0f,0.0f);

Particle::Particle(Vector2 initialPostion, Vector2 velocity)
{
	position = initialPostion;
	Maxlifetime = MyRandomNumber::RandomInRange(9.0f,25.0f);
	lifetime = 0.0f;
	this->velocity = velocity;
}
Particle::Particle(){};

void Particle::draw(Core::Graphics& g)
{
	
	position = position + velocity;
	g.SetColor(color);
	g.DrawLine(particulate.x+position.x, particulate.y+position.y,(particulate.x+2)+position.x,particulate.y+position.y);
	g.SetColor(RGB(255,255,255));
	
}



