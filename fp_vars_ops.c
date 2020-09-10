#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    
    // Problem 1
    int score = rand() % (100000 + 1 - 0) + 0;
    printf("%d\n", score);
    
    // Problem 2
    const int MAX_SCORE = 100000;
    float percentage = (float)score / (float)MAX_SCORE  * 100;
    printf("%0.2f\n", percentage);
    
    // Problem 3
    printf("%0.0f\n", percentage);
}
