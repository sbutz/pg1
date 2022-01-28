#include <stdio.h>

#define SUCCESS 0

int main() {
	int s1, s2, erg;

	printf("Zahl 1: ");
	scanf("%d", &s1);
	printf("Zahl 2: ");
	scanf("%d", &s2);

	erg = s1 + s2;

	printf("Adresse von s1: %p\n", &s1);
	printf("Adresse von s2: %p\n", &s2);
	printf("Adresse von erg: %p\n", &erg);

	return SUCCESS;
}
