#pragma once
char* analyzeTriangle(int side1, int side2, int side3);

// Calculates the three interior angles using the Law of Cosines
// Returns 1 if successful, 0 if the sides do not form a valid triangle
int calculateTriangleAngles(int side1, int side2, int side3, double angles[3]);


