#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int getRandint(int minValue, int maxValue) {
    return rand() % (maxValue - 1 - minValue) + minValue;
}

int numToGuess;
int numTries = 3;
bool completed = false;

int main() {
    printf("The computer has picked a number between 0-8 guess what that number is. You have 3 tries.\n\n");
    while(!completed) {
        numToGuess = getRandint(0, 8);
        printf("You have %d of guesses left.\nGuess the number: ", numTries);
        int guess;
        if(scanf("%d", &guess) != 1) {
            while ((getchar()) != '\n');// Clears the last input buffer apparently. 
            //Took a bit of digging to find a instruction that does this.
            continue;
        }
        if(guess == numToGuess) {
            printf("You've guessed correctly.\nYou win.\n");
            completed = true;
        } else {
            numTries--;
            if(numTries <= 0) {
                printf("You have ran out of tries.\nYou lose.\n");
                completed = true;
            }
        }

    }   
    return 0;
}
