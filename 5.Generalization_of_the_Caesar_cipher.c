#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int areCoprime(int a, int b) {
    return gcd(a, b) == 1;
}

char encryptChar(int a, int b, char p) {
    if (isalpha(p)) {
        char base = isupper(p) ? 'A' : 'a';
        return (char)(((a * (p - base) + b) % 26) + base);
    } else {
        return p;
    }
}

int main() {
    int a, b;

    printf("Enter the value for 'a': ");
    scanf("%d", &a);

    printf("Enter the value for 'b': ");
    scanf("%d", &b);

    if (!areCoprime(b, 26)) {
        printf("Error: 'b' must be relatively prime to 26.\n");
        return 1;
    }

    if (!areCoprime(a, 26)) {
        printf("Error: 'a' must be chosen such that it is coprime to 26.\n");
        return 1;
    }

    char plaintext[] = "HelloWorld";
    char ciphertext[50];

    for (int i = 0; plaintext[i] != '\0'; ++i) {
        ciphertext[i] = encryptChar(a, b, plaintext[i]);
    }

    ciphertext[strlen(plaintext)] = '\0';

    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}
