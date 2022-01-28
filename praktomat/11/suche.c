#include <stdio.h>
#include <string.h>

char *suche(char *, char *, unsigned int);

/*
int main() {
	printf("%s", suche("dreierleieierei", "ei", 1) ); // ergibt: eierleieierei
	printf("\n");
	printf("%s", suche("dreierleieierei", "ei", 3) ); // ergibt: eierei
	printf("\n");
	printf("%s", suche("dreierleieierei", "ei", 4) ); // ergibt: ei
	printf("\n");
	printf("%s", suche("barbara macht barbarei", "arba", 2) ); // ergibt: arbarei
	printf("\n");
	if( suche("barbara macht barbarei ", "asdf", 1) == NULL ) 
	   printf("nicht vorhanden!"); // sollte ausgegeben werden, da es nicht vorkommt
	printf("\n");
	if( suche("barbara macht barbarei ", "barba", 3) == NULL ) 
	   printf("nicht vorhanden!"); // sollte ausgegeben werden, da es nur 2-mal vorkommt
	printf("\n");
	return 0;
}
*/

char *suche(char *str, char *such, unsigned int n) {
	char *ptr;
	int i;

	ptr = strstr(str, such);
	i = 1;
	while (ptr != NULL) {
		if (i == n)
			return ptr;
		else if (i > n)
			return NULL;

		ptr = strstr(ptr + 1, such);
		i++;
	}

	return NULL;
}
