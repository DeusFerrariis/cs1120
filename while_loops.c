#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {
    // Problem 1
    int biggest_int = 0;
    int current_int = 0;
    while (current_int != -1) {
        printf("Enter an int (-1 to quit): ");
        scanf("%d", &current_int);
        if (current_int > biggest_int) {
            biggest_int = biggest_int + current_int - biggest_int; 
        }
    }
    printf("Largest Entered Int: %d\n", biggest_int);
}
