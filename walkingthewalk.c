#include <stdio.h>

void rewind_arr(int* arr, int steps);

int main() {
    int arrWidth = 0;
    printf("how many values?: ");
    scanf(" %d", &arrWidth);

    int* values = malloc(arrWidth * sizeof(int));

    int* val_ptr = &values[0];
    for (int i=0; i<arrWidth; i++) {
        *val_ptr = i;
        if (i < arrWidth - 1) {
            *val_ptr++;
        }
    }


    val_ptr = &values[0];
    for (int i=0; i<arrWidth; i++) {
        printf("%d\n", *val_ptr);
        if (i < arrWidth - 1) {
            *val_ptr++;
        }
    }
    
    int sum = 0;
    val_ptr = &values[0];
    for (int i=0; i<arrWidth; i++) {
        sum = sum + *val_ptr;
        if (i < arrWidth - 1) {
            *val_ptr++;
        }
    }
    printf("sum: %d\n", sum);
}

