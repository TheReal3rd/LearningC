#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This array was just found from a search mostly to poke and prod it.
typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} DynamicArray;

void initArray(DynamicArray* arr, size_t initialCapacity) {
    arr->data = malloc(initialCapacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initialCapacity;
}

void insert(DynamicArray* arr, int value) {
    if (arr->size == arr->capacity) {
        size_t newCapacity = arr->capacity * 2;
        int* newData = realloc(arr->data, newCapacity * sizeof(int));
        if (!newData) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        arr->data = newData;
        arr->capacity = newCapacity;
    }
    arr->data[arr->size++] = value;
}

void freeArray(DynamicArray* arr) {
    free(arr->data);
}

DynamicArray arrayTest;

int main() {
    initArray(&arrayTest, 10);

    for(int x = 9; x != 0; x-- ) {
        insert(&arrayTest, x);
    }

    printf("%d\n", arrayTest.data[5]);
    printf("%d\n", arrayTest.size);

    printf("Array size: %d\n", sizeof(arrayTest));

    for(int x = 30; x != 0; x--) {
        insert(&arrayTest, x);
    }
    printf("Array size: %d\n", sizeof(arrayTest));
    printf("%d\n", arrayTest.size);

    for(int x = 0; x != arrayTest.size - 1; x++) {
        printf("%p\n", &arrayTest.data[x]);
    }

    return 0;
}

