#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR_MISSING_PARAMETER 1

double distance(double a[2], double b[2]);

double shortest_path(double p[3][2]);

int main(int argc, char *argv[]) {
    double points[3][2];
    int points_len = sizeof(points) / sizeof(points[0]);

    // Aufruf: PROGRAMMNAME 2.0 5.0 4.0 8.0 1.0 3.0
	if (argc < 6) {
		printf("Ungenuegende Koordinatenanzahl.\n");
		return ERROR_MISSING_PARAMETER;
	}

	for (int i = 0; i < points_len; i++) {
		points[i][0] = atof(argv[(2 * i) + 1]);
		points[i][1] = atof(argv[(2 * i) + 2]);
	}

	printf("%lf\n", shortest_path(points));

    return 0;
}

double distance(double a[2], double b[2]) {
	return sqrt(pow(b[0] - a[0], 2) + pow(b[1] - a[1], 2));
}

double shortest_path(double p[3][2]) {
	double ab, ac, bc, abc, acb, bac;

	ab = distance(p[0], p[1]);
	ac = distance(p[0], p[2]);
	bc = distance(p[1], p[2]);

	abc = ab + bc;
	acb = ac + bc;
	bac = ab + ac;

	if (abc < acb && abc < bac)
		return abc;
	else if (acb < abc && acb < bac)
		return acb;
	else
		return bac;
}
