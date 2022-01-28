#include <stdio.h>

double my_pow(int, int);
double my_sqrt(int);

int main() {
	int a, b;

	a = 10;
	b = 0;
	printf("%d^%d: %lf\n", a, b, my_pow(a, b));

	a = 10;
	b = 3;
	printf("%d^%d: %lf\n", a, b, my_pow(a, b));

	a = 10;
	b = -3;
	printf("%d^%d: %lf\n", a, b, my_pow(a, b));

	a = 9;
	printf("sqrt(%d): %lf\n", a, my_sqrt(a));

	a = 64;
	printf("sqrt(%d): %lf\n", a, my_sqrt(a));

	a = 5;
	printf("sqrt(%d): %lf\n", a, my_sqrt(a));

	return 0;
}

double my_pow(int base, int exp) {
	int i;
	double res = 0;

	if (exp == 0) {
		return 1;
	} else if (exp > 0) {
		res = 1;
		for (i = 0; i < exp; i++) {
			res *= base;
		}
	} else {
		res = 1;
		for (i = 0; i > exp; i--) {
			res /= base;
		}
	}

	return res;
}

double my_sqrt(int a) {
	double x0, x1;

	x0 = (a + 1) / 2;
	x1 = a;

	while (x1 - x0 > 0.00001) {
		x1 = x0;
		x0 = 0.5 * (x1 + a / x1);
	}

	return x0;
}
