#include "Vector3.h"
#include "Ray.h"
#include "Sphere.h"
#include "LightSource.h"
#include <iostream>
#include <fstream>

int main()
{
	Ray::color outputColor;
	Vector3 newvector(1, 2, 3);
	Vector3 secondVector(-2, 1, -3);
	Vector3 crossedVector;
	int imageWidth = 255;
	int imageHeight = 255;
	
	newvector.print();
	std::cout << "\nHello\n";
	secondVector.print();
	std::cout << "\nCross Product:\n";
	crossedVector = newvector.crossProduct(secondVector);
	crossedVector.print();
	float dotProduct = newvector.dotProduct(secondVector);
	std::cout << "\nDot Product:\n";
	std::cout << dotProduct << std::endl;
	int numberOfSpheres = 2;

	Ray* testRay;
	Sphere* sphereArray = new Sphere[numberOfSpheres];
	sphereArray[0] = Sphere(15, 3, 3, 1, 0, 0, 255);
	sphereArray[1] = Sphere(15, 3, -3, 1, 255, 255, 0);

	std::ofstream img("picture14.png");
	img << "P3" << std::endl;
	img << imageWidth << " " << imageHeight << std::endl;
	img << "255" << std::endl;

	float planeWidth = 7, planeHeight = 7;

	double widthIncrement = planeWidth / imageWidth;
	double heightIncrement = planeHeight / imageHeight;

	std::cout << "Drawing...\n";

	for (float i = 0 + (planeHeight / 2); i > 0 - (planeHeight / 2); i = i - heightIncrement)
	{
		for (float j = 0 - (planeWidth / 2); j < (planeWidth / 2); j = j + widthIncrement)
		{
			testRay = new Ray(Vector3(0, 0, 0), Vector3(13, i, j));
			bool anyIntersection = false;
			for (int sphereInc = 0; sphereInc < numberOfSpheres; sphereInc++)
			{
				if (testRay->checkCollisionSphere(sphereArray[sphereInc], &outputColor))
				{
					//std::cout << "Ray (" << "1.5, " << i << ", " << j << ") collides with sphere!\n";
					//std::cout << "*";
					//img << 0 << " " << 0 << " " << 255 << std::endl;
					anyIntersection = true;
				}
				else
				{
					//std::cout << "Ray (" << "1.5, " << i << ", " << j << ") doesn't collide with sphere\n";
					//std::cout << ".";
					//img << 0 << " " << 0 << " " << 0 << std::endl;
				}
			}

			if (anyIntersection)
			{
				img << outputColor.r << " " << outputColor.g << " " << outputColor.b << std::endl;
			}
			else
			{
				img << 0 << " " << 0 << " " << 0 << std::endl;

			}
			delete testRay;
		}
		std::cout << std::endl;
	}

	return 0;
}