
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

    switch(choice){

        case 'N':
            printf("Creating new game...\n");
            break;

        case 'L':
            printf("Loading game...\n");
            break;

        case 'O':
            printf("Fetching options...\n");
            break;
        
        case 'Q':
            printf("Quitting...\n");
            break;

        default:
            printf("Unknown choice\n");
            break;
    }
    

	return (EXIT_SUCCESS);
}