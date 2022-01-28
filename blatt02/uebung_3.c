#include <stdio.h>

int main() {
	int s1, s2, res;

	printf("Zahl 1: ");
	scanf("%d", &s1);
	printf("Zahl 2: ");
	scanf("%d", &s2);

	res = s1 + s2;

	printf("s1 = %p\n", s1);
	printf("s2 = %p\n", s2);
	printf("res = %p\n", res);

	return 0;
}
