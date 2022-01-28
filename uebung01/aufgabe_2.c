#include <stdio.h>

int main() {
	int length, height, area;

	printf("Laenge: ");
	scanf("%d", &length);
	printf("Hoehe: ");
	scanf("%d", &height);

	printf("------------\n");
	area = height * length;
	printf("Flaeche: %d\n", area);

	return 0;
}
