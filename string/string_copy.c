#include <stdio.h>

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

char *strn_cpy (char [], char [], int);

int main() {
	char a[] = "Hello World\0";
	char b[20];

	strn_cpy(a, b, ARRAY_SIZE(a));
	a[0]='G';

	printf("a = %s\n", a);
	printf("b = %s\n", b);

	return 0;

}

char *strn_cpy(char *src, char *dst, int size) {
	int i;

	for (i = 0; i < size; i++) {
		if (src[i])
			dst[i] = src[i];
		else
			dst[i] = '\0';
	}

	return dst;
}
