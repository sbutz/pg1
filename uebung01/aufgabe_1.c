#include <stdio.h>

int main() {
	char name[50];

	printf("Ihr Name: ");
	scanf("%50s", name);
	printf("Hallo %s\n", name);

	return 0;
}
