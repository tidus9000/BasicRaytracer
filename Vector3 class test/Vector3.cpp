#include "Vector3.h"
#include <iostream>



Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
};

Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Vector3::print()
{
	std::cout << "(" << x << ", " << y << ", " << z << ")";
}

Vector3 Vector3::crossProduct(Vector3 vectorB)
{
	Vector3 returnedVector((y * vectorB.getZ())-(z * vectorB.getY()), 
							(z * vectorB.getX())-(x * vectorB.getZ()),
							(x * vectorB.getY())-(y * vectorB.getX()));

	return returnedVector;

}

Vector3 Vector3::takeAway(Vector3 vectorB)
{
	Vector3 returnedVector((x - vectorB.getX()), (y - vectorB.getY()), (z - vectorB.getZ()));
	return returnedVector;
}

Vector3 Vector3::multiply(float value)
{
	Vector3 returnedValue(x * value, y * value, z * value);
	return returnedValue;
}

Vector3 Vector3::addition(Vector3 vectorB)
{
	Vector3 returnedValue(x + vectorB.getX(), y + vectorB.getY(), z + vectorB.getZ());
	return returnedValue;
}

Vector3 Vector3::divideScalar(float value)
{
	Vector3 returnedVector(x / value, y / value, z / value);
	return returnedVector;
}

Vector3 Vector3::normalized()
{
	float magnitude = sqrt((x * x) + (y * y) + (z * z));
	Vector3 returnedVector(x, y, z);
	returnedVector = returnedVector.divideScalar(magnitude);
	return returnedVector;
}

float Vector3::dotProduct(Vector3 VectorB)
{
	float returnedValue = (x * VectorB.getX()) +
		(y * VectorB.getY()) +
		(z * VectorB.getZ());
	return returnedValue;
}

float Vector3::getX()
{
	return x;
}

float Vector3::getY()
{
	return y;
}

float Vector3::getZ()
{
	return z;
}

void Vector3::setX(float position)
{
	x = position;
}

void Vector3::setY(float position)
{
	y = position;
}

void Vector3::setZ(float position)
{
	z = position;
}

Vector3::~Vector3()
{
}
