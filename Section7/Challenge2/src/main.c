#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for random number generation seed

int main() {
    int randomNumber = 0;
    int numberGuess;
    time_t t;

    // Initialize random number generator
    srand((unsigned) time(&t));
    // Get the random number
    randomNumber = rand() % 21; // random number between 0 and 20


    printf("Guess the number. Only enter the number between 0 and 20: ");
    scanf("%d", &numberGuess);

    for (int i = 0; i < 5; ++i) {
        if (numberGuess < 0 || numberGuess > 20) {
            printf("The number is out of range. Please enter a number between 0 and 20: ");
        } 
        else if (numberGuess < randomNumber) {
            printf("Too low. Try again: ");
        } 
        else if (numberGuess > randomNumber) {
            printf("Too high. Try again: ");
        }
        else {
            printf("Congratulations! You guessed the number.\n");
            return 0;
        }
        scanf("%d", &numberGuess);
    }
    printf("Sorry, you've used all your attempts. The correct number was %d.\n", randomNumber);
    return 0;
}