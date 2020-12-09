#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char[100] getMessage();

int main() {
    char originalMessage[100] = getMessage();
    
    /*
    bool validMesasage = false;
    printf("Enter message to be encrypted (upper case alphabetic charcaters only): ");
    fgets(originalMessage, sizeof(originalMessage), stdin);
    int originalMessageLength = strnlen(originalMessage, sizeof(originalMessage)) -1;

    while (!validMesasage) {
        validMessage = true;
        for (int i=0; i<originalMessageLength; i++) {
            if (!isupper(originalMessage[i])) {
                printf("\n");
                printf("Message can only contain uppercase alphabetic characters.\n");
                printf("Enter message to be encrypted (upper case alphabetic charcaters only): ");
                fgets(originalMessage, sizeof(originalMessage), stdin);
                originalMessageLength = strnlen(originalMessage, sizeof(originalMessage)) -1;

                validMessage = false;
                break;
            }
        }
    }

    char* encryptedMessage = malloc((originalMessageLength + 1) * sizeof(char));
    for (int i=0; i<originalMessageLength; i++){
        encryptedMessage[i] = originalMessage[i] + SHIFT_AMOUNT;
        if (encryptedMessage[i] > 'Z'){
            encryptedMessage[i] -= 'Z' - 'A' + 1;
        }
    }

    encryptedMessage[originalMessageLength] = '\0';
    */

}

char[100] getMessage() {
    char message[100];
    printf("Enter message to be encrypted (upper case alphabetic charcaters only): ");
    fgets(message, sizeof(message), stdin);
    return &message;
}
