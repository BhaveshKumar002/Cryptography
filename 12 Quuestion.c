#include <stdio.h>
#include <string.h>

int main() {
	int i,j,k;
    char message[] = "meet me at the usual place at ten rather than eight oclock";

    int key[2][2] = {{9, 4}, {5, 7}};

    int len = strlen(message);

    if (len % 2 != 0) {
        message[len] = 'x';
        message[len + 1] = '\0';
    }

    for (i = 0; message[i]; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - 'a' + 'A';
        }
    }

    int matrix[len / 2][2];

    for (i = 0, k = 0; i < len / 2; i++) {
        for (j = 0; j < 2; j++) {
            matrix[i][j] = message[k] - 'A';
            k++;
        }
    }

    int result[len / 2][2];
    for (i = 0; i < len / 2; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (k = 0; k < 2; k++) {
                result[i][j] += matrix[i][k] * key[k][j];
            }
            result[i][j] %= 26;
        }
    }

    printf("Encrypted message: ");
    for (i = 0; i < len / 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%c", result[i][j] + 'A');
        }
    }
    printf("\n");

    for (i = 0, k = 0; i < len / 2; i++) {
        for (j = 0; j < 2; j++) {
            matrix[i][j] = result[i][j];
        }
    }

    int det = key[0][0] * key[1][1] - key[0][1] * key[1][0];

    int detInverse;
    for (detInverse = 1; detInverse < 26; detInverse++) {
        if ((det * detInverse) % 26 == 1) {
            break;
        }
    }

    int adj[2][2] = {{key[1][1], -key[0][1]}, {-key[1][0], key[0][0]}};

    int keyInverse[2][2];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            keyInverse[i][j] = (adj[i][j] * detInverse) % 26;
            if (keyInverse[i][j] < 0) {
                keyInverse[i][j] += 26;
            }
        }
    }

    for (i = 0; i < len / 2; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (k = 0; k < 2; k++) {
                result[i][j] += matrix[i][k] * keyInverse[k][j];
            }
            result[i][j] %= 26;
        }
    }

    printf("Decrypted message: ");
    for (i = 0; i < len / 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%c", result[i][j] + 'A');
        }
    }
    printf("\n");

    return 0;
}
