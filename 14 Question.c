#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void encryptVigenereOTP(const char *plaintext, const int *key, char *ciphertext) {
    int length = strlen(plaintext),i;

    for (i = 0; i < length; ++i) {
        if (isupper(plaintext[i])) {
            ciphertext[i] = (char)((plaintext[i] - 'A' + key[i % length]) % 26 + 'A');
        }
        else if (islower(plaintext[i])) {
            ciphertext[i] = (char)((plaintext[i] - 'a' + key[i % length]) % 26 + 'a');
        }
        else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[length] = '\0';
}

int main() {
    const char *plaintext = "HelloWorld";
    const int key[] = {3, 19, 5, 12, 8, 16, 7, 4, 2, 21};
    int length = strlen(plaintext);
    char ciphertext[length + 1];
    encryptVigenereOTP(plaintext, key, ciphertext);
    printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for (int i = 0; i < length; ++i) {
        printf("%d ", key[i]);
    }
    printf("\n");
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
