#include <stdio.h>

int main() {
	char name[50] = "\0";

	printf("Name: ");
	scanf("%s", name);
	printf("Hallo %s\n", name);

	return 0;
}
