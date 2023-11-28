#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void generateCipherSequence(const char *keyword, char *cipherSequence)
{
	int ch;
    int keywordLength = strlen(keyword);
    int index = 0;
    strcpy(cipherSequence, keyword);
    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (!strchr(keyword, ch)) {
            cipherSequence[keywordLength + index] = ch;
            index++;
        }
    }
    cipherSequence[ALPHABET_SIZE] = '\0';
}
void monoalphabeticEncrypt(const char *plaintext, const char *cipherSequence, char *ciphertext) {
	int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char originalChar = toupper(plaintext[i]);
            int index = originalChar - 'A';
            ciphertext[i] = islower(plaintext[i]) ? tolower(cipherSequence[index]) : cipherSequence[index];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}
void monoalphabeticDecrypt(const char *ciphertext, const char *cipherSequence, char *decryptedText) {
	int i;
    for ( i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char encryptedChar = toupper(ciphertext[i]);
            int index = strchr(cipherSequence, encryptedChar) - cipherSequence;
            decryptedText[i] = islower(ciphertext[i]) ? tolower('A' + index) : 'A' + index;
        } else {
            decryptedText[i] = ciphertext[i];
        }
    }
    decryptedText[strlen(ciphertext)] = '\0';
}
int main()
{
    const char *keyword = "CIPHER";
    char cipherSequence[ALPHABET_SIZE + 1];
    char plaintext[] = "Hello, World!";
    char ciphertext[100];
    char decryptedText[100];
    generateCipherSequence(keyword, cipherSequence);
    monoalphabeticEncrypt(plaintext, cipherSequence, ciphertext);
    printf("Encrypted: %s\n", ciphertext);
    monoalphabeticDecrypt(ciphertext, cipherSequence, decryptedText);
    printf("Decrypted: %s\n", decryptedText);
    return 0;
}
