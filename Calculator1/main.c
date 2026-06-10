#include <stdio.h>
#include <stdbool.h>

int opNum;
int numTwo;
int numOne;
bool closing = false;

int main() {
    printf("Hello Calculator\n");
    while(!closing) {
	printf("Enter you operation: 0 = ADD, 1 = Subtract,  2 = Multiply & 3 = Division");
    	scanf("%d", &opNum);
    	printf("Enter the first value: ");
	scanf("%d", &numOne);
	printf("Enter the second value: ");
	scanf("%d", &numTwo);
	switch(opNum) {
	    case 0:
		printf("%d + %d = %d ", numOne, numTwo, numOne + numTwo);
		break;
	    case 1:
		printf("%d - %d = %d ", numOne, numTwo, numOne - numTwo);
		break;
	    case 2:
		printf("%d * %d = %d ", numOne, numTwo, numOne * numTwo);
		break;
	    case 3:
		printf("%d / %d = %d", numOne, numTwo, numOne / numTwo);
		break;
    	}
    }
    return 0;
}



