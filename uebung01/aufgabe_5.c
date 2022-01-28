#include <stdio.h>

#define SUCCESS 0
#define ERROR_UNKNOWN_OPERATOR 1
#define ERROR_DIVISION_BY_ZERO 2

int main() {
	int a, b;
	char operator;
	double result;

	printf("Zahl 1: ");
	scanf("%d", &a);
	printf("Operator: ");
	scanf(" %c", &operator);
	printf("Zahl 2: ");
	scanf("%d", &b);

	switch(operator) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b == 0) {
			printf("Division by Zero is not allowed.\n");
			return ERROR_DIVISION_BY_ZERO;
		}
		result = a / b;
		break;
	default:
		printf("Unknown Operator.\n");
		return ERROR_UNKNOWN_OPERATOR;
	}

	printf("--------\n");
	printf("Ergebnis: %lf\n", result);

	return SUCCESS;
}
