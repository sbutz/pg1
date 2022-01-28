#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void say_short_number(int, char*);

void say_long_number(long, char*);

char *EINER[] = {
	"eins",
	"zwei",
	"drei",
	"vier",
	"fuenf",
	"sechs",
	"sieben",
	"acht",
	"neun",
	"zehn",
	"elf",
	"zwoelf",
	"dreizehn",
	"vierzehn",
	"fuenfzehn",
	"sechzehen",
	"siebzehn",
	"achtzehn",
	"neunzehn",
};
char *ZEHNER[] = {
	"zehn",
	"zwanzig",
	"dreissig",
	"vierzig",
	"fuenfzig",
	"sechzig",
	"siebzig",
	"achtzig",
	"neunzig",
};

int main(int argc, char *argv[]) {
	char *buf;
	long num;

	if (argc < 2) {
		printf("No number specified.\n");
		return 1;
	}

	num = strtol(argv[1], NULL, 10);
	buf = malloc(500 * sizeof(char));
	say_long_number(num, buf);
	printf("Zahl als Wort: %s\n", buf);

	return 0;
}

void say_short_number(int num, char *buf) {
	int hunderter, zehner, einer;
	char *str;

	if (num < 1 || num > 999) {
		printf("Uebergebene Zahlen muessen zwischen 1 und 999 liegen.");
		return;
	}

	hunderter = num / 100;
	zehner = (num % 100) / 10;
	einer = num % 10;

	if (hunderter > 0) {
		str = hunderter == 1 ? "ein" : EINER[hunderter - 1];
		strncat(buf, str, strlen(str));
		strncat(buf, "hundert", 7);
	}
	if (einer > 0) {
		if (zehner == 1)
			str = EINER[einer + 9];
		else if (einer == 1)
			str = "ein";
		else
			str = EINER[einer - 1];
		strncat(buf, str, strlen(str));
	}
	if (zehner > 1) {
		str = ZEHNER[zehner - 1];
		strncat(buf, "und", 3);
		strncat(buf, str, strlen(str));
	}
}

void say_long_number(long num, char *buf) {
	int milliarden, millionen, tausender, hunderter;
	char *str;

	milliarden = num / 1000000000;
	num -= (long) milliarden * 1000000000;
	millionen = num / 1000000;
	num -= millionen * 1000000;
	tausender = num / 1000;
	num -= tausender * 1000;
	hunderter = num;

	if (milliarden > 0) {
		say_short_number(milliarden, buf);
		str = "milliarden ";
		strncat(buf, str, strlen(str));
	}
	if (millionen > 0) {
		say_short_number(millionen, buf);
		str = "millionen ";
		strncat(buf, str, strlen(str));
	}
	if (tausender > 0) {
		say_short_number(tausender, buf);
		str = "tausend ";
		strncat(buf, str, strlen(str));
	}
	if (hunderter > 0)
		say_short_number(hunderter, buf);
}
