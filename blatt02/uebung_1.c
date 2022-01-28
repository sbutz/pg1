#include <stdio.h>
#include <stdlib.h>

#define ERROR_MISSING_PARAMETER 1

int main(int argc, char *argv[]) {
	int i, j, k, stars, max_width, height;

	if (argc < 2) {
		printf("Es muss die Baumbreite angegeben werden.\n");
		return ERROR_MISSING_PARAMETER;
	}

	height = atoi(argv[1]);
	max_width = height * 2 + 3;

	for (i = 0; i < height; i++) {
		for (j = 0; j < 3; j++) {
			stars = 1 + (i + j) * 2;
			for (k = 0; k < (max_width - stars) / 2; k++)
				printf(" ");
			for (k = 0; k < stars; k++)
				printf("*");
			for (k = 0; k < (max_width - stars) / 2; k++)
				printf(" ");
			printf("\n");
		}
	}

	for (k = 0; k < (max_width - 3) / 2; k++)
		printf(" ");
	printf("|||");
	for (k = 0; k < (max_width - 3) / 2; k++)
		printf(" ");
	printf("\n");

	return 0;
}
