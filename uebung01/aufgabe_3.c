#include <stdio.h>
#include <math.h>

int main() {
	int a, b;
	double c;

	printf("Kathete a: ");
	scanf("%d", &a);
	printf("Kathete b: ");
	scanf("%d", &b);

	c = sqrt(a * a + b * b);
	printf("---------\n");
	printf("Hypothenuse: %.2lf\n", c);

	return 0;
}
