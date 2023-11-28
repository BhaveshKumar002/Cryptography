#include <stdio.h>

int main() {
    char mostFrequent = 'B';
    char secondMostFrequent = 'U';
    int a, b, inverseA;
    int diff = (mostFrequent - secondMostFrequent + 26) % 26;
    for (int i = 1; i < 26; i++) {
        if ((i * diff) % 26 == 1) {
            a = i;
            break;
        }
    }
    b = (mostFrequent - 'A' - a * (secondMostFrequent - 'A') + 26) % 26;

    for (inverseA = 1; inverseA < 26; inverseA++) {
        if ((a * inverseA) % 26 == 1) {
            break;
        }
    }
    printf("Affine cipher key: a = %d, b = %d\n", a, b);
    printf("Inverse of a: %d\n", inverseA);
    return 0;
}
