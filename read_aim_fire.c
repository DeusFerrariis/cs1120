/*
* File:   main.c
* Author: Dr. T
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define G 9.81
#ifndef M_PI
	#define M_PI 3.14159265358979323846f
#endif

float getFloat();

/*
* Calculates the maximum height and horizontal distance
* for a shell given an initial angle and speed
*/
int main(int argc, char** argv)
{
	// input variables
	float theta;
	float speed;

	// get initial angle and convert to radians
	theta = getFloat();
	float radiansTheta = theta * 0.01745329f;
	// get initial speed
	speed = getFloat();

	// calculate initial velocity components
	float vox = speed * cosf(radiansTheta);
	float voy = speed * sinf(radiansTheta);
	// calculate final values
	float t = voy / G;
	float h = pow(voy, 2) / (2 * G);
	float dx = (vox*2*t);
	// print max height and horizontal distance
	printf("%0.4f,%0.4f\n", h, dx);

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

