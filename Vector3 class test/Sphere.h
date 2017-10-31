#pragma once
#include "Vector3.h"
class Sphere
{
public:
	Sphere();
	Sphere(float x, float y, float z, float _radius,
			int _r, int _g, int _b);
	~Sphere();

	int getColorR();
	int getColorG();
	int getColorB();
	float getRadius();
	Vector3 getPosition();

private:
	Vector3 position;
	float radius;
	struct color
	{
		int r;
		int g;
		int b;
	};
	color sphereCol;
};

