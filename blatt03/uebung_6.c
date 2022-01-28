#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINES 1

struct kv_pair {
	char *key;
	int key_size;
	char *value;
	int value_size;
};

struct kv_pair *str_to_kv(char *, int);
void print_kv(struct kv_pair *);
void free_kv(struct kv_pair *);

int main() {
	struct kv_pair *pairs[LINES];
	int i;
	char buf[512];

	for (i = 0; i < LINES; i++) {
		fgets(buf, 511, stdin);

		pairs[i] = str_to_kv(buf, strlen(buf));
	}

	for (i = 0; i < LINES; i++) {
		print_kv(pairs[i]);
		free_kv(pairs[i]);
	}

	return 0;
}

struct kv_pair *str_to_kv(char *str, int size) {
	struct kv_pair *p;
	int i;

	i = 0;
	while (str[i] != '=' && i < size && str[i] != '\0') {
		i++;
	}

	p = malloc(sizeof(struct kv_pair) * 1);
	if (p == NULL) {
		printf("Failed to allocate memory.\n");
		exit(1);
	}

	p->key = malloc(sizeof(char) * (i + 1));
	strncpy(p->key, str, i);
	p->key[i] = '\0';
	p->key_size = i + 1;

	p->value = malloc(sizeof(char) * (size - i - 1));
	strncpy(p->value, str + i + 1, size - i - 2);
	p->value[size] = '\0';
	p->value_size = size - i - 1;

	return p;
}

void print_kv(struct kv_pair *p) {
	printf("%s=%s\n", p->key, p->value);
}

void free_kv(struct kv_pair *p) {
	free(p->key);
	free(p->value);
	free(p);
}
