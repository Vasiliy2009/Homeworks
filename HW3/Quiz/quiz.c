#include <stdio.h>
#include <stdlib.h> // needed for rand

#define LOWBOUND 1
#define HIGHBOUND 1000

int mode1() {
    int tries = 0, val = 0, min = LOWBOUND, max = HIGHBOUND, thinking = 1;

    srand(time(NULL));
    val = min + rand() % (max - min + 1);
    printf("Guess one number from %d to %d: ", min, max);
    while (thinking) {
        int guess = 0;
        tries++;
        scanf(" %d", &guess);
        if (guess > val) {
            printf("The chosen number is less. Try again: ");
        } else if (guess < val) {
            printf("The chosen number is more. Try again: ");
        } else {
            printf("You're right\n");
            thinking = 0;
        }
    }

    return tries;
}

int mode2() {
    int tries = 0, val = 0, min = LOWBOUND, max = HIGHBOUND, thinking = 1;

    while (thinking) {
        char response;
        tries++;
        val = min + (max - min)/2;
        printf("Your number is %d? (>, <, =): ", val);
        scanf(" %c", &response);
        if (response == '>') {
            min = val + 1;
        } else if (response == '<') {
            max = val - 1;
        } else {
            printf("I guessed\n");
            thinking = 0;
        }
    }

    return tries;
}

int main() {
    int choice = 0;

    printf("Choose mode (1-You guess, 2-I guess): ");
    scanf("%d", &choice);
    if (choice != 1 && choice != 2) {
        printf("Error: wrong mode\n");
        return 1;
    }

    if (choice == 1) {
        printf("You guessed number in %d steps\n", mode1());
    } else {
        printf("I spent %d steps\n", mode2());
    }

    return 0;
}