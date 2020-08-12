/*
* File:   main.c
* Author: Dr. T
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float getFloat();

/*
* Graded Exercise 5
*/
int main(int argc, char** argv)
{
	// Problem 1: Define type for GPS coordinates
	struct Coordinates {
		float latitude;
		float longitude;
	};
	// Problem 2: Declare and initialize variables
	struct Coordinates uccsCoords = {38.893647f, -104.800312f};
	struct Coordinates inputCoords = {getFloat(), getFloat()};
	// Problem 3: Print latitude and longitude differences
	float latDiff = fabsf(inputCoords.latitude-uccsCoords.latitude);
	float longDiff = fabsf(inputCoords.longitude-uccsCoords.longitude);
	
	printf("%0.6f,%0.6f\n", latDiff, longDiff);
	return (EXIT_SUCCESS);
}

/*
* Gets a floating-point number from the user
*/
float getFloat()
{
	float number;
	scanf("%f", &number);
	return number;
}

