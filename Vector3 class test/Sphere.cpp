#include "Sphere.h"



Sphere::Sphere()
{
	radius = 0;
	position.setX(0);
	position.setY(0);
	position.setZ(0);
}

Sphere::Sphere(float x, float y, float z, float _radius,
				int _r, int _g, int _b)
{
	radius = _radius;
	position.setX(x);
	position.setY(y);
	position.setZ(z);
	sphereCol.r = _r;
	sphereCol.g = _g;
	sphereCol.b = _b;
}

float Sphere::getRadius()
{
	return radius;
}

int Sphere::getColorR()
{
	return sphereCol.r;
}

int Sphere::getColorG()
{
	return sphereCol.g;
}

int Sphere::getColorB()
{
	return sphereCol.b;
}

Vector3 Sphere::getPosition()
{
	return position;
}

Sphere::~Sphere()
{
}
