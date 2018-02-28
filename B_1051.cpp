#include <cstdio>
#include <cmath>
int main()
{
	double R1, P1, R2, P2;
	scanf("%lf%lf%lf%lf", &R1, &P1, &R2, &P2);
	double a1 = R1 * cos(P1), b1 = R1 * sin(P1), a2 = R2 * cos(P2), b2 = R2 * sin(P2);
	double A = a1 * a2 - b1 * b2;
	double B = a1 * b2 + a2 * b1;
	if(A + 0.005 >= 0 && A < 0)
		printf("0.00");
	else
		printf("%.2f", A);

	if(B >= 0)
		printf("+%.2fi", B);
	else if(B + 0.005 >= 0 && B <0)
		printf("+0.00i");
	else
		printf("%.2fi", B);
	return 0;
}