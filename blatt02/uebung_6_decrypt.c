#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_INVALID_PARAMETER 1

int main(int argc, char *argv[]) {
	int i, n, len;

	if (argc < 3) {
		printf("Sie muessen die Verschiebungsgroesse und eine Zeichenkette "
			"uebergeben.\n");
		return ERROR_INVALID_PARAMETER;
	}

	n = atoi(argv[1]);
	n = (n < 0) ? 26 + (n % 26) : n % 26;
	len = strlen(argv[2]);

	for (i = 0; i < len; i++) {
		if (argv[2][i] >= 65 && argv[2][i] <= 90) {
			argv[2][i] = ((argv[2][i] - 65 - n) % 26) + 65;
		} else if (argv[2][i] >= 97 && argv[2][i] <= 122) {
			argv[2][i] = ((argv[2][i] - 97 - n) % 26) + 97;
		}
	}

	printf("%s\n", argv[2]);

	return 0;
}
