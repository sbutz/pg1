#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

struct point {
	int x, y;
};

struct point points[4];

double area3(struct point, struct point, struct point);

int main() {
	int i;
	double area;

	for (i = 0; i < ARRAY_SIZE(points); i++) {
		printf("%d. Punkt X-Koordinate: ", i + 1);
		scanf("%d", &points[i].x);
		printf("%d. Punkt Y-Koordinate: ", i + 1);
		scanf("%d", &points[i].y);
	}

	area = area3(points[0], points[1], points[2]) +
		area3(points[1], points[2], points[3]);
	printf("area: %lf\n", area);

	return 0;
}

double area3(struct point a, struct point b, struct point c) {
	double ab, ac, bc, height, s;

	ab = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	ac = sqrt(pow(c.x - a.x, 2) + pow(c.y - a.y, 2));
	bc = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
	s = 0.5 * (ab + ac + bc);
	return sqrt(s * (s - ab) * (s - ac) * (s - bc));
}
