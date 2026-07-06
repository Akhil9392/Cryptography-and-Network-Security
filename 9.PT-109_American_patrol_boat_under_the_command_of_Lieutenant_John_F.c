#include <stdio.h>
#include <string.h>

void prepareKeyTable(char key[], char keyTable[5][5]) {
    int k, i, j;
    int keyLength = strlen(key);
    int index = 0;
    char keySet[26] = {0};

    for (k = 0; k < keyLength; ++k) {
        if (key[k] != 'J') {
            if (keySet[key[k] - 'A'] == 0) {
                keySet[key[k] - 'A'] = 1;
                keyTable[index / 5][index % 5] = key[k];
                ++index;
            }
        }
    }

    for (k = 0; k < 26; ++k) {
        if (keySet[k] == 0 && k != ('J' - 'A')) {
            keyTable[index / 5][index % 5] = 'A' + k;
            ++index;
        }
    }
}

void findPositions(char keyTable[5][5], char a, char b, int* rowA, int* colA, int* rowB, int* colB) {
    int i, j;

    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            if (keyTable[i][j] == a) {
                *rowA = i;
                *colA = j;
            }
            if (keyTable[i][j] == b) {
                *rowB = i;
                *colB = j;
            }
        }
    }
}

void playfairDecrypt(char keyTable[5][5], char ciphertext[]) {
    int i, rowA, colA, rowB, colB;

    for (i = 0; i < strlen(ciphertext); i += 2) {
        findPositions(keyTable, ciphertext[i], ciphertext[i + 1], &rowA, &colA, &rowB, &colB);

        if (rowA == rowB) {
            
            printf("%c%c", keyTable[rowA][(colA - 1 + 5) % 5], keyTable[rowB][(colB - 1 + 5) % 5]);
        } else if (colA == colB) {
            printf("%c%c", keyTable[(rowA - 1 + 5) % 5][colA], keyTable[(rowB - 1 + 5) % 5][colB]);
        } else {
            printf("%c%c", keyTable[rowA][colB], keyTable[rowB][colA]);
        }
    }
}

int main() {
    char key[] = "PT109";
    char keyTable[5][5];
    char ciphertext[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";

    prepareKeyTable(key, keyTable);

    playfairDecrypt(keyTable, ciphertext);

    return 0;
}
