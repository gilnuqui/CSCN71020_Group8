#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"

// For conversion (radians to degrees)
#define PI 3.14159265358979323846

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

int calculateTriangleAngles(int side1, int side2, int side3, double angles[3])
{
	// make sure the sides are positive
	if (side1 <= 0 || side2 <= 0 || side3 <= 0)
	{
		return 0; // Not a valid triangle
	}

	// Check the triangle inequality rule.
	// The sum of any two sides must be greater than the third side.
	if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
	{
		return 0; // Not a valid triangle
	}
	
	double a = side1;
	double b = side2;
	double c = side3;

	double cosA = (b * b + c * c - a * a) / (2.0 * b * c);
	double cosB = (a * a + c * c - b * b) / (2.0 * a * c);
	double cosC = (a * a + b * b - c * c) / (2.0 * a * b);

	// prevent small floating point outside the range of acos
	if (cosA > 1.0)
	{
		cosA = 1.0;
	}
	if (cosB > 1.0)
	{
		cosB = 1.0;
	}
	if (cosC > 1.0)
	{
		cosC = 1.0;
	}
	if (cosA < -1.0)
	{
		cosA = -1.0;
	}
	if (cosB < -1.0)
	{
		cosB = -1.0;
	}
	if (cosC < -1.0)
	{
		cosC = -1.0;
	}

	angles[0] = acos(cosA) * (180.0 / PI);
	angles[1] = acos(cosB) * (180.0 / PI);
	angles[2] = acos(cosC) * (180.0 / PI);

	return 1;

}

