#include <stdio.h>

int main(void) {
	
	int probOne;
	scanf("%d", &probOne);
	if (probOne >= 0) {
		printf("Positive\n");
	}

	int probTwo;
	scanf("%d", &probTwo);
	if (probTwo >= 0) {
		printf("Positive\n");
	}
	else {
		printf("Negative\n");
	}
	
	printf("************\n");
	printf("N  New Game\n");
	printf("L  Load Game\n");
	printf("O  Options\n");
	printf("Q  Quit\n");
	printf("************\n");
	
	getchar();
	char choice = getchar();
	
	if (choice == 'n') {
		printf("Starting\n");
	}
	else if (choice == 'l') {
		printf("Loading\n");
	}
	else if (choice == 'o') {
		printf("Options\n");
	}
	else if (choice == 'q') {
		printf("Quitting\n");
	}
	else {
		printf("Invalid");
	}

}
