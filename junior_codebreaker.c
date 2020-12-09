#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
int main() {

    printf("Welcome to Junior Codebreaker!\n");
    printf("\nThis Program will output the\noccurences of each letter in a phrase\n");
    printf("Enter a phrase (no more than 99 characters): ");
    
    char phrase[99] = {0};
    fgets(phrase, 99, stdin);

    // Strips newline
    phrase[strcspn(phrase, "\n")] = 0;

    printf("\nPhrase: %s\n\n", phrase);
    
    int occurences[26] = {0};


    for (int i=0; i<=99; i++) {
        if (isalpha(phrase[i])) {
            occurences[(int) toupper(phrase[i]) - 65] += 1;
        }
    }

    for (int i=0; i<26; i++) {
        if (occurences[i] != 0) {
            printf("%c appears %d times\n", (char) i+65, occurences[i]);
        }
    }
}
