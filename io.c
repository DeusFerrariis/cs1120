#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char movement;
bool shifting = false;
int amount;
bool solution = false;

char getValidShiftDirection();
char* getPhrase();

enum shift {
   RIGHT,
   LEFT
};

enum shift currentShift = RIGHT;

int main(int argc, const char * argv[]) {

   while (!shifting)

   {
       printf("Which direction do you want to move (l or r)");
       scanf(" %c", &movement);
       movement = tolower(movement);
       if (movement == 'l' || movement == 'r')
       {
           shifting = true;
       }
       else
       {
           printf("Invalid Input\n");
       }
   }

    while (!solution)

    {
        printf("How many times would you like to shift (1 to 25)");
        scanf("%d", &amount);
        if (amount >= 1 && amount <= 25)
        {
            solution = true;
        }
        else
        {
            printf("Invalid Input");
        }
    }
       getchar();
    char originalMessage[100];
       bool validMessage = false;
       printf("Enter UPPER CASE message to be encrypted: ");
       fgets(originalMessage, sizeof(originalMessage), stdin);
       int originalMessageLength = (int)strnlen(originalMessage, sizeof(originalMessage)) - 1;
       while (!validMessage)

       {
           validMessage = true;

           for (int i = 0; i < originalMessageLength; i++)
           {
               if (!isupper(originalMessage[i]))
               {
                   printf("\n");
                   printf("ONLY upper case alphabetic characters!\n");
                   printf("Re-Enter message to be encrypted: ");
                   fgets(originalMessage, sizeof(originalMessage), stdin);

                   originalMessageLength = (int)strnlen(originalMessage, sizeof(originalMessage)) - 1;

                   validMessage = false;
                   break;
               }
           }
       }
       
       char* encryptedMessage = malloc((originalMessageLength + 1) * sizeof(char));

       for (int i = 0; i < originalMessageLength; i++)
       {
           if (movement == 'r')
           {
           encryptedMessage[i] = originalMessage[i] + amount;
           }
           if (movement == 'l')
            {
            encryptedMessage[i] = originalMessage[i] - amount;
            }
            if (encryptedMessage[i] > 'Z')
           {
               encryptedMessage[i] -= 'Z' - 'A' + 1;
           }
           if (encryptedMessage[i] < 'A')
           {
               encryptedMessage[i] += 'Z' - 'A' + 1;
           }
       }
      encryptedMessage[originalMessageLength] = '\0';       

      int encryptedMessageLength = originalMessageLength;
      char* decryptedMessage = malloc((encryptedMessageLength + 1) * sizeof(char));

       for (int i = 0; i < encryptedMessageLength; i++)
       {
           if (movement == 'r')
           {

              char getValidShiftDirection();
              char* getPhrase();
              
           decryptedMessage[i] = encryptedMessage[i] - amount;
           }
           if (movement == 'l')
            {
            decryptedMessage[i] = encryptedMessage[i] + amount;
            }
           if (decryptedMessage[i] < 'A')
           {
               decryptedMessage[i] += 'Z' - 'A' + 1;
           }
           if (decryptedMessage[i] < 'Z')
            {
                decryptedMessage[i] -= 'Z' - 'A' + 1;
            }
       }

       decryptedMessage[encryptedMessageLength] = '\0';

       printf("\n");
       printf("Original Message : %s", originalMessage);
       printf("Encrypted Message: %s\n", encryptedMessage);
       printf("Decrypted Message: %s\n", decryptedMessage);

       free(encryptedMessage);
       encryptedMessage = NULL;
       free(decryptedMessage);
       decryptedMessage = NULL;

       printf("\n");

    return 0;

}
