#include <stdio.h>

int main() {
	int num, res;

	while (1) {
		printf("Zahl: ");
		scanf("%d", &num);
		res += num;
		printf("Zwischensumme: %d\n", res);
	}

	return 0;
}
