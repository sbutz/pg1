#include <stdio.h>

int is_prime(int);

int main() {
	int num;

	printf("Zahl: ");
	scanf("%d", &num);

	if (is_prime(num))
		printf("Ist eine Primzahl.\n");
	else
		printf("Ist keine Primzahl.\n");

	return 0;
}

int is_prime(int num) {
	int i;

	i = 2;
	while (i < num) {
		if (num % i == 0)
			return 0;
		else
			i++;
	}

	return 1;
}
