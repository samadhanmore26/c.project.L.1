#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lower = 1, upper = 100; // range between
    int numToGuess, playerGuess, attempts = 0;

    // Initialize random seed
    srand(time(0));

    // Generate a random number between 'lower' and 'upper'
    numToGuess = (rand() % (upper - lower + 1)) + lower;

    printf("Welcome to the Guess the Number Game!\n");
    printf("I'm thinking of a number between %d and %d.\n", lower, upper);

    do {
        printf("Enter your guess: ");
        scanf("%d", &playerGuess);
        attempts++;

        if (playerGuess < numToGuess) {
            printf("Too low! Try again.\n");
        } else if (playerGuess > numToGuess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", numToGuess, attempts);
        }
    } while (playerGuess != numToGuess);

    return 0;
}
