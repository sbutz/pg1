#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_INVALID_PARAMETER 1

void encrypt(char *, int, int);
void decrypt(char *, int, int);

int main(int argc, char *argv[]) {
	int n;

	if (argc < 3) {
		printf("Sie muessen die Verschiebungsgroesse und eine Zeichenkette "
			"uebergeben.\n");
		return ERROR_INVALID_PARAMETER;
	}

	n = atoi(argv[1]);
	n = (n < 0) ? 26 + (n % 26) : n % 26;

	encrypt(argv[2], strlen(argv[2]), n);
	printf("Verschuesselter Text: %s\n", argv[2]);

	decrypt(argv[2], strlen(argv[2]), n);
	printf("Entschuesselter Text: %s\n", argv[2]);

	return 0;
}

void encrypt(char *str, int size, int n) {
	int i;

	for (i = 0; i < size; i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			str[i] = ((str[i] - 65 + n) % 26) + 65;
		} else if (str[i] >= 97 && str[i] <= 122) {
			str[i] = ((str[i] - 97 + n) % 26) + 97;
		}
	}
}

void decrypt(char *str, int size, int n) {
	encrypt(str, size, -n);
}
