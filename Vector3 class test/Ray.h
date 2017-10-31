#pragma once
#include "Vector3.h"
#include "Sphere.h"

class Ray
{
public:
	Ray();
	~Ray();
	Ray(Vector3 _origin, Vector3 _direction);
	struct color
	{
		int r;
		int g;
		int b;
	};

	bool checkCollisionSphere(Sphere s, color* returnedColor);

private:
	Vector3 origin;
	Vector3 direction;
};

