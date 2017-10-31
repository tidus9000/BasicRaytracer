#pragma once
#include "Sphere.h"
class LightSource :
	public Sphere
{
public:
	LightSource();
	~LightSource();
private:
	float brightness;
};

