#include "ParticleEffect.h"



ParticleEffect::ParticleEffect(void)
{}



ParticleEffect::ParticleEffect(int numberOfParticles, int effect, Vector2 position, Vector2 velocity, float dt)
{
	myDT = dt;
	numberOfParticlesInEffect = numberOfParticles;
	particleArray = new Particle[numberOfParticlesInEffect];
	this->position = position;
	this->velocity = velocity;
	this->effect = effect;
	isFinished = false;
}



void ParticleEffect::draw(Core::Graphics& g)
{
	int numOfDead = 0;
	for(int i = 0; i < numberOfParticlesInEffect; i++)
	{
		if(!particleArray[i].isAlive)
		{
			numOfDead++;
		}
		if(numberOfParticlesInEffect == numOfDead)
		{
			isFinished = true;
		//	delete [] particleArray;
		}

		if(effect == 1)
		{
			if(particleArray[i].lifetime < particleArray[i].Maxlifetime)
			{
			
				particleArray[i].lifetime = particleArray[i].lifetime + myDT*.5f;
			}
			else
			{
				particleArray[i].isAlive = false;
			}
		}
		else if(effect == 2)
		{
			float angle;
			Matrix3 tempMatrix;
			Vector2 tempVelocity;
			angle = MyRandomNumber::RandomInRange(1.0f,100.0f)*((2.0f*3.14f)/100.0f);
			tempMatrix.Rotation(angle);
			float speedDiff = MyRandomNumber::RandomInRange(-5.0f,5.0f);
			tempVelocity = tempMatrix*(velocity+speedDiff);
		 
			if(particleArray[i].position.x > 1024 || particleArray[i].position.x < 0)
			{
				particleArray[i].position = this->position;
				particleArray[i].velocity = tempVelocity;
				particleArray[i].color = Util::Colors::VeryColor(RGB(100,100,255),10.05f);

			}
			else if(particleArray[i].position.y > 728 || particleArray[i].position.y < 0)
			{
				particleArray[i].position = this->position;
				particleArray[i].velocity = tempVelocity;
				particleArray[i].color = Util::Colors::VeryColor(RGB(100,100,255),255.0f);

			}
		}
		particleArray[i].draw(g);
	}
}

//void ParticleEffect::CleanUpParticleEffect(void)
//{
//	delete [] particleArray;
//}




void ParticleEffect::BounceEffect()
{

	float angle;
	Matrix3 tempMatrix;
	Vector2 tempVelocity;
	isFinished = false;
	for(int i = 0; i < numberOfParticlesInEffect; i++)
	{
		angle = MyRandomNumber::RandomInRange(.01f,1.0f)*((2.0f*3.14f)/100.0f);
		tempMatrix.Rotation(angle);
		float speedDiff = MyRandomNumber::RandomInRange(-10.0f,10.0f);
		tempVelocity = tempMatrix*(velocity+speedDiff);
		Particle p;
		p.position = this->position;
		p.velocity = tempVelocity;
		p.color = Util::Colors::VeryColor(RGB(255,0,0),100.0f);
		particleArray[i] = p;	
	}


}


void ParticleEffect::TunnelEffect()
{

	float angle;
	Matrix3 tempMatrix;
	Vector2 tempVelocity;
	for(int i = 0; i < numberOfParticlesInEffect; i++)
	{
		Particle p;

		angle = MyRandomNumber::RandomInRange(.01f,1.0f)*((2.0f*3.14f)/100.0f);
		tempMatrix.Rotation(angle);
		velocity.x = MyRandomNumber::RandomInRange(-5.0f,5.0f);
		velocity.y = MyRandomNumber::RandomInRange(-5.0f,5.0f);
		tempVelocity = tempMatrix*(velocity);
		p.position = this->position;
		p.velocity = tempVelocity;
		p.color = Util::Colors::VeryColor(RGB(100,100,255),255.0f);

		particleArray[i] = p;	
	}
}
