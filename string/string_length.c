#include <stdio.h>

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

int str_len(char *, int);

int main() {
	char str[] = "Hello World!";

	printf("length: %d\n", str_len(str, ARRAY_SIZE(str)));
	str[5] = '\0';
	printf("length: %d\n", str_len(str, ARRAY_SIZE(str)));

	return 0;
}

int str_len(char *str, int size) {
	int i;

	for (i = 0; i < size; i++) {
		if (str[i] == '\0')
			return i;
	}
	return i;
}
