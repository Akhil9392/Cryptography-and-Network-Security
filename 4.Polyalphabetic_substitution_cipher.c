#include <stdio.h>
#include <ctype.h>
#include <string.h>

void polyalphabeticCipher(char message[], char key[]) {
    int keyLength = strlen(key);
    int messageLength = strlen(message);

    for (int i = 0; i < messageLength; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            int keyIndex = i % keyLength;

            char encryptedChar = (char)(((message[i] - base + key[keyIndex] - 'A') % 26) + base);

            message[i] = encryptedChar;
        }
    }
}

int main() {
    char message[100];
    char key[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key (a word or phrase): ");
    fgets(key, sizeof(key), stdin);

    strtok(message, "\n");
    strtok(key, "\n");
    
    polyalphabeticCipher(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
