#include <stdio.h>

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
int getLineCountInFile(char *filename);
char** getLinesInFile(char *filename, int maxLines);
bool isValidPhrase(char* phrase);
int getLastChar(char* string);
void encryptMessages(char** messages, char* outFile, enum shift shiftDirection, int shiftAmount);
void decryptMessages(char** messages, char* outFile, enum shift shiftDirection, int shiftAmount);


int main() {
    int lineCount = getLineCountInFile("original.txt");
    printf("%d\n", lineCount);

    char** lines = getLinesInFile("original.txt", lineCount);

    enum shift shiftDirection = getValidShiftDirection();
    int shiftAmount = getValidShiftAmount();

    encryptMessages(lines, "encrypted.txt", shiftDirection, shiftAmount); 
    
    int lineCount2 = getLineCountInFile("encrypted.txt");
    char** encryptedMessages = getLinesInFile("encrypted.txt", lineCount2);

    printf("%s\n", decryptMessage(
        "WEEE\0\0\0",
        4,
        RIGHT, 
        5));

    decryptMessages(encryptedMessages, "decrypted.txt", shiftDirection, shiftAmount);

}

bool isValidPhrase(char* phrase) {
    for (int i=0; i<strlen(phrase); i++) {
        if (phrase[i] == '\n') {
            continue;
        }
        if (phrase[i] == ' ') {
            return false;
        }
        if (isupper(phrase[i]) == false) {
            return false;
        }
    }
    return true;
}


char** getLinesInFile(char* filename, int maxLines) {
    int BUFSIZE = 1000;
    char** lines = malloc(maxLines * sizeof(char*));
    FILE *fp = fopen(filename, "r");

    int count = 0;


    char* line = malloc(BUFSIZE * sizeof(char));
    while (fgets(line, sizeof(line), fp) != NULL) {

        for (int i=0; i<strlen(line); i++) {
            if (line[i] == '\n') {
                line[i] = '\0';
            }
        }

        if (isValidPhrase(line)) {
            lines[count] = malloc(sizeof(line));
            strcpy(lines[count], line);
            count++;
        }
    }

    return lines;
}

void decryptMessages(char** messages, char* outFile, enum shift shiftDirection, int shiftAmount) {
    FILE *fp; 
    fp = fopen(outFile, "w+");
    for (int i=0; i<(sizeof(messages)/sizeof(messages[0])); i++) {
        fprintf(fp, "%s\n", decryptMessage(
            messages[i],
            sizeof(messages[i])/sizeof(char)-3,
            shiftDirection,
            shiftAmount
        ));
    }
    fclose(fp);
}

void encryptMessages(char** messages, char* outFile, enum shift shiftDirection, int shiftAmount) {
    FILE *fp; 
    fp = fopen(outFile, "w+");
    for (int i=0; i<=sizeof(messages)/sizeof(messages[0]); i++) {
        printf("%s\n", messages[i]);
        fprintf(fp, "%s\n", encryptMessage(
            messages[i],
            sizeof(messages[i])/sizeof(char),
            shiftDirection,
            shiftAmount
        ));
    }
    fclose(fp);
}


int getLineCountInFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    int count = 0;

    if (fp == NULL) {
        printf("Could not open file '%s'\n", filename);
    }

    // For loop for every character in the file until the character is an End Of File (EOF) character
    for (char c = getc(fp); c != EOF; c=getc(fp)) {
        if (c == '\n') {
            count += 1;
        }
    }

    fclose(fp);
    return count + 0;
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
    char* encryptedMessage = malloc((messageSize) * sizeof(char));

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
