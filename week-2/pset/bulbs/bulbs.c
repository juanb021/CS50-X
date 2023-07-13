#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_binary(const char* text, char** binary_values, int* num_values) {
    int length = strlen(text);
    int i;

    for (i = 0; i < length; i++) {
        int ascii_value = text[i];
        char binary[9];
        int j;

        // Convert the ASCII value to binary.
        for (j = 7; j >= 0; j--) {
            binary[j] = (ascii_value % 2) + '0';
            ascii_value /= 2;
        }
        binary[8] = '\0';

        // Store the binary value in the array.
        binary_values[i] = strdup(binary);
    }

    *num_values = length;
}

char* print_bulbs(const char* binary) {
    char* bulbs = malloc((strlen(binary) * 2 + 1) * sizeof(char));
    int i;

    // If the number is 1, replace it with a 🟡 emoji, otherwise replace it with a ⚫ emoji.
    for (i = 0; binary[i] != '\0'; i++) {
        if (binary[i] == '1') {
            strcat(bulbs, "🟡");
        } else {
            strcat(bulbs, "⚫");
        }
    }

    return bulbs;
}

void main() {
    char text[1000];
    printf("Message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    char* binary_values[1000];
    int num_values;

    convert_binary(text, binary_values, &num_values);

    int i;
    for (i = 0; i < num_values; i++) {
        char* bulbs = print_bulbs(binary_values[i]);
        printf("%s\n", bulbs);
        free(bulbs);
        free(binary_values[i]);
    }
}
