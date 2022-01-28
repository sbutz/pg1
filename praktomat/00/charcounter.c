#include <stdio.h>
#include <string.h>

#define ERROR_NO_PARAMETER 1

int main(int argc, char *argv[]) {
	int counter[26] = {0};
	int i, len;

	if (argc < 2) {
		printf("Es muss eine Zeichenkette uebergeben werden.\n");
		return ERROR_NO_PARAMETER;
	}

	len = strlen(argv[1]);
	for (i = 0; i < len; i++) {
		if (argv[1][i] >= 65 && argv[1][i] <= 90)
			counter[argv[1][i] - 65]++;
		else if (argv[1][i] >= 97 && argv[1][i] <= 122)
			counter[argv[1][i] - 97]++;
	}

	for (i = 0; i < 26; i++) {
		if (counter[i] > 0)
			printf("%c: %d\n", 65 + i, counter[i]);
	}

	return 0;
}
