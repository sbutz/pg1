#include <stdio.h>
#include <string.h>

#define DEBUG
#define CAPACITY 4

struct patient {
	int id;
	char vorname[30];
	char nachname[30];
	char strasse[30];
	char plz[6];
	char ort[30];
};

int main() {
	int i, j;
	struct patient tmp;
	struct patient patienten[CAPACITY];

	for (i = 0; i < CAPACITY; i++) {
		patienten[i].id = i + 1;
		printf("Vorname: ");
		fgets(patienten[i].vorname, 29, stdin);

		#ifndef DEBUG
		printf("Nachname: ");
		fgets(patienten[i].nachname, 29, stdin);
		printf("Strasse: ");
		fgets(patienten[i].strasse, 29, stdin);
		printf("PLZ: ");
		fgets(patienten[i].plz, 5, stdin);
		printf("Ort: ");
		fgets(patienten[i].ort, 29, stdin);
		#endif
	}

	
	for (i = 0; i < CAPACITY; i++) {
		for (j = 0; j < CAPACITY - 1; j++) {
			if (strncmp(patienten[j].vorname, patienten[j + 1].vorname, 30) > 0) {
				tmp = patienten[j];
				patienten[j] = patienten[j + 1];
				patienten[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < CAPACITY; i++) {
		printf("ID: %d)\n", patienten[i].id);
		printf("Vorname: %s\n", patienten[i].vorname);

		#ifndef DEBUG
		printf("Nachname: %s\n", patienten[i].nachname);
		printf("Strasse: %s\n", patienten[i].strasse);
		printf("PLZ: %s\n", patienten[i].plz);
		printf("Ort: %s\n", patienten[i].ort);
		#endif
	}

	return 0;
}
