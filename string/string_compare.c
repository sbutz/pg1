#include <stdio.h>

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

int strn_cmp(char *, char *, int);
char to_lower(char);

int main() {
	char a[] = "Max Mustermann";
	char b[] = "Max mustermann";

	printf("a = %s, b = %s, cmp = %d\n", a, b, strn_cmp(a, b, ARRAY_SIZE(a)));
	a[3] = '\0';
	printf("a = %s, b = %s, cmp = %d\n", a, b, strn_cmp(a, b, ARRAY_SIZE(a)));

	return 0;
}

int strn_cmp(char *a, char *b, int size) {
	int i;

	for (i = 0; i < size; i++) {
		if (a[i] == '\0' && b[i] == '\0')
			return 0;
		if (to_lower(a[i]) != to_lower(b[i]))
			return a > b ? 1 : -1;
	}

	return 0;
}

char to_lower(char a) {
	return (a >= 65 && a <= 90) ? (a + 32) : a;
}
