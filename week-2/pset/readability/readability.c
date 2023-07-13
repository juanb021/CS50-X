#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count_letters(const char* text) {
    int letters = 0;
    int length = strlen(text);
    int i;

    for (i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            letters++;
        }
    }

    return letters;
}

int count_words(const char* text) {
    int words = 1;
    int length = strlen(text);
    int i;

    for (i = 0; i < length; i++) {
        if (text[i] == ' ') {
            words++;
        }
    }

    return words;
}

int count_sentences(const char* text) {
    int sentences = 0;
    int length = strlen(text);
    int i;

    for (i = 0; i < length; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences++;
        }
    }

    return sentences;
}

float calculate_index(int letters, int words, int sentences) {
    float index = 0.0588 * (letters * 100.0 / words) - 0.296 * (sentences * 100.0 / words) - 15.8;
    return index;
}

int main() {
    char text[1000];
    printf("Insert the text to evaluate: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float index = calculate_index(letters, words, sentences);

    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade: %.0f\n", index);
    }

    return 0;
}
