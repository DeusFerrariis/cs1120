#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float getFloat();

/*
* Graded Exercise 5
*/

typedef struct Coordinates {
  float latitude;
  float longitude;
} Coordinates;

int main(int argc, char** argv)
{
	// Problem 1: Define type for GPS coordinates
	// Problem 2: Declare and initialize variables
    // UCCS COORDS
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
  printf("enter float coordinate: ");
	scanf("%f", &number);
	return number;
}