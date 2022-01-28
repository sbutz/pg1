#include <stdio.h>

#define SUCESS 0
#define ERROR_UNKNOW_OPERATOR 1
#define ERROR_DEVISION_BY_ZERO 2

int main() {
	int a, b;
	double result;
	char operator;

	printf("Zahl 1: ");
	scanf("%d", &a);
	printf("Operator: ");
	scanf("%s", &operator);
	printf("Zahl 2: ");
	scanf("%d", &b);

	switch (operator) {
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
				printf("Es darf nicht durch 0 geteilt werden.\n");
				return ERROR_DEVISION_BY_ZERO;
			}
			result = (double) a / b;
			break;
		default:
			printf("Nicht unterstuetzter Operator: %c\n", operator);
			return ERROR_UNKNOW_OPERATOR;
	}

	printf("%d %c %d = %lf\n", a, operator, b, result);

	return 0;
}
