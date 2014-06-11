#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include "Particle.h"
#include "Core.h"
#include "Vector2.h"
#include "MyRandomNumber.h"
#include "VaryColor.h"
#include "DebugMemory.h"




class ParticleEffect
{
	Particle *particleArray;
	int numberOfParticlesInEffect;
	MyRandomNumber rn;	
	Vector2 position;
	Vector2 velocity;
	float myDT;
	

public:
	bool isFinished;
	int effect;
	void ParticleEffect::CleanUpParticleEffect(void);
	ParticleEffect::ParticleEffect(void);
	ParticleEffect::ParticleEffect(int numberOfParticles,int effect, Vector2 position, Vector2 velocity,float);
	void ParticleEffect::TunnelEffect();
	void ParticleEffect::draw(Core::Graphics&);
	void ParticleEffect::update(float);
	void ParticleEffect::BounceEffect();
	
};


#endif // !PARTICLEEFFECT_H

