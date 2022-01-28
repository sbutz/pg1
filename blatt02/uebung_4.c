#include <stdio.h>

int main() {
	int i;
	int *ptr;

	printf("i = %p\n", &i);

	for (i = 0, ptr = &i; i < 200; i++, ptr -= 32) {
		printf("%p: %x\n", ptr, *ptr);
	}

	return 0;
}
