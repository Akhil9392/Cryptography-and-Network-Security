#include <stdio.h>
void encrypt(const char *key, const char *plaintext, char *ciphertext) {
    sprintf(ciphertext, "E(%s, %s)", key, plaintext);
}
void cbcMacOneBlock(const char *key, const char *message, char *mac) {
    encrypt(key, message, mac);
}

void cbcMacTwoBlocks(const char *key, const char *message, char *mac) {
    char xorResult[16];
    char ciphertext[16];

    for (int i = 0; i < 16; i++) {
        xorResult[i] = message[i] ^ mac[i];
    }

    encrypt(key, xorResult, ciphertext);

    for (int i = 0; i < 16; i++) {
        mac[i] = ciphertext[i];
    }
}

int main() {
    const char key[] = "SecretKey123456";
    const char message[] = "Hello, CBC-MAC!";

    char macOneBlock[16];
    cbcMacOneBlock(key, message, macOneBlock);

    printf("MAC for One-Block Message: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", (unsigned char)macOneBlock[i]);
    }
    printf("\n");

    char macTwoBlocks[16];
    cbcMacTwoBlocks(key, message, macTwoBlocks);
    
    printf("MAC for Two-Block Message: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", (unsigned char)macTwoBlocks[i]);
    }
    printf("\n");

    return 0;
}
