#include "ParticleEffect.h"
#include <vector>



ParticleEffect::ParticleEffect(void)
{}



ParticleEffect::ParticleEffect(float dt,int thisEffect)
{
	myDT = dt;
	effect = thisEffect;
	numberOfParticlesInEffect = 500;
	for(int i = 0; i < 500; i++)
	{
		Particle p;
		
		p.isAlive =true;
		particles[i] = p;
	}

}
/*
numberOfParticlesInEffect = numberOfParticles;
particleArray = new Particle[numberOfParticlesInEffect];
this->position = position;
this->velocity = velocity;
this->effect = effect;
isFinished = false;*/

void ParticleEffect::draw(Core::Graphics& g)
{

	int numOfDead = 0;

	for(int i = 0; i < numberOfParticlesInEffect; i++)
	{
		if(!particles[i].isAlive )
			{
				numOfDead++;
			}
			if(numberOfParticlesInEffect == numOfDead)
			{
				isFinished = true;
			}

		if(effect == 1)
		{
			
			if(particles[i].lifetime < particles[i].Maxlifetime)
			{

				particles[i].lifetime = particles[i].lifetime + myDT*.5f;
			}
			else
			{
				if(i ==498)
				{
					int j;
					j=5;
				}
				particles[i].isAlive = false;
			}
		}
		else if(effect == 2)
		{
			float angle;
				isFinished = false;


			Matrix3 tempMatrix;
			Vector2 tempVelocity;
			angle = MyRandomNumber::RandomInRange(1.0f,100.0f)*((2.0f*3.14f)/100.0f);
			tempMatrix.Rotation(angle);
			float speedDiff = MyRandomNumber::RandomInRange(-5.0f,5.0f);
			tempVelocity = tempMatrix*(velocity+speedDiff);

			if(particles[i].position.x > 1024 || particles[i].position.x < 0)
			{
				particles[i].position = Vector2(500,300);
				particles[i].velocity = tempVelocity;
				particles[i].color = Util::Colors::VeryColor(RGB(100,100,255),10.05f);

			}
			else if(particles[i].position.y > 728 || particles[i].position.y < 0)
			{
				particles[i].position = Vector2(500,300);
				particles[i].velocity = tempVelocity;
				particles[i].color = Util::Colors::VeryColor(RGB(100,100,255),255.0f);

			}
		}
		particles[i].draw(g);
	}
}



//void ParticleEffect::CleanUpParticleEffect(void)
//{
//	delete [] particleArray;
//}




void ParticleEffect::BounceEffect()
{

	float angle;
	effect=1;
	Matrix3 tempMatrix;
	Vector2 tempVelocity;
	isFinished = false;
	for(int i = 0; i < 500; i++)
	{
		angle = MyRandomNumber::RandomInRange(.01f,1.0f)*((2.0f*3.14f)/100.0f);
		tempMatrix.Rotation(angle);
		float speedDiff = MyRandomNumber::RandomInRange(-10.0f,10.0f);
		tempVelocity = tempMatrix*(velocity+speedDiff);
		particles[i].isAlive = true;
		particles[i].position = this->position;
		particles[i].velocity = tempVelocity;
		particles[i].color = Util::Colors::VeryColor(RGB(255,0,0),100.0f);

	}


}


void ParticleEffect::TunnelEffect()
{

	float angle;
	effect=2;
	isFinished = false;
	Matrix3 tempMatrix;
	Vector2 tempVelocity;
	for(int i = 0; i < numberOfParticlesInEffect; i++)
	{
		angle = MyRandomNumber::RandomInRange(.01f,1.0f)*((2.0f*3.14f)/100.0f);
		tempMatrix.Rotation(angle);
		velocity.x = MyRandomNumber::RandomInRange(-5.0f,5.0f);
		velocity.y = MyRandomNumber::RandomInRange(-5.0f,5.0f);
		tempVelocity = tempMatrix*(velocity);
		particles[i].isAlive = true;
		particles[i].position = this->position;
		particles[i].velocity = tempVelocity;
		particles[i].color = Util::Colors::VeryColor(RGB(100,100,255),255.0f);

	}
	
}

//void ParticleEffect::ClearArray()
//{
//	if(particles.size() > 0)
//	{
//	for(int it = 0; it <numberOfParticlesInEffect; it++)
//	{
//		//particles[it] = NULL;
//	}
//	particles.clear();
//	}
//}
