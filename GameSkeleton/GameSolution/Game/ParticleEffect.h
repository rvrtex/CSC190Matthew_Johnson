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

	float myDT;
	Particle particles[500];
	
	int numberOfParticlesInEffect;
public:
	
	//void ParticleEffect::ClearArray();
	
	MyRandomNumber rn;	
	Vector2 position;
	Vector2 velocity;
	bool isFinished;
	int effect;
	//void ParticleEffect::CleanUpParticleEffect(void);
	ParticleEffect::ParticleEffect(void);
	ParticleEffect::ParticleEffect(float dt,int effectNum);
	void ParticleEffect::TunnelEffect();
	void ParticleEffect::draw(Core::Graphics&);
	void ParticleEffect::update(float);
	void ParticleEffect::BounceEffect();
	
};


#endif // !PARTICLEEFFECT_H

