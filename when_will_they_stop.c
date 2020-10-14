#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("This Program will Take a series of integers and return the mean\n");
    int total = 0;
    int intCount = 0;

    int currentInt = 0;
    while(currentInt != -1) {
        printf("Enter an int (-1 to quit) : ");
        scanf("%d", &currentInt);
        if (currentInt < 0 && currentInt != -1) {
            printf("Negative Ints not Allowed.");
            continue;
        }
        if (currentInt != -1) {
            total += currentInt;
            intCount++;
        }
    }
    printf("Mean: %0.2f\n", ((float) total / (float) intCount));
}