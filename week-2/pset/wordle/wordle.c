#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_COUNT 10
#define WORD_LENGTH 5

typedef struct {
    char words[WORD_COUNT][WORD_LENGTH + 1];
} Words;

void init_words(Words* words) {
    strcpy(words->words[0], "apple");
    strcpy(words->words[1], "banana");
    strcpy(words->words[2], "cherry");
    strcpy(words->words[3], "orange");
    strcpy(words->words[4], "lemon");
    strcpy(words->words[5], "grape");
    strcpy(words->words[6], "melon");
    strcpy(words->words[7], "peach");
    strcpy(words->words[8], "pear");
    strcpy(words->words[9], "plum");
}

void init_random() {
    srand(time(NULL));
}

char* choose_word(Words words) {
    int index = rand() % WORD_COUNT;
    return words.words[index];
}

int compare_words(const char* a, const char* b) {
    int i;
    int same = 1;
    for (i = 0; i < WORD_LENGTH; i++) {
        if (a[i] == b[i]) {
            printf("\x1b[42m%c\x1b[0m", a[i]);  // Print with green background
        } else if (strchr(b, a[i]) != NULL) {
            printf("\x1b[43m%c\x1b[0m", a[i]);  // Print with yellow background
            same = 0;
        } else {
            printf("\x1b[41m%c\x1b[0m", a[i]);  // Print with red background
            same = 0;
        }
    }
    printf("\n");
    return same;
}

void play_game() {
    Words words;
    init_words(&words);

    printf("This is WORDLE50\n");

    char* word = choose_word(words);

    int i;
    for (i = 1; i <= 5; i++) {
        char guess[WORD_LENGTH + 1];
        printf("Guess %d: ", i);
        scanf("%s", guess);

        if (strlen(guess) == WORD_LENGTH) {
            if (compare_words(guess, word)) {
                printf("You Won!\n");
                return;
            }
        }

        if (i == 5) {
            printf("You Lost! The Word was: %s\n", word);
            return;
        }
    }
}

int main() {
    init_random();
    play_game();
    return 0;
}
