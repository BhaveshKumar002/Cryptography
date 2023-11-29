#include <stdio.h>
#include <string.h>

int main() {
    char ciphertext[1000]; 
	int key,i;
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    int len = strlen(ciphertext);

    for (key = 1; key <= 26; key++) {
        printf("\nKey %d:\n", key);
        
        for (i = 0; i < len; i++) {
            char currentChar = ciphertext[i];

            if (currentChar >= 'A' && currentChar <= 'Z') {
                char decryptedChar = currentChar - key;

                while (decryptedChar < 'A') {
                    decryptedChar += 26;
                }

                printf("%c", decryptedChar);
            } else {
              
                printf("%c", currentChar);
            }
        }

        printf("\n");
    }

    return 0;
}
