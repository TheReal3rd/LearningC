#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool closing = false;
bool finishedPrimes = false;

int *primeArray;
// So the prime numbers with memory alloc to create a list of prime numbers to then search through.
int main() {
    int primeRange;
    int currentIndex = 0;
    size_t arraySize = 5;
    while(!closing) {
        if (!finishedPrimes) {
            printf("Please enter a number to calculate a list of prime numbers: ");
            scanf("%d", &primeRange);
            primeArray = malloc(arraySize * sizeof(int));

            for(int x = primeRange; x != 0; x--){
                if(x <= 1) {
                    break;
                }

                bool prime = true;
                for(int i = 2; i != (int) sqrt(x) + 1; i++) {
                    if(x % i == 0) {
                        prime = false;
                        continue;
                    }
                }
                if(prime) {
                    primeArray[currentIndex] = x;
                    currentIndex++;
                    printf("%d\n", x);
                    
                    if (currentIndex >= arraySize - 1){
                        size_t newSize = arraySize * 2;
                        arraySize = newSize;
                        int* tempArray = realloc(primeArray, newSize * sizeof(int));
                        primeArray = tempArray;
                        printf("Array expanded by: %d", newSize);
                    }
                }
            }
            finishedPrimes = true;
        } else {
            int searchIndex;
            printf("Size: %d Index: %d\n", arraySize, currentIndex);
            printf("Enter index to get the value: \n");
            scanf("%d", &searchIndex);
            if(searchIndex == -10) {
                closing = true;
                break;
            }

            if(searchIndex < 0 && searchIndex > arraySize) {
                printf("Index provided is either too small or too large.\n\n");
                continue;
            }

            printf("The value is: %d\n", primeArray[searchIndex]);
        }


    }

    return 0;
}