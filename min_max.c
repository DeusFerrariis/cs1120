#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt();

int main(int argc, char** argv) {

    // Problem 1
    int scores[5] = {
        getInt(),
        getInt(),
        getInt(),
        getInt(),
        getInt(),
    };

    // Problem 2
    int min;
    int max;


    for(int i = 0; i < 5; i++) {
        if (i == 0) {
            min = scores[i];
            max = scores[i];
            continue;
        }
        if (scores[i] < min) {
            min = scores[i];
        }
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    printf("%d\n", min);
    printf("%d\n", max);

    // Problem 3

    int totalScores;
    printf("How many scores? : ");
    scanf("%d", &totalScores);

    int* newScores = malloc(totalScores * sizeof(int));

    int newMin;
    int newMax;

    for(int i = 0; i <= sizeof(newScores) / sizeof(newScores[0]); i++) {
        newScores[i] = getInt();
        if (i == 0) {
            newMin = newScores[i];
            newMax = newScores[i];
            continue;
        }
        if (newScores[i] < newMin) {
            newMin = newScores[i];
        }
        if (newScores[i] > newMax) {
            newMax = newScores[i];
        }
    }

    printf("%d\n", newMin);
    printf("%d\n", newMax);
}

int getInt() {
    int input;
    printf("Enter a score 0-100: ");
    scanf("%d", &input);
    while (input < 0 || input > 100) {
        printf("Invalid Score range please re-enter: ");
        scanf("%d", &input);
    }
    return input;
}
