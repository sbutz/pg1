#include <stdio.h>

int main() {
	int num, sum;

	sum = 0;
	do {
		printf("Zahl: ");
		scanf("%d", &num);

		sum += num;
		printf("Summe: %d\n", sum);
	} while (1);

	return 0;
}
