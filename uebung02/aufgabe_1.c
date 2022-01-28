#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define ERROR_NO_PARAMETER 1

int main(int argc, char *argv[]) {
	int width, max_width;

	if (argc < 2) {
		printf("Bitte Zahl fuer die Breite des Baums uebergeben.\n");
		return ERROR_NO_PARAMETER;
	}

	width = atoi(argv[1]);
	max_width = width * 2 + 3;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < 3; j++) {
			for (int a = 0; a <= width - i - j; a++)
				printf(" ");
			for (int a = 0; a < 1 + 2 * (j + i); a++)
				printf("*");
			printf("\n");
		}
	}
	for (int i = 0; i < width; i++) {
		printf(" ");
	}
	printf("|||");
	for (int i = 0; i < width; i++) {
		printf(" ");
	}
	printf("\n");

	return 0;
}
