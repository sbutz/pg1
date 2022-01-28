#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_FAILED_ALLOCATION 1

int main(int argc, char *argv[]) {
    char *result = NULL;
    if (argc != 4) {
        printf("Korrekter Aufruf: %s \"string to replace\" \"replacement\""
			" \"String\"\n", argv[0]);
        return 0;
    }

    // Implementierung hier einfügen
	char *ptr, *tmp;
	int w1_len, w2_len, str_len;

	w1_len = strlen(argv[1]);
	w2_len = strlen(argv[2]);
	str_len = strlen(argv[3]);

	result = malloc(str_len * sizeof(char));
	strncpy(result, argv[3], str_len);

	ptr = strstr(result, argv[1]);
	while (ptr != NULL) {
		if (w2_len > w1_len) {
			tmp = realloc(result, str_len + (w2_len - w1_len));
			if (tmp == NULL) {
				printf("Allocation Error\n");
				return ERROR_FAILED_ALLOCATION;
			}
		}
		memmove(ptr + w2_len, ptr + w1_len, str_len - w1_len);
		strncpy(ptr, argv[2], w2_len);
		str_len += w2_len - w1_len;
		ptr = strstr(ptr + w2_len, argv[1]);
	}
	result[str_len] = '\0';

    if (result != NULL) {
        printf("%s\n", result);
    }

    free(result);
    return 0;
}
