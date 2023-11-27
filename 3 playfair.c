#include <stdio.h>
#include <string.h>

int main() {
    char key[25], keyTable[5][5], text[100], cipher[100];
    int dicty[26] = {0}, k = 0;

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the text: ");
    scanf("%s", text);

    for (; *key;)
        if (*key != 'j' && !dicty[*key - 'a'])
            dicty[*key++ - 'a'] = 1, keyTable[k / 5][k % 5] = *(key - 1);

    for (char i = 'a'; i <= 'z';)
        if (i != 'j' && !dicty[i - 'a'])
            keyTable[k / 5][k % 5] = i, i++, k++;

    k = 0;

    for (; *text; text += 2)
        if (*text != *(text + 1))
            for (char r = 0; r < 5; r++)
                for (char c = 0; c < 5;)
                    if (keyTable[r][c] == *text)
                        cipher[k++] = keyTable[r][++c % 5],
                        cipher[k++] = keyTable[r][*(text + 1) - 'a'];
                    else if (keyTable[r][c] == *(text + 1))
                        cipher[k++] = keyTable[r][*text - 'a'],
                        cipher[k++] = keyTable[r][++c % 5];

    cipher[k] = '\0';

    printf("Cipher: %s\n", cipher);

    return 0;
}
