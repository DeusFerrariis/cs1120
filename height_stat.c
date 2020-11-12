#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1
#define MIN 0

void printWelcomeMessage();
int getValidInteger(char promptString[], char errorString[], int lowerBound, int upperBound);
float averageIntegerArray(int values[], int count);
int findExtremeInIntegerArray(int minOrMax, int values[], int count);
void printIntegerArray(char heading[], int values[], int count);


int main() {
    int totalHeights = getValidInteger(
        "How many heights would you like to enter? (1-100): ",
        "Please enter a number within the range.\n",
        0,
        100
    );

    int* heights = malloc(totalHeights * sizeof(int));
    printf("oof\n");

    for (int i = 0; i < totalHeights; i++) {
        heights[i] = getValidInteger(
            "Please enter a height (1-96): ",
            "Invalid Height.\n",
            1,
            96
        );
    }

    printIntegerArray("-Entered Numbers-\n", heights, totalHeights);

    float average = averageIntegerArray(heights, totalHeights);
    printf("Average: %f\n", average);

    int max = findExtremeInIntegerArray(MAX, heights, totalHeights);
    int min = findExtremeInIntegerArray(MIN, heights, totalHeights);
    printf("min: %d, max: %d\n", min, max);

}

void printWelcomeMessage() {
    printf("Welcome to the Height Statisticamator\n");
    printf("This application takes a series of heights and returns statistics about the data\n");
}

int getValidInteger(char promptString[], char errorString[], int lowerBound, int upperBound) {
    int number;
    while (true) {
        printf("%s", promptString);
        scanf("%d", &number);
        if (number >= lowerBound && number <= upperBound) {
            break;
        }
        printf("%s", errorString);
    }
    return number;
}

float averageIntegerArray(int values[], int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += values[i];
    }
    return (float) total / (float) count;
}

int findExtremeInIntegerArray(int minOrMax, int values[], int count) {
    int min = values[0];
    int max = values[0];
    for (int i = 0; i < count; i++) {
        if (values[i] < min) {
            min = values[i];
        }
        if (values[i] > max) {
            max = values[i];
        }
    }
    if (minOrMax == MAX) {
        return max;
    }
    else {
        return min;
    }
}

void printIntegerArray(char heading[], int values[], int count) {
   printf("%s", heading);
   for (int i=0; i<count; i++) {
        if ((i % 5 == 0 && i > 1) || i == count-1) {
            printf("%d\n", values[i]);
            continue;
        }
        else {
            printf("%d, ", values[i]);
        }
    }
   printf("\n");
}
