/*algorithm for calculating standard deviation*/
/*asliddinxanov*/
/*https://github.com/asliddinxanov*/
/*2022-03-22*/

#include<stdio.h>
#include<math.h>

void data_in(int *n, double x[]) {
	int i;
	printf("data number=");
	scanf_s("%d", &*n);
	for (i = 1; i <= *n; i++) {
		printf("x[%d]=", i);
		scanf_s("%lf", &x[i]);
	}
}

void standard(int n, double *sg, double x[], double xh[], double y[]) {
	int i;
	double s1, s2, me1, me2;

	s1 = s2 = 0;
	for (i = 1; i <= n; i++) {
		s1 += x[i];
		s2 += x[i] * x[i];
	}
	me1 = s1 / n;
	me2 = s2 / n;
	*sg = sqrt(me2 - me1 * me1);
	for (i = 1; i <= n; i++) {
		xh[i] = (x[i] - me1) / *sg;
		y[i] = 10 * xh[i] + 50;
	}
}

void sol_out(int n, double sg, double x[], double xh[], double y[]) {
	int i;
	printf("standard deviation:\n");
	printf("  sg=%8.4f\n", sg);
	printf("standardized data and deviation\n");
	printf(" i   x[i]     xh[i]    y[i]\n");
	for (i = 1; i <= n; i++) {
		printf("%3d %6.2f %8.4f %8.4f\n", i, x[i], xh[i], y[i]);
	}
}

int main(void) {
	int n;
	double sg;
	double x[100], xh[100], y[100];

	data_in(&n, x);
	standard(n, &sg, x, xh, y);
	sol_out(n, sg, x, xh, y);
	return(0);
}