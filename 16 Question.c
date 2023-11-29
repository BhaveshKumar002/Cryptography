#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
void countLetterFrequency(const char *text, int *frequency) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char letter = tolower(text[i]);
            frequency[letter - 'a']++;
        }
    }
}
void letterFrequencyAttack(const char *ciphertext, int topN) {
    int frequency[ALPHABET_SIZE] = {0};
    countLetterFrequency(ciphertext, frequency);
    int sortedFrequency[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        sortedFrequency[i] = frequency[i];
    }
    for (int i = 0; i < ALPHABET_SIZE - 1; i++) {
        for (int j = i + 1; j < ALPHABET_SIZE; j++) {
            if (sortedFrequency[i] < sortedFrequency[j]) {
                int temp = sortedFrequency[i];
                sortedFrequency[i] = sortedFrequency[j];
                sortedFrequency[j] = temp;
            }
        }
    }
    printf("Top %d possible plaintexts:\n", topN);
    for (int n = 0; n < topN; n++) {
        printf("%d. ", n + 1);
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                if (frequency[j] == sortedFrequency[i]) {
                    printf("%c", 'a' + j);
                    break;
                }
            }
        }
        printf("\n");
    }
}
int main() {
    const char *ciphertext = "Gur checbfr bs gur Gbgny Qvfpbirevrf vf n fhssvpvrag ceboyrz.";

    int topN = 5;

    letterFrequencyAttack(ciphertext, topN);

    return 0;
}
