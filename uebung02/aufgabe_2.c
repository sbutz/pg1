#include <stdio.h>
#include <string.h>

#define SUCCESS 0
#define ERROR_NO_PARAMETER 1
#define ERROR_INVALID_PARAMETER 2;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Bitte uebergebe eine Zeichenkette.\n");
		return ERROR_NO_PARAMETER;
	}

	if (strlen(argv[1]) != 3) {
		printf("Bitte uebergebe eine Zeichenkette mit 3 Buchstaben.\n");
		return ERROR_INVALID_PARAMETER;
	}

	printf("%c%c%c\n", argv[1][0], argv[1][1], argv[1][2]);
	printf("%c%c%c\n", argv[1][0], argv[1][0], argv[1][1]);
	printf("%c%c%c\n", argv[1][1], argv[1][0], argv[1][2]);
	printf("%c%c%c\n", argv[1][1], argv[1][2], argv[1][0]);
	printf("%c%c%c\n", argv[1][2], argv[1][0], argv[1][1]);
	printf("%c%c%c\n", argv[1][2], argv[1][1], argv[1][0]);
	
	return 0;
}
