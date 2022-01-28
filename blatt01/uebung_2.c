#include <stdio.h>

int main() {
	int laenge, breite, flaeche;

	printf("Laenge: ");
	scanf("%d", &laenge);
	printf("Breite: ");
	scanf("%d", &breite);

	flaeche = laenge * breite;
	printf("Flaeche: %d\n", flaeche);

	return 0;
}
