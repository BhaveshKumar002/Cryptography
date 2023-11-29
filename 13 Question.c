#include <stdio.h>
#include <string.h>

int main() {
    int key[3][3] = {
        {6, 24, 1},
        {13, 16, 10},
        {20, 17, 15}
    };

    char plaintext[] = "HELLOHILL";

    int i,j,k,len = strlen(plaintext);

    if (len % 3 != 0) {
        int padding = 3 - (len % 3);
        for (i = 0; i < padding; i++) {
            plaintext[len + i] = 'X';
        }
        len += padding;
        plaintext[len] = '\0';
    }

    for (i = 0; i < len; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = plaintext[i] - 'a' + 'A';
        }
    }

    for (i = 0; i < len; i += 3) {
        int block[3];
        for (j = 0; j < 3; j++) {
            block[j] = plaintext[i + j] - 'A';
        }

        int result[3];
        for (j = 0; j < 3; j++) {
            result[j] = 0;
            for (k = 0; k < 3; k++) {
                result[j] += key[j][k] * block[k];
            }
            result[j] %= 26;  
        }

        for (j = 0; j < 3; j++) {
            printf("%c", result[j] + 'A');
        }
    }

    printf("\n");

    return 0;
}
