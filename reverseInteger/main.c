#include <stdio.h>
#include <stdbool.h>

//I didn't entirely come up with this code but worked out how it does the reversal process.


int reverseNumber(int n) {
    int reversed = 0;
    int remainder;
    int sign = (n < 0) ? -1 : 1;
    n = n * sign;

    while(n != 0) {
        remainder = n % 10;
        if (reversed > (2147483647 / 10)) {
            return 0;
        }
        printf("Remainder %d\n", remainder);
        reversed = reversed * 10 + remainder;
        printf("Reversed %d\n", reversed);
        n = n / 10;
        printf("n div %d\n", n);
    }
    return reversed * sign;
}


int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reversed: %d\n", reverseNumber(num));
    return 0;
}


