#include <stdio.h>

#define PI 3.14

int main() {
	double radius, flaeche;

	printf("Radius: ");
	scanf("%lf", &radius);

	flaeche = radius * radius * PI;
	printf("Flaeche: %lf\n", flaeche);
	
	return 0;
}
