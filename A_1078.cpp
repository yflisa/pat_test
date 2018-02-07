#include <cstdio>
#include <cmath>
const int maxn = 11111;
bool hashtable[maxn] = {false};
bool isPrime(int n)
{
	if(n <= 1)
		return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int Tsize, n, a;
	scanf("%d%d", &Tsize, &n);
	while(isPrime(Tsize) == false)
		Tsize++;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		int M = a % Tsize;
		if(hashtable[M] == false)
		{
			hashtable[M] = true;
			if(i == 0)
				printf("%d", M);
			else
				printf(" %d", M);
		}
		else
		{
			int step;
			for(step = 1; step < Tsize; step++)
			{
				M = (a + step * step) % Tsize;
				if(hashtable[M] == false)
				{
					hashtable[M] = true;
					if(i == 0)
						printf("%d", M);
					else
						printf(" %d", M);
					break;
				}
			}
			if(step >= Tsize)
			{
				if(i == 0)
					printf("-");
				else
					printf(" -");
			}
		}
	}
	return 0;
}