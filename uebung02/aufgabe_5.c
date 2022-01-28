#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

#define BUF_SIZE 32


typedef struct {
	int id;
	char name[BUF_SIZE];
	char vorname[BUF_SIZE];
	char strasse[BUF_SIZE];
	int plz;
	char ort[BUF_SIZE];
} Patient;

void read_patient(Patient *);
void print_patient(Patient *);


int main() {
	Patient patienten[4];

	for (int i = 0; i < ARRAY_SIZE(patienten); i++) {
		patienten[i].id = i + 1;
		read_patient(&patienten[i]);
	}

	for (int i = 0; i < ARRAY_SIZE(patienten); i++) {
		for (int j = 0; j < ARRAY_SIZE(patienten) - 1; j++) {
			if (strncmp(patienten[j].name, patienten[j+1].name, BUF_SIZE) > 0) {
				Patient tmp;
				memcpy(&tmp, &patienten[j], sizeof(Patient));
				memcpy(&patienten[j], &patienten[j+1], sizeof(Patient));
				memcpy(&patienten[j+1], &tmp, sizeof(Patient));
			}
		}
	}

	for (int i = 0; i < ARRAY_SIZE(patienten); i++)
		print_patient(&patienten[i]);
	
	return 0;
}

void read_patient(Patient *p) {
	printf("Name: ");
	fgets(p->name, BUF_SIZE, stdin);

	return;
	printf("Vorname: ");
	fgets(p->vorname, BUF_SIZE, stdin);

	printf("Strasse: ");
	fgets(p->strasse, BUF_SIZE, stdin);

	printf("PLZ: ");
	scanf("%d", &p->plz);

	printf("Ort: ");
	fgets(p->ort, BUF_SIZE, stdin);
}

void print_patient(Patient *p) {
	printf("{ ");
	printf("Id: %d, ", p->id);
	printf("Name: %s, ", p->name);
	printf("Vorname: %s, ", p->vorname);
	printf("Strasse: %s, ", p->strasse);
	printf("PLZ: %d, ", p->plz);
	printf("Ort: %s", p->ort);
	printf(" }\n");
}
