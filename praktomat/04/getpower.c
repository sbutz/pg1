#include <stdio.h>

int main(void) {
        double result = 0.0;

        // Hier bitte den Code zum Erfragen der ganzzahligen Basis,
        // des ganzzahligen Exponenten und zur Berechnung des
        // Ergebnisses von Typ double einfügen.
		int base, exp, i;

		printf("Basis: ");
		scanf("%d", &base);
		printf("Exponent: ");
		scanf("%d", &exp);

		if (exp == 0) {
			result = 1.0;
		} else if (exp > 0) {
			result = 1.0;
			for (i = 0; i < exp; i++)
				result *= base;
		} else {
			result = 1.0;
			for (i = 0; i > exp; i--)
				result /= base;
		}

        printf("Ergebnis: %lf\n", result);
}
