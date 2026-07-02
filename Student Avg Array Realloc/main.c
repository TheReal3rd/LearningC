#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int randint(int minValue, int maxValue) {
    return minValue + rand() % (maxValue - minValue + 1);
}

char *createName(char *dest, size_t destSize, char *list[], int size){
    dest[0] = '\0';
    // TODO make myself more familiar with strings and char relationships. 
    snprintf(dest, destSize, "%s %s",
        list[rand() % size],
        list[rand() % size]);
    
    return dest;
}

char *nameList[10] = {
    "Alice",
    "Dave",
    "Bob",
    "Ben",
    "Josh",
    "Jake",
    "David",
    "William",
    "Arthur",
    "George",
};

typedef struct {
    char name[40];
    int mathGrade;
    int englishGrade;
    int scienceGrade;
    int itGrade;
} student;

student *students;
int numberOfStudents = 20;

// I am aware this could be written so it create array after input but this was to learn how realloc works.
// Good i did as i had memory corruption issues.
// I have an exam i meant to be taking for this too. Best to pratice.
int main() {
    srand(time(NULL));
    students = malloc(numberOfStudents * sizeof(student));
    if(students == NULL) {
        return 1;
    }

    int newStudentSize;
    printf("\nHow many students do you want?:");
    if(scanf("%d", &newStudentSize) != 1) {
        while((getchar()) != '\n' );
    }

    if(newStudentSize > numberOfStudents) {
        numberOfStudents = newStudentSize;
        student *tempPointer = realloc(students, numberOfStudents * sizeof(student));
        students = tempPointer;

        if(students == NULL) {
            printf("\nFailed to resize student array.");
            return 1;
        }
    }

    int nameListSize = sizeof(nameList) / sizeof(nameList[0]);

    for(int i = 0; i != numberOfStudents; i++) {
        char srcName[40];
        createName(srcName, sizeof(srcName), nameList, nameListSize);

        strncpy(students[i].name, srcName, sizeof(students[i].name) - 1);
        
        students[i].mathGrade = randint(1, 10);
        students[i].englishGrade = randint(1, 10);
        students[i].scienceGrade = randint(1, 10);
        students[i].itGrade = randint(1, 10);
        printf("Index: %d Name: %s Math: %d English: %d Science: %d IT: %d\n", i, students[i].name, students[i].mathGrade, students[i].englishGrade,  students[i].scienceGrade, students[i].itGrade);
    }

    int mathSum = 0;
    int englishSum = 0;
    int scienceSum = 0;
    int itSum = 0;

    for(int i = 0; i != numberOfStudents; i++) {
        mathSum = mathSum + students[i].mathGrade;
        //printf("\n\nValue: %d\n\n", students[i].mathGrade);
        englishSum = englishSum + students[i].englishGrade;
        scienceSum = scienceSum + students[i].scienceGrade;
        itSum = itSum + students[i].itGrade;
    }

    //printf("\nSum : %d\n", mathSum);

    float mathAvg = ((float) mathSum) / numberOfStudents;
    float englishAvg = ((float) englishSum) / numberOfStudents;
    float scienceAvg = ((float) scienceSum) / numberOfStudents;
    float itAvg = ((float) itSum) / numberOfStudents;

    printf("\n\nMath Avg: %.2f English Avg: %.2f Science Avg: %.2f IT Avg: %.2f\n\n", mathAvg, englishAvg, scienceAvg, itAvg);

    free(students);
    students = NULL;
    return 0;
}
