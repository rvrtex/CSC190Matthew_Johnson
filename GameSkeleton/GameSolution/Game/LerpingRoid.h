#ifndef LERPING_H
#define LERPING_H
#include "Vector2.h"
#include "Core.h"





class LerpingRoid
{
public:
	Vector2 position;
	Vector2 velocity;

	void draw(Core::Graphics& );
	void update(float dt);



};

#endif
