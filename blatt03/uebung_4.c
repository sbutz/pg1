#include <stdio.h>
#include <string.h>

#define ERROR_NO_PARAMETER 1

int count_tok(char *, int, char *, int);

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Bitte uebergeben sie einen Suchterm und eine Zeichenkette.\n");
		return ERROR_NO_PARAMETER;
	}

	printf("Eregbnis: %d\n", count_tok(argv[2], strlen(argv[2]), argv[1],
		strlen(argv[1])));

	return 0;
}

int count_tok(char *str, int str_size, char *tok, int tok_size) {
	int i;

	if (str_size < tok_size)
		return -1;

	i = 0;
	while ((str = strstr(str, tok)) != NULL) {
		i++;
		str++;
	}
	return i;
}
