#include "Ray.h"
#include <math.h>



Ray::Ray()
{

}

Ray::Ray(Vector3 _origin, Vector3 _direction)
{
	origin = _origin;
	direction = _direction;
}

bool Ray::checkCollisionSphere(Sphere s, color* returnedColor)
{
	//L is distance from origin to center of circle
	Vector3 L = s.getPosition().takeAway(origin);
	//D is the normalized vector for direction
	Vector3 D = direction.normalized();

	//find magnitude of L and use that to find tc - distance from origin to closest point to center of sphere
	float lMag = sqrt(pow(L.getX(), 2.0) + pow(L.getY(), 2.0) + pow(L.getZ(), 2.0));

	//this code is not as accurate but keep it here to show yourself how you got here
	//float costheta = (L.dotProduct(direction)) / ((sqrt((L.getX() * L.getX()) + (L.getY() * L.getY()) + (L.getZ() * L.getZ()))) *
		//(sqrt((direction.getX() * direction.getX())+(direction.getY() * direction.getY())+(direction.getZ() * direction.getZ()))));
	//float tc = sqrt((L.getX() * L.getX()) + (L.getY() * L.getY()) + (L.getZ() * L.getZ())) / costheta;


	float tc = D.dotProduct(L);
	if (tc < 0)
	{
		return false;
	}

	//Find distance from center of circle to closest point to direction vector
	float distance = sqrt((lMag * lMag) - (tc * tc));

	//if that distance is greater than the radius, then there is no intersection
	if (distance > s.getRadius())
	{
		return false;
	}
	else
	{

		//t1c is line from one point of intersection and midpoint.
		float t1c = sqrt((s.getRadius() * s.getRadius()) - (distance * distance));
		float t1 = tc - t1c;
		float t2 = tc + t1c;

		//finding what to multiply direction of ray vector by to get intersection point.
		float multiplicationfactor1 = t1 / sqrt((direction.getX()*direction.getX()) + (direction.getY()*direction.getY()) + (direction.getZ()*direction.getZ()));
		float multiplicationfactor2 = t2 / sqrt((direction.getX()*direction.getX()) + (direction.getY()*direction.getY()) + (direction.getZ()*direction.getZ()));

		//get those points
		Vector3 p1 = origin.addition(direction);
		p1 = p1.multiply(multiplicationfactor1);

		Vector3 p2 = origin.addition(direction);
		p2 = p2.multiply(multiplicationfactor2);

		returnedColor->r = s.getColorR();
		returnedColor->g = s.getColorG();
		returnedColor->b = s.getColorB();

		return true;
	}
}

Ray::~Ray()
{
}
