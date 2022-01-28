#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c;

	printf("Kathete a: ");
	scanf("%lf", &a);
	printf("Kathete b: ");
	scanf("%lf", &b);

	c = sqrt((a * a) + (b * b));
	printf("Hypothenuse: %lf\n", c);

	return 0;
}
