#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0

#define BUF_SIZE 81

int main() {
	char buf[BUF_SIZE];
	char *text = NULL, *tmp = NULL;
	int size = 0, len;

	do {
		fgets(buf, BUF_SIZE, stdin);
		len = strnlen(buf, BUF_SIZE);

		tmp = realloc(text, (size+len) * sizeof(char));
		if (tmp == NULL) {
			printf("Fehler bei der Speicherreservierung.\n");
			break;
		}
		text = tmp;

		strncpy(&text[size], buf, len);
		size += len;
	} while (strncmp(buf, "ENDE\n", BUF_SIZE) != 0);

	printf("len = %ld\n", strlen(text));
	printf("%s", text);
	free(text);

	return SUCCESS;
}
