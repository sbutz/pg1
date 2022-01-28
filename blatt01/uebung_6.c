#include <stdio.h>

int isPrime(int);

int main() {
	int num;

	printf("Zahl: ");
	scanf("%d", &num);

	if (isPrime(num))
		printf("Ist eine Primzahl\n");
	else
		printf("Ist keine Primzahl\n");
	
	return 0;
}

int isPrime(int num) {
	int i;

	if (num < 2)
		return 0;

	i = 2;
	while (i < num) {
		if (num % i == 0)
			return 0;
		i++;
	}

	return 1;
}
