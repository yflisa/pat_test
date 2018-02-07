#include <cstdio>
#include <cmath>
int n, m, num = 0;
const int maxn = 10010;
bool prime[maxn] = {false};
int is_prime[maxn] = {0};

void find_prime(int n)
{
	for(int i = 2; i < 1010; i++)
	{
		if(prime[i] == false)
		{
			is_prime[num++] = i;
			for(int j = i + i; j < 1010; j += i)
			{
				prime[j] = true;
			}
			if(num > n)
				break;
		}
	}
}
int main()
{
	int count = 0;
	scanf("%d%d", &m, &n);
	find_prime(n);
	for(int i = m; i <= n; i++)
	{
		printf("%d", is_prime[i - 1]);
		count++;
		if(count % 10 == 0)
			printf("\n");
		else if(count % 10 != 0 && i < n)
			printf(" ");
	}
	return 0;
}