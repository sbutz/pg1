#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char *buf;
	int len;

	len = 0;
	do {
		buf = realloc(buf, sizeof(char) * 80 - len % 80);
		fgets(&buf[len], 80, stdin);
		len = strnlen(buf, len + 80);
	} while (strncmp(&buf[len - 5], "ENDE\n", 5) != 0);

	printf("\n");
	printf("len: %d\n", len);
	printf("%s", buf);

	free(buf);
	
	return 0;
}
