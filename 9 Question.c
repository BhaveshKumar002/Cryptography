#include <stdio.h>
#include <string.h>

void decryptPlayfair(char cipher[], char keyMatrix[5][5]) {
    int i, j,k ,p1, p2, q1, q2;
    char decryptedText[100];

    for (i = 0; i < strlen(cipher); i += 2) {

        for (j = 0; j < 5; j++) {
            for ( k = 0; k < 5; k++) {
                if (cipher[i] == keyMatrix[j][k]) {
                    p1 = j;
                    q1 = k;
                }
                if (cipher[i + 1] == keyMatrix[j][k]) {
                    p2 = j;
                    q2 = k;
                }
            }
        }

        if (p1 == p2) {
            decryptedText[i] = (q1 > 0) ? keyMatrix[p1][q1 - 1] : keyMatrix[p1][4];
            decryptedText[i + 1] = (q2 > 0) ? keyMatrix[p2][q2 - 1] : keyMatrix[p2][4];
        } else if (q1 == q2) {
        	
            decryptedText[i] = (p1 > 0) ? keyMatrix[p1 - 1][q1] : keyMatrix[4][q1];
            decryptedText[i + 1] = (p2 > 0) ? keyMatrix[p2 - 1][q2] : keyMatrix[4][q2];
        } else {

            decryptedText[i] = keyMatrix[p1][q2];
            decryptedText[i + 1] = keyMatrix[p2][q1];
        }
    }

    decryptedText[i] = '\0';

    printf("Decrypted Message:\n%s\n", decryptedText);
}

int main() {
    char cipher[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";

    char keyMatrix[5][5] = {
        {'K', 'X', 'J', 'E', 'Y'},
        {'U', 'R', 'E', 'B', 'Z'},
        {'W', 'H', 'T', 'U', 'F'},
        {'S', 'K', 'G', 'O', 'Y'},
        {'I', 'W', 'T', 'T', 'U'}
    };

    decryptPlayfair(cipher, keyMatrix);

    return 0;
}
