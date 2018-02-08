#include <cstdio>
#include <cmath>
typedef long long LL;
struct Factor
{
	int p;
	int k;
}F[1100];
int num = 0;
int main()
{
	LL n;
	scanf("%lld", &n);
	if(n == 0)
	{
		printf("0=0");
		return 0;
	}
	else if(n == 1)
	{
		printf("1=1");
		return 0;
	}

	LL tmp = n;
	LL sqr = (LL)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++)
	{
		if(tmp % i == 0)
		{
			F[num].p = i;
			F[num].k = 1;
			tmp = tmp / i;
			while(1)
			{
				if(tmp % i == 0)
					F[num].k++;
				else
					break;
				tmp /= i;
			}
			num++;
		}
	}
	if(tmp != 1)
	{
		F[num].p = tmp;
		F[num].k = 1;
		num++;
	}
	printf("%lld=", n);
	for(int i = 0; i < num; i++)
	{
		if(i == 0)
			printf("%d", F[i].p);
		else
			printf("*%d", F[i].p);
		if(F[i].k > 1)
			printf("^%d", F[i].k);
	}
	return 0;
}