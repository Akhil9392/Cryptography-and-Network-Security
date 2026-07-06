#include <stdio.h>

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}
char decryptChar(int a, int b, char c) {
    if (isalpha(c)) {
        char base = isupper(c) ? 'A' : 'a';
        return (char)((modInverse(a, 26) * (c - base - b + 26)) % 26 + base);
    } else {
        return c;
    }
}

int main() {
    char ciphertext[] = "BXUBBUUUBBUUUBBUXBUUUBBXU";
    
    char mostFrequent = 'B';
    char secondMostFrequent = 'U';

    int a, b;

    a = (secondMostFrequent - mostFrequent + 26) % 26;
    b = (mostFrequent - 'A') % 26;

    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        ciphertext[i] = decryptChar(a, b, ciphertext[i]);
    }

    printf("Decrypted message: %s\n", ciphertext);

    return 0;
}
