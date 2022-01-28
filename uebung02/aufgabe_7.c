#include <stdio.h>
#include <string.h>

#define SUCCESS 0
#define ERROR_INVALID_PARAMETER 1

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Uebergebe einen Schluessel und einen Text.\n");
		return ERROR_INVALID_PARAMETER;
	}

	int key_len = strlen(argv[1]);
	int msg_len = strlen(argv[2]);

	for (int i = 0; i < key_len; i++) {
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') {
			argv[1][i] -= 'A';
		} else if (argv[1][i] >= 'a' && argv[1][i] <= 'z') {
			argv[1][i] -= 'a';
		}
	}

	for (int i = 0; i < msg_len; i++) {
		if (argv[2][i] >= 'A' && argv[2][i] <= 'Z') {
			argv[2][i] -= 'A';
			argv[2][i] = argv[2][i] ^ argv[1][i % key_len];
			argv[2][i] += 'A';
		} else if (argv[2][i] >= 'a' && argv[2][i] <= 'z') {
			argv[2][i] -= 'a';
			argv[2][i] = argv[2][i] ^ argv[1][i % key_len];
			argv[2][i] += 'a';
		}
	}

	printf("%s\n", argv[2]);

	return SUCCESS;
}
