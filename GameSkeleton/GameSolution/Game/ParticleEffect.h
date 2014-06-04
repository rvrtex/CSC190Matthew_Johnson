#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include "Particle.h"
#include "Core.h"
#include "Vector2.h"
#include "MyRandomNumber.h"
#include "VaryColor.h"



class ParticleEffect
{
	Particle *particleArray;
	int numberOfParticlesInEffect;
	MyRandomNumber rn;	
	Vector2 position;
	Vector2 velocity;
	

public:
	bool isFinished;
	int effect;
	void ParticleEffect::CleanUpParticleEffect(void);
	float ParticleEffect::RandomFloat();
	float ParticleEffect::RandomInRange(float min, float max);
	ParticleEffect(void);
	ParticleEffect(int numberOfParticles,int effect, Vector2 position, Vector2 velocity);
	void ParticleEffect::TunnelEffect();
	void draw(Core::Graphics&);
	void update(float);
	void BounceEffect();
	
};


#endif // !PARTICLEEFFECT_H

