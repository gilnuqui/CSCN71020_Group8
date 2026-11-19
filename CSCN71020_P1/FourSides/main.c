#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define EPSILON 0.001f

float getCoordinate(const char* prompt);

int main()
{
	float x1, x2, y1, y2, x3, x4, y3, y4;

	x1 = getCoordinate("enter x1 cordinates:\n");
	y1 = getCoordinate("enter y1 cordinates:\n");
	x2 = getCoordinate("enter x2 cordinates:\n");
	y2 = getCoordinate("enter y2 cordinates:\n");
	x3 = getCoordinate("enter x3 cordinates:\n");
	y3 = getCoordinate("enter y3 cordinates:\n");
	x4 = getCoordinate("enter x4 cordinates:\n");
	y4 = getCoordinate("enter y4 cordinates:\n");

	// the four lines: 1-2, 2-3, 3-4, 4-1
	float side1 = sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2));
	float side2 = sqrtf(powf(x3 - x2, 2) + powf(y3 - y2, 2));
	float side3 = sqrtf(powf(x4 - x3, 2) + powf(y4 - y3, 2));
	float side4 = sqrtf(powf(x1 - x4, 2) + powf(y1 - y4, 2));

	// 2-4 and 1-3 diagonals
	float sidediagonal2 = sqrtf(powf(x4 - x2, 2) + powf(y4 - y2, 2));
	float sidediagonal1 = sqrtf(powf(x3 - x1, 2) + powf(y3 - y1, 2));

	float perimeter = side1 + side2 + side3 + side4;
	printf("\nPerimeter: %.2f\n", perimeter);

	// rectangle test:
	// no zero-length sides, opposite sides equal, and both diagonals equal
	bool nonZero = side1 > EPSILON && side2 > EPSILON &&
		side3 > EPSILON && side4 > EPSILON;
	bool oppositeSidesEqual = fabsf(side1 - side3) < EPSILON &&
		fabsf(side2 - side4) < EPSILON;
	bool diagonalsEqual = fabsf(sidediagonal1 - sidediagonal2) < EPSILON;

	if (nonZero && oppositeSidesEqual && diagonalsEqual)
	{
		float area = side1 * side2;
		printf("The shape is a rectangle.\n");
		printf("Area: %.2f\n", area);
	}
	else
	{
		printf("The shape is not a rectangle.\n");
	}

	return 0;
}

// asks until the user enters one valid number
float getCoordinate(const char* prompt)
{
	float value;
	while (true)
	{
		printf("%s", prompt);
		int result = scanf_s("%f", &value);

		// clear the rest of the line, and note any junk like "3abc"
		bool junk = false;
		int c;
		while ((c = getchar()) != '\n' && c != EOF)
		{
			if (c != ' ' && c != '\t' && c != '\r')
				junk = true;
		}

		if (result == 1 && !junk && isfinite(value))
			return value;

		printf("Invalid input. Please enter a number.\n");
	}
}