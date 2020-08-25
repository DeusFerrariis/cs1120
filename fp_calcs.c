#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    float originalFarenheit;
    float calculatedCelcius;
    float calculatedFareheit;

    printf("Enter temperature (Fahrenheit): ");
    scanf("%f", &originalFarenheit);

    calculatedCelcius = (originalFarenheit - 32) / 9 * 5;
    calculatedFareheit = (calculatedCelcius * 1.8) + 32;

    printf("%f\n", calculatedCelcius);
    printf("%f\n", calculatedFareheit);    
}
