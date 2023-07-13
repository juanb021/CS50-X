#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void caesar(char* text, int key) {
    int length = strlen(text);
    int i;
    for (i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int offset = text[i] - base;
            int shifted_offset = (offset + key) % 26;
            text[i] = base + shifted_offset;
        }
    }
}

int main(int argc, char* argv[]) {
    // Verify the length of the command-line.
    if (argc != 2) {
        fprintf(stderr, "USAGE: ./caesar KEY\n");
        return 1;
    }

    // Verify that the key is a numeric value.
    int key;
    if (sscanf(argv[1], "%d", &key) != 1) {
        fprintf(stderr, "USAGE: ./caesar KEY\n");
        return 1;
    }

    char plaintext[1000];
    printf("Text: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    caesar(plaintext, key);

    printf("Ciphertext: %s\n", plaintext);

    return 0;
}
