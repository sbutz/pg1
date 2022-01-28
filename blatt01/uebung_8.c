#include <stdio.h>
#include <math.h>

#define ERROR_ILLEGAL_INPUT 1

int main() {
	int credit = 100000, type, years, installment;
	float interest;

	printf("Annuitaeten oder Ratenzahlung? [0,1]: ");
	scanf("%d", &type);

	if (type != 0 && type != 1) {
		printf("Ungueltige Eingabe\n");
		return ERROR_ILLEGAL_INPUT;
	}

	printf("Zinssatz: [%]");
	scanf("%f", &interest);

	printf("Ratenhoehe: ");
	scanf("%d", &installment);

	if (type == 0) {
		interest = credit * interest / 100;
		years = ceil((double) (interest + credit) / (installment));
	} else {
		years = 0;
		while (credit > 0) {
			credit = credit - (installment - (credit * interest / 100));
			years++;
		}
	}

	printf("Sie brauchen %d Jahre um ihren Kredit abzuzahlen\n", years);

	return 0;
}
