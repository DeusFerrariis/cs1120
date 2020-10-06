#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void clearBuffer();

int main(int argc, char** argv) {

    // Problem 1

    int firstInt;
    printf("Enter an Int: ");
    scanf("%d", &firstInt);

    if (firstInt >= 0) {
        printf("First Int was Positive\n");
    }

    // Problem 2

    int secondInt;
    printf("Enter an Int: ");
    scanf("%d", &secondInt);

    if (secondInt >= 0) {
        printf("Second Int was Positive\n");
    }    
    else {
        printf("Second Int was Negative\n");
    }
    
    // Problem 3

    printf("****************\n");
    printf("N New Game\n");
    printf("L Load Game\n");
    printf("O Options\n");
    printf("Q Quit\n");
    printf("****************\n");

    char choice;
    clearBuffer();
    scanf("%c", &choice);
    choice = toupper(choice);


    if (choice == 'N'){
        printf("Creating new game...\n");
        return (EXIT_SUCCESS);
    }

    else if (choice == 'L') {
        printf("Loading game...\n");
        return (EXIT_SUCCESS);
    }

    else if (choice == 'O') {
        printf("Fetching options...\n");
        return (EXIT_SUCCESS);
    }

    else if (choice == 'Q')
    {
        printf("Quitting...\n");
        return (EXIT_SUCCESS);
    }

    else {
        printf("Unknown choice\n");
        return (EXIT_SUCCESS);
    }
    

	return (EXIT_SUCCESS);


}

// Fixes \n issue
void clearBuffer() {
    while ((getchar()) != '\n');
}