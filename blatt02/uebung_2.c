#include <stdio.h>
#include <string.h>

#define ERROR_NO_PARAMETER 1;

void permute(char *, int, int);
void swap(char *, char *);

int main(int argc, char *argv[]) {
	int len, i, j;

	if (argc < 2) {
		printf("Bitte uebergeben Sie eine Zeichenkette.\n");
		return ERROR_NO_PARAMETER;
	}

	len = strlen(argv[1]);

	permute(argv[1], 0, strlen(argv[1]));

	return 0;
}

void permute(char *str, int i1, int i2) {
	char tmp;
	int i;

	if (i1 == i2) {
		printf("%s\n", str);
	} else {
		for (i = i1; i < i2; i++) {
			swap(&str[i1], &str[i]);
			permute(str, i1 + 1, i2);
			swap(&str[i1], &str[i]);
		}
	}
}

void swap(char *a, char *b) {
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
