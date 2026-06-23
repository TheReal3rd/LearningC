#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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
        unSortedArr[i] = getRandom(10, 100);
        printf("%d\n", unSortedArr[i]);
    }
    sortedArr = malloc(size * sizeof(int));
    int lowestValue = 99999;
    int in = 0;
	int indexShift = 0;
    bool sorted = false;
    while(!sorted) {
        int temp = unSortedArr[in];
		printf("temp: %d\n", temp);
        if(temp < lowestValue) {
            lowestValue = temp;
        }
        
        if(in >= size) {
			printf("Set sorted %d in %d\n", lowestValue, indexShift);
			sortedArr[indexShift] = lowestValue;
			lowestValue = 99999;
			indexShift++;
			in = indexShift;
			if(indexShift >= size) {
				sorted = true;
			}
        } else {
			in++;
		}
		printf("index pos %d %d\n",in, indexShift);
    }
    
	printf("\n\nSorted list now:\n");
	for(int i = 0; i != size; i++) {
		printf("%d\n", sortedArr[i]);
	}
    
    free(unSortedArr);
    free(sortedArr);
    unSortedArr = NULL;
    sortedArr = NULL;
    return 0;
}
