#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char** argv) {

    printf("****************\n");
    printf("N New Game\n");
    printf("L Load Game\n");
    printf("O Options\n");
    printf("Q Quit\n");
    printf("****************\n");

    char choice;
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