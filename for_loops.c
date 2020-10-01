#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * get_asterisk(int length);

int main(int argc, char** argv) {

    // Problem 1
    int range;

    printf("Enter Range: ");
    scanf("%d", &range);

    for (int a=0; a <= range; a++) {
       if (a % 2 == 0) {
           printf("%d\n", a);
       } 
    }

    // Problem 2
    int total;

    printf("Total Asterisks: ");
    scanf("%d", &total);

    char asterisks_string[total+2];

    for (int i = 0; i < total; i++) {
        strcat(asterisks_string, "*");
    }

    strcat(asterisks_string, "\n");

    printf("%s", asterisks_string);

    // Problem 3
    int height;
    int width;

    printf("Width: ");
    scanf("%d", &width);

    printf("Height: ");
    scanf("%d", &height);

    char new_string[height+2];
    for (int j = 0; j < width; j++) {
        strcat(new_string, "*");
    }

    strcat(new_string, "\n");

    for (int i = 0; i < height; i++) {
        printf("%s", new_string);
    }

    // Problem 4
    int rows;
    
    printf("Rows: ");
    scanf("%d", &rows);

    char newer_string[rows+2];

    for (int i = 1; i <= rows; i++) {
        
        //Sets string to empty
        memset(newer_string, 0, sizeof(newer_string));

        for (int j=0; j < i; j++) {
            strcat(newer_string, "*");
        }

        printf("%s\n", newer_string);

    }


    return 0;
}
