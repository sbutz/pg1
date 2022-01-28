#include <stdio.h>

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

#define ERROR_ILLEGAL_SELECTION 1

struct coffee {
	char *type;
	int price;
};

struct coffee sortiment[] = {
	{ "Milk Coffee", 90 },
	{ "Cappucino", 130 },
	{ "Hot Chocolate", 110 }
};

int coins[] = { 200, 100, 50, 20, 10, 5 };

int contains(int val, int* arr, int size);

int main() {
	int i, len, selection, rest;
	int amount[ARRAY_SIZE(coins)] = { 0 };
	float coin;

	printf("Angebot:\n");
	for (i = 0, len = ARRAY_SIZE(sortiment); i < len; i++) {
		printf("%i) %s: %.2f Euro\n", i, sortiment[i].type,
			(float) sortiment[i].price / 100);
	}

	printf("Bitte waehlen Sie eine Kaffesorte [0-%d]: ", len - 1);
	scanf("%d", &selection);

	if (selection < 0 || selection >= len) {
		printf("Ungueltige Auswahl.\n");
		return ERROR_ILLEGAL_SELECTION;
	}

	i = 1;
	rest = sortiment[selection].price;
	do {
		printf("Zu zahlender Restbetrag: %.2f\n", (float) rest / 100);

		printf("%d. Muenze: ", i);
		scanf("%f", &coin);

		if (contains((int) (coin * 100), coins, ARRAY_SIZE(coins))) {
			rest -= (int) (coin * 100);
			i++;
		} else {
			printf("Ungueltige Muenze\n");
		}
	} while (rest > 0);

	rest *= -1;
	i = 0;
	while (rest > 0) {
		if (rest >= coins[i]) {
			amount[i]++;
			rest -= coins[i];
		} else {
			i++;
		}
	}

	printf("Rueckgeld:");
	for (i = 0; i < ARRAY_SIZE(amount); i++) {
		if (amount[i] > 0)
			printf(" %d x %.2f", amount[i], (float) coins[i] / 100);
	}
	printf("\n");

	return 0;
}

int contains(int val, int *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] == val)
			return 1;
	}
	return 0;
}
