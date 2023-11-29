#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') {
        ch = 'I'; 
    }

    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (matrix[*row][*col] == ch) {
                return;
            }
        }
    }
}

void encryptPair(char matrix[SIZE][SIZE], char a, char b) {
    int row1, col1, row2, col2;
    findPosition(matrix, a, &row1, &col1);
    findPosition(matrix, b, &row2, &col2);

    if (row1 == row2) {
        col1 = (col1 + 1) % SIZE;
        col2 = (col2 + 1) % SIZE;
    }

    else if (col1 == col2) {
        row1 = (row1 + 1) % SIZE;
        row2 = (row2 + 1) % SIZE;
    }

    else {
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }

    printf("%c%c%c%c", matrix[row1][col1], matrix[row2][col2], matrix[row1][col2], matrix[row2][col1]);
}

void playfairEncrypt(char matrix[SIZE][SIZE], char *message) {
    int len = strlen(message);
    for (int i = 0; i < len; i += 2) {
        char a = toupper(message[i]);
        char b = (i + 1 < len) ? toupper(message[i + 1]) : 'X';
        encryptPair(matrix, a, b);
    }
}

int main() {

    char matrix[SIZE][SIZE] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };

    char message[] = "Must see you over Cadogan West. Coming at once";

    playfairEncrypt(matrix, message);

    return 0;
}
