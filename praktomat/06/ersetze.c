#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Korrekter Aufruf: %s A B \"String\"\n", argv[0]);
        return 0;
    }

    // Implementierung hier einfügen
	int i, len = strlen(argv[3]);
	char result[len + 1];
	for (i = 0; i < len; i++) {
		if (argv[3][i] == argv[1][0])
			result[i] = argv[2][0];
		else
			result[i] = argv[3][i];
	}
	result[len] = '\0';

    printf("%s\n", result);
    return 0;
}
