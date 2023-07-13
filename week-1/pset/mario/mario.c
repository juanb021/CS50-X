#include <stdio.h>

int validateInput() {
    int number;
    do {
        printf("Enter a number between 1 and 8: ");
        scanf("%d", &number);
        if (number < 1 || number > 8) {
            printf("Invalid input. Please try again.\n");
        }
    } while (number < 1 || number > 8);
    return number;
}

void printPyramid(int number) {
    int i, j;
    for (i = 1; i <= number; i++) {
        for (j = 1; j <= number - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("#");
        }
        printf("  ");
        for (j = 1; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int number = validateInput();
    printPyramid(number);
    return 0;
}
