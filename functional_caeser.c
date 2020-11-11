#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

enum shift {
    LEFT,
    RIGHT
};

enum shift getValidShiftDirection();
int getValidShiftAmount();
void getValidPhrase(char **message, int messageSize);
char* encryptMessage(char *message, int messageSize, enum shift direction, int shiftAmount);
char* decryptMessage(char* message, int messageSize, enum shift direction, int shiftAmount);

int main() {
    enum shift shiftDirection = getValidShiftDirection();
    int shiftAmount = getValidShiftAmount();
    char *phrase;
    getValidPhrase(&phrase, 100);
    int phraseLength = strlen(phrase);
    printf("Phrase: %s", phrase);

    char* encryptedPhrase = encryptMessage(
        phrase,
        phraseLength,
        shiftDirection,
        shiftAmount
    );

    printf("Encrypted Phrase: %s\n", encryptedPhrase);

    int encryptedLength = strlen(encryptedPhrase);

    char* enPhrase = encryptedPhrase;

    char* decryptedPhrase = decryptMessage(
        enPhrase,
        encryptedLength,
        shiftDirection,
        shiftAmount
    );

    printf("Decrypted Phrase: %s\n", decryptedPhrase);


}

char* decryptMessage(char* message, int messageSize, enum shift direction, int shiftAmount) {
    char* decryptedMessage = malloc((messageSize) * sizeof(char));

    for (int i = 0; i < messageSize; i++)
    {
        if (direction == LEFT) {
            decryptedMessage[i] = message[i] + shiftAmount;
        }
        if (direction == RIGHT) {
            decryptedMessage[i] = message[i] - shiftAmount;
        }
        if (decryptedMessage[i] > 'Z'){
            decryptedMessage[i] -= 'Z' - 'A' + 1;
        }
        if (decryptedMessage[i] < 'A'){
            decryptedMessage[i] += 'Z' - 'A' + 1;
        }
    }
    return decryptedMessage;
}

char* encryptMessage(char* message, int messageSize, enum shift direction, int shiftAmount) {
    char* encryptedMessage = malloc((messageSize - 1) * sizeof(char));

    for (int i = 0; i < messageSize - 1; i++)
    {
        if (direction == RIGHT) {
            encryptedMessage[i] = message[i] + shiftAmount;
        }
        if (direction == LEFT) {
            encryptedMessage[i] = message[i] - shiftAmount;
        }
        if (encryptedMessage[i] > 'Z'){
            encryptedMessage[i] -= 'Z' - 'A' + 1;
        }
        if (encryptedMessage[i] < 'A'){
            encryptedMessage[i] += 'Z' - 'A' + 1;
        }
    }
    return encryptedMessage;
}

void getValidPhrase(char **message, int messageSize) {
    char* tempMessage = malloc(sizeof(char)*messageSize);

    bool isInvalid = true;
    while (isInvalid) {
        printf("Enter a message (all caps): ");
        fgets(tempMessage, messageSize, stdin);
        int tempMessageLength = (int) strnlen(tempMessage, sizeof(tempMessage)) -1;

        bool isCaps = true;
        for (int i=0; i<tempMessageLength; i++) {
            if (!isupper(tempMessage[i])) {
                printf("ONLY uppercase alphabetic characters!\n");
                isCaps = false;
                break;
            }
        }
        if (isCaps){
            isInvalid = false;
        }
    }
    *message = tempMessage;
}
     
int getValidShiftAmount() {
    int shiftAmount;

    while (true) {
        printf("How far would you like to shift? (1-25): ");
        scanf(" %d%*c", &shiftAmount);
        if (shiftAmount >=1 && shiftAmount <=25) {
            break;
        }
        // I don't explicitly write else here because if its true
        // this line wont be reached anyways (implicit else)
        printf("Invalid Input.\n");
    }
    return shiftAmount;
}


enum shift getValidShiftDirection() {
    char shiftChar;
    enum shift shiftDirection;

    while(true) {
        printf("Please enter shift direction (l|r): ");
        scanf(" %c%*c", &shiftChar);
        shiftChar = tolower(shiftChar);
        if (shiftChar == 'l') {
            shiftDirection = LEFT;
            break;
        }
        if (shiftChar == 'r') {
            shiftDirection = RIGHT;
            break;
        }
        printf("Invalid Input.\n");
    }
    return shiftDirection;
}
