#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculateFrequency(char *ciphertext, int *frequency) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            frequency[ciphertext[i] - 'A']++;
        }
        i++;
    }
}

void letterFrequencyAttack(char *ciphertext, int topN) {
    int frequency[26] = {0}; // Initialize frequency array for 26 letters
    calculateFrequency(ciphertext, frequency);

    int sortedFrequency[26];
    for (int i = 0; i < 26; i++) {
        sortedFrequency[i] = frequency[i];
    }

    for (int i = 0; i < 26 - 1; i++) {
        for (int j = 0; j < 26 - i - 1; j++) {
            if (sortedFrequency[j] < sortedFrequency[j + 1]) {
                int temp = sortedFrequency[j];
                sortedFrequency[j] = sortedFrequency[j + 1];
                sortedFrequency[j + 1] = temp;
            }
        }
    }

    printf("Top %d possible plaintexts:\n", topN);
    for (int n = 0; n < topN; n++) {
        printf("%d. ", n + 1);
        for (int i = 0; i < 26; i++) {
            if (frequency[i] == sortedFrequency[n]) {
                printf("%c", 'A' + i);
            }
        }
        printf(": ");
        for (int i = 0; ciphertext[i] != '\0'; i++) {
            if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
                printf("%c", 'A' + (ciphertext[i] - 'A' + 26 - sortedFrequency[n]) % 26);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char ciphertext[] = "CIPHER TEXT GOES HERE"; // Replace with your ciphertext
    int topN = 10; // Number of top possible plaintexts to show

    letterFrequencyAttack(ciphertext, topN);

    return 0;
}
