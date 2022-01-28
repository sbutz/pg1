#include <stdio.h>

#define PI 3.14f

int main() {
	int rad;
	double area;

	printf("Radius: ");
	scanf("%d", &rad);

	area = rad * rad * PI;
	printf("---------\n");
	printf("Flaeche: %lf\n", area);

	return 0;
}
