#include <stdio.h>

int main(void) {

    float originalFarenheit;
    float calculatedCelcius;
    float calculatedFareheit;

    scanf("%f", &originalFarenheit);

    calculatedCelcius = (originalFarenheit - 32) / 9*5;
    calculatedFareheit = (calculatedFareheit * 9 * 5) + 32;

    printf("%f\n", calculatedCelcius);
    printf("%f\n", calculatedFareheit);
}
