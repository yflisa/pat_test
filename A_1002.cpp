#include <cstdio>

const int N = 1010;
int main()
{
	double A[N] = {0}, c;

	int times = 2, K, e, count = 0;

	for(int i = 0; i < times; i++)
	{
		scanf("%d", &K);
		while(K != 0)
		{
			scanf("%d%lf", &e, &c);
			A[e] += c;
			K--;
		}
	}

	for(int i = 1000; i >= 0; i--)
	{
		if(A[i] != 0)
			count++;
	}

	printf("%d", count);
	for(int i = 1000; i >= 0; i--)
	{
		if(A[i] != 0)
		{
			printf(" %d %.1f", i, A[i]);
			count--;
		}
	}

	return 0;
}