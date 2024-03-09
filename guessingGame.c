#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY 1
#define MEDIUM 2
#define HARD 3

void printGameHeader() {
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Welcome to     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Guessing Game! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");
}

void chooseDifficultyLevel(int *level) {
    printf("What difficulty level?\n");
    printf("(1) Easy (2) Medium (3) Hard\n\n");
    printf("Choose: ");
    scanf("%d", level);
}

void printVictoryOrDefeatMessage(int correct, int points) {
    printf("\n");
    if(correct) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nCongratulations! You got it right!\n");
        printf("You made %.2f points. Until next time!\n\n", points);
    } else {

        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("\nYou lost! Try again!\n\n");
    }

}

int main() {

    // Printing a beautiful game header
    printGameHeader();

    // Declaring variables that will be used later
    int guess;
    int correct;
    int level;
    int totalAttempts;

    // Defining the initial points quantity
    double points = 1000;

    // Generating a random secret number
    srand(time(0));
    int secretNumber = rand() % 100;

    // Choosing the difficulty level
    chooseDifficultyLevel(level);
    

    switch(level) {
        case EASY: 
            totalAttempts = 20;
            break;
        case MEDIUM:
            totalAttempts = 15;
            break;
        case HARD:
            totalAttempts = 6;
            break;
        default:
            printf("Invalid choice! Defaulting to Hard level.\n");
            totalAttempts = 6;
            break;    
    }

    // Main game loop
    for(int i = 1; i <= totalAttempts; i++) {

        printf("-> Attempt %d of %d\n", i, totalAttempts);

        printf("Guess a number: ");
        scanf("%d", &guess);

        // Handling negative number guesses
        if(guess < 0) {
            printf("You can't guess negative numbers\n");
            i--;
            continue;
        }

        // Checking if it was correct, higher or lower
        correct = guess == secretNumber;

        if(correct) {
            break;
        } else if(guess > secretNumber) {
            printf("\nYour guess was higher than the secret number!\n\n");
        } else {
            printf("\nYour guess was lower than the secret number!\n\n");
        }

        // Calculating the number of points
        double lostPoints = abs(guess - secretNumber) / 2.0;
        points -= lostPoints;
    }

    // Printing victory or defeat message
    printVictoryOrDefeatMessage(correct, points);

    return 0;
}
