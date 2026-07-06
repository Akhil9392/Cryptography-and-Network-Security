#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateCipherSequence(char keyword[], char cipherSequence[]) {
    int keywordLength = strlen(keyword);
    int index = 0;

    strcpy(cipherSequence, keyword);

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        if (strchr(keyword, toupper(ch)) == NULL) {
            cipherSequence[keywordLength + index] = ch;
            ++index;
        }
    }

    cipherSequence[keywordLength + index] = '\0';
}

void monoalphabeticCipher(char message[], char cipherSequence[]) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';

            message[i] = cipherSequence[message[i] - base];
        }
    }
}

int main() {
    char keyword[] = "CIPHER";
    char cipherSequence[26];
    char message[100];

    generateCipherSequence(keyword, cipherSequence);

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    monoalphabeticCipher(message, cipherSequence);

    printf("Encrypted message: %s", message);

    return 0;
}
