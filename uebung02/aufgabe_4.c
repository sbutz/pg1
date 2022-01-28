#include <stdio.h>

int main() {
	int *i;

	for (int j = 0; j < 200; j++) {
		int *x = i - (j * 4);
		printf("Adresse: %p, Inhalt: %x\n", x, *x);
	}
	return 0;
}
