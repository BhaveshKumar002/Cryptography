#include <stdio.h>
#include <stdint.h>

void generateSubKeys(const uint8_t* key, uint8_t* subKey1, uint8_t* subKey2);
void encryptSDES(const uint8_t* plaintext, const uint8_t* key, const uint8_t* iv, uint8_t* ciphertext);
void decryptSDES(const uint8_t* ciphertext, const uint8_t* key, const uint8_t* iv, uint8_t* decryptedText);
void xorBlock(const uint8_t* input1, const uint8_t* input2, uint8_t* result);
void printBinary(const char* label, const uint8_t* data, size_t length);

int main() {
    uint8_t key[8] = {0x1F, 0x3D};
    uint8_t iv[8] = {0xAA};      
    uint8_t plaintext[8] = {0x01, 0x23}; 
    uint8_t ciphertext[8];
    uint8_t decryptedText[8];

    generateSubKeys(key, key + 1, key + 2);

    encryptSDES(plaintext, key, iv, ciphertext);
    printBinary("Plaintext:  ", plaintext, 2);
    printBinary("Ciphertext: ", ciphertext, 2);

    decryptSDES(ciphertext, key, iv, decryptedText);
    printBinary("Decrypted Text: ", decryptedText, 2);

    return 0;
}

void generateSubKeys(const uint8_t* key, uint8_t* subKey1, uint8_t* subKey2) {
  
}

void encryptSDES(const uint8_t* plaintext, const uint8_t* key, const uint8_t* iv, uint8_t* ciphertext) {

}

void decryptSDES(const uint8_t* ciphertext, const uint8_t* key, const uint8_t* iv, uint8_t* decryptedText) {

}

void xorBlock(const uint8_t* input1, const uint8_t* input2, uint8_t* result) {

}

void printBinary(const char* label, const uint8_t* data, size_t length) {

}
