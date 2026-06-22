#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bool.h>

int *unSortedArr;
int *sortedArr;
int size = 10;

int getRandom(int minValue, int maxValue) {
    return rand() % (maxValue - 1 - minValue) + minValue;
}

int main() {
    srand(time(NULL));
    
    printf("Please enter the size of random number list: ");
    scanf("%d", &size);
    unSortedArr = malloc(size * sizeof(int));
    printf("Unsorted array: \n");
    for(int i = 0; i != size - 1; i++) {
        unSortedArr[i] = getRandom(0, 10);
        printf("%d\n", unSortedArr[i]);
    }
    sortedArr = malloc(size * sizeof(int));
    int lowestValue = 0;
    int in = 0;
    bool sorted = false;
    while(!sorted) {
        int temp = unSortedArr[in];
        if(temp < lowestValue) {
            lowestValue = temp;
        }
        //TODO not done
        
        in++;
        if(in >= size) {
            in = 0;
        }
    }
    
    
    free(unSortedArr);
    free(sortedArr);
    unSortedArr = NULL;
    sortedArr = NULL;
    return 0;
}
