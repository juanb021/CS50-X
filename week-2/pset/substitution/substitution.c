#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void substitution(char* text, const char* key) {
    char replace_dict[ALPHABET_SIZE];
    int i;

    // Create the replacement dictionary.
    for (i = 0; i < ALPHABET_SIZE; i++) {
        replace_dict[i] = key[i];
    }

    int length = strlen(text);
    for (i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            char c = tolower(text[i]);
            int index = c - 'a';
            text[i] = isupper(text[i]) ? toupper(replace_dict[index]) : replace_dict[index];
        }
    }
}

int validate_key(const char* key) {
    // Verify that the key contains 26 letters, each letter a single time.
    int i;
    int counts[ALPHABET_SIZE] = {0};
    int length = strlen(key);

    if (length != ALPHABET_SIZE) {
        fprintf(stderr, "Key must contain 26 characters.\n");
        return 0;
    }

    for (i = 0; i < length; i++) {
        char c = tolower(key[i]);
        if (!isalpha(c)) {
            fprintf(stderr, "Key must contain 26 letters.\n");
            return 0;
        }

        int index = c - 'a';
        if (counts[index] > 0) {
            fprintf(stderr, "Key cannot contain repeated letters.\n");
            return 0;
        }
        counts[index]++;
    }

    return 1;
}

int main(int argc, char* argv[]) {
    // Verify the length of the command-line.
    if (argc != 2) {
        fprintf(stderr, "USAGE: ./substitution KEY\n");
        return 1;
    }

    const char* key = argv[1];
    if (!validate_key(key)) {
        return 1;
    }

    char plaintext[1000];
    printf("Message: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    substitution(plaintext, key);

    printf("Ciphertext: %s\n", plaintext);

    return 0;
}
