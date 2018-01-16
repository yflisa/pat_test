#include <cstdio>
const int N = 1001;
int main()
{
	int c, e, A[N] = {0}, count = 0;
	while(scanf("%d%d", &c, &e) != EOF)
		A[e] = c;
	A[0] = 0;
	for(int i = 0; i <= 1000; i++)
	{
		A[i - 1] = A[i] * i;
		A[i] = 0;
		if(A[i -1] != 0)
			count++;
	}
	if(count == 0)
		printf("0 0");
	else
	{
		for(int i = 1000; i >= 0; i--)
		{
			if(A[i] != 0)
			{
				printf("%d %d", A[i], i);
				count--;
				if(count > 0)
					printf(" ");
			}
		}
	}

	return 0;
}