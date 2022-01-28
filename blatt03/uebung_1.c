#include <stdio.h>
#include <stdlib.h>

#define ERROR_MISSING_PARAMETER 1

void print_row(unsigned int, unsigned int);

int main(int argc, char *argv[]) {
	int i, j, center, height;

	if (argc < 2) {
		printf("Es muss die Baumbreite angegeben werden.\n");
		return ERROR_MISSING_PARAMETER;
	}

	height = atoi(argv[1]);
	center = height + 2;
	
	for (i = 0; i < height; i++) {
		for (j = 0; j < 3; j++)
			print_row(center, (i + j) * 2);
	}
	for (i = 0; i < center - 1; i++)
		printf(" ");
	printf("|||");
	for (i = 0; i < center - 1; i++)
		printf(" ");
	printf("\n");

	return 0;
}

void print_row(unsigned int center, unsigned int width) {
	int i;

	for (i = 0; i < center - width / 2; i++)
		printf(" ");
	for (i = 0; i <= width; i++)
		printf("*");
	for (i = 0; i < center - width / 2; i++)
		printf(" ");
	printf("\n");
}
