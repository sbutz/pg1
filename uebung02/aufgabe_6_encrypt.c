#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define ERROR_INVALID_PARAMETER 1

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Uebergebe einen Verschluessungsparameter und eine "
			"Zeichenkette.\n");
		return ERROR_INVALID_PARAMETER;
	}

	int n = atoi(argv[1]);

	for (int i = 0; i < strlen(argv[2]); i++) {
		if (argv[2][i] >= 'A' && argv[2][i] <= 'Z') {
			argv[2][i] -= 'A';
			argv[2][i] = argv[2][i] + n % 26;
			argv[2][i] += 'A';
		} else if (argv[2][i] >= 'a' && argv[2][i] <= 'z') {
			argv[2][i] -= 'a';
			argv[2][i] = argv[2][i] + n % 26;
			argv[2][i] += 'a';
		}
	}

	printf("%s\n", argv[2]);

	return SUCCESS;
}
