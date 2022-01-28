#include <stdio.h>
#include <string.h>

#define DEBUG
#define CAPACITY 4

struct patient {
	int id;
	char vorname[30];
	#ifndef DEBUG
	char nachname[30];
	char strasse[30];
	char plz[6];
	char ort[30];
	#endif
};

void read_patient(struct patient *);
void sort_patients(struct patient *, int);
void print_patient(struct patient *);

int main() {
	int i;
	struct patient patienten[CAPACITY];

	for (i = 0; i < CAPACITY; i++) {
		read_patient(&patienten[i]);
	}
	
	sort_patients(patienten, CAPACITY);

	for (i = 0; i < CAPACITY; i++) {
		print_patient(&patienten[i]);
	}

	return 0;
}

void read_patient(struct patient *dst) {
	static int id = 0;

	dst->id = id;
	printf("Vorname: ");
	fgets(dst->vorname, 29, stdin);
	#ifndef DEBUG
	printf("Nachname: ");
	fgets(dst->nachname, 29, stdin);
	printf("Strasse: ");
	fgets(dst->strasse, 29, stdin);
	printf("PLZ: ");
	fgets(dst->plz, 5, stdin);
	printf("Ort: ");
	fgets(dst->ort, 29, stdin);
	#endif

	id++;
}

void sort_patients(struct patient *arr, int size) {
	int i;
	struct patient tmp;

	for (i = 0; i < size * size; i++) {
		if (strncmp(arr[i % size].vorname, arr[i % size + 1].vorname, 30) > 0) {
			tmp = arr[i % size];
			arr[i % size] = arr[i % size + 1];
			arr[i % size + 1] = tmp;
		}
	}
}

void print_patient(struct patient *p) {
	printf("ID: %d)\n", p->id);
	printf("Vorname: %s\n", p->vorname);
	#ifndef DEBUG
	printf("Nachname: %s\n", p->nachname);
	printf("Strasse: %s\n", p->strasse);
	printf("PLZ: %s\n", p->plz);
	printf("Ort: %s\n", p->ort);
	#endif
}
