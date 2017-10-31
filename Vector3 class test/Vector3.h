#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float _x, float _y, float _z);
	~Vector3();

	void print();
	Vector3 crossProduct(Vector3 vectorB);
	Vector3 takeAway(Vector3 vectorB);
	Vector3 addition(Vector3 vectorB);
	Vector3 divideScalar(float value);
	Vector3 normalized();
	Vector3 multiply(float value);
	float dotProduct(Vector3 vectorB);

	float getX();
	float getY();
	float getZ();
	void setX(float position);
	void setY(float position);
	void setZ(float position);

private:
	float x, y, z;
};





