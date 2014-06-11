#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector2.h"
#include "Core.h"
#include "Matrix3.h"
#include "MyRandomNumber.h"

class Particle
{
public:
	Vector2 particle;
	Vector2 position;
	Vector2 velocity;
	Core::RGB color;
	bool isAlive;
	float lifetime;
	float Maxlifetime;


	void draw(Core::Graphics&);
	void update(float dt);

	Particle(void);
	Particle(Vector2, Vector2);
	//~Particle(void);
};

#endif