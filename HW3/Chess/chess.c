#include <stdio.h>
#include <stdlib.h> // needed for abs

enum Figure {
    KING = 1,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT
};

const char *figures[5] = {
    "King", "Queen", "Rook", "Bishop", "Knight"
};

int check_king(int delta_letter, int delta_digit) {
    return delta_letter <= 1 && delta_digit <= 1;
}

int check_rook(int delta_letter, int delta_digit) {
    return delta_letter == 0 || delta_digit == 0;
}

int check_bishop(int delta_letter, int delta_digit) {
    return delta_letter == delta_digit;
}

int check_knight(int delta_letter, int delta_digit) {
    return (delta_letter == 2 && delta_digit == 1) || (delta_letter == 1 && delta_digit == 2);
}

int analyze(enum Figure f, int delta_letter, int delta_digit) {
    int possible = 0;

    switch (f) {
        case KING:
            possible = check_king(delta_letter, delta_digit);
            break;

        case QUEEN:
            possible = check_rook(delta_letter, delta_digit) || check_bishop(delta_letter, delta_digit);
            break;

        case ROOK:
            possible = check_rook(delta_letter, delta_digit);
            break;

        case BISHOP:
            possible = check_bishop(delta_letter, delta_digit);
            break;

        case KNIGHT:
            possible = check_knight(delta_letter, delta_digit);
            break;

        default:
            // never should be reached
            printf("Error: no such figure\n");
            break;
    }
    
    return possible;
}

int main() {
    enum Figure f;
    int fig = 0, start_digit, end_digit;
    char start_letter, end_letter;

    printf("Choose figure (1-King, 2-Queen, 3-Rook, 4-Bishop, 5-Knight): ");
    scanf("%d", &fig);
    if (fig < KING || KNIGHT < fig) {
        printf("Error: no such figure\n");
        return 1;
    }
    f = (enum Figure)fig;

    printf("Enter current position (a1-h8): ");
    scanf(" %c%d", &start_letter, &start_digit);
    if (start_letter < 'a' || 'h' < start_letter || 
        start_digit < 1 || 8 < start_digit) {
        printf("Error: wrong position\n");
        return 1;
    }

    printf("Enter next position (a1-h8): ");
    scanf(" %c%d", &end_letter, &end_digit);
    if (end_letter < 'a' || 'h' < end_letter || 
        end_digit < 1 || 8 < end_digit) {
        printf("Error: wrong position\n");
        return 1;
    }

    if (start_letter == end_letter && start_digit == end_digit) {
        printf("same position\n");
        return 0;
    }

    if (analyze(f, abs(end_letter-start_letter), abs(end_digit-start_digit))) {
        printf("Move is allowed\n");
    } else {
        printf("Move is NOT allowed\n");
        for (enum Figure s = KING; s <= KNIGHT; s++) {
            if (analyze(s, abs(end_letter-start_letter), abs(end_digit-start_digit))) {
                printf("This move is allowed for %s\n", figures[s-1]);
            }
        }
    }

    return 0;
}