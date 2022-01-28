#include <stdio.h>

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

#define SUCCESS 0
#define ERROR_UNGUELTIGE_AUSWAHL 1

typedef struct {
	char *name;
	int preis;
} Kaffesorte;

int array_contains(int [], int, int);

Kaffesorte sortiment[] = {
	{ "Milchkaffee", 100 },
	{ "Espresso", 70 },
	{ "Capuccino", 140 },
};

int muenzen[] = { 200, 100, 50, 20, 10, 5 };

int main() {
	int auswahl, restbetrag;
	float muenze;

	printf("Kaffesorte [ ");
	for (int i = 0; i < ARRAY_SIZE(sortiment); i++) {
		printf("%s=%d ", sortiment[i].name, i);
	}
	printf("]: ");
	scanf("%d", &auswahl);

	if (auswahl < 0 || auswahl >= ARRAY_SIZE(sortiment)) {
		printf("Ungueltige Auswahl.\n");
		return ERROR_UNGUELTIGE_AUSWAHL;
	}

	printf("Preis: %.2f Euro\n", (float) sortiment[auswahl].preis / 100);

	restbetrag = sortiment[auswahl].preis;
	while (restbetrag > 0.0000001f) {
		printf("Muenzeinwurf: ");
		scanf("%f", &muenze);
		muenze = (int) (muenze * 100);
		if (array_contains(muenzen, ARRAY_SIZE(muenzen), muenze)) {
			restbetrag -= muenze;
		} else {
			printf("Ungueltige Muenze.\n");
		}
		printf("Restbetrag: %.2f\n", (float) restbetrag / 100);
	}


	printf("Rueckgeld: ");
	restbetrag *= -1;
	for (int i = 0; i < ARRAY_SIZE(muenzen); i++) {
		printf("%d x %.2f ", restbetrag / muenzen[i], (float) muenzen[i] / 100);
		restbetrag %= muenzen[i];
	}
	printf("\n");

	return SUCCESS;
}

int array_contains(int arr[], int size, int element) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == element)
			return 1;
	}
	return 0;
}
