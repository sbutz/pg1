#include <stdio.h>
#include <math.h>

#define SUCCESS 0
#define ERROR_UNBEKANNTER_KREDIT 1

#define KREDIT_ANUALITAET 0
#define KREDIT_RATE 1

int main() {
	int kredit, kredit_typ, rate, restdauer;
	double zinssatz;

	kredit = 100000;

	printf("Kredittyp: [Anulaitaet = %d, Rate = %d]: ", KREDIT_ANUALITAET, KREDIT_RATE);
	scanf("%d", &kredit_typ);

	printf("Zinssatz: ");
	scanf("%lf", &zinssatz);

	printf("Maximale Montaliche Rate: ");
	scanf("%d", &rate);

	switch(kredit_typ) {
	case KREDIT_ANUALITAET:
		restdauer = ceil((double) (kredit + kredit * zinssatz) / rate / 12);
		break;
	case KREDIT_RATE:
		restdauer = 0;
		while (kredit > 0) {
			kredit -= rate - (kredit * zinssatz);
			restdauer++;
		}
		restdauer = ceil((double) restdauer / 12);
		break;
	default:
		printf("Unbekannter Kredit.\n");
		return ERROR_UNBEKANNTER_KREDIT;
	}

	printf("Restdauer: %d Jahre\n", restdauer);
	
	return SUCCESS;
}
