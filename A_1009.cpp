#include <cstdio>

typedef struct  Poly
{
	double c;
	int e;
};

const int N = 2001;
double A[N] = {0};

int main()
{
	int n, m, tmpE, count = 0;
	Poly P[1001] = {0};
	double tmpC;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%lf", &P[i].e, &P[i].c);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%lf", &tmpE, &tmpC);
		for(int j = 0; j < n; j++)
		{
			A[tmpE + P[j].e] += (P[j].c * tmpC);
		}
	}

	for(int i = 0; i <=2000; i++)
	{
		if(A[i] != 0.0)
			count++;
	}

	printf("%d", count);
	for(int i = 2000; i >= 0; i--)
	{
		if(A[i] != 0)
			printf(" %d %.1f", i, A[i]);
	}
	return 0;
}