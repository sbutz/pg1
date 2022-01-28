#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        if(argc != 2) {
                printf("Verwendung: getsquareroot ZAHL\n");
                return 1;
        }
        int zahl = atoi(argv[1]);

        // Hier bitte den Code zur Berechnung der Quadratwurzel einfügen
		double f1 = (zahl + 1) / 2, f2;
		do {
			f2 = f1;
			f1 = 0.5 * (f1 + (zahl / f1));
		} while ((f2 - f1) > 0.0000001d);

        printf("Ergebnis: %lf\n", f1);
        return 0;
}
