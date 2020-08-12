#include <stdio.h>

int main(void) {
    int score = 34567;
    printf("%d\n", score);

    const int MAX_SCORE = 100000;
    float percent = ((float)score/MAX_SCORE) * 100.0;

    printf("%0.2f\n", percent); 
    printf("%0.0f\n", percent); 
    return 0;
}
