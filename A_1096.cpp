#include <cstdio>
#include <cmath>
typedef long long LL;
int main()
{
	LL n;
	scanf("%lld", &n);
	LL sqr = (LL)sqrt(1.0 * n) ,ansI = 0, ansLen = 0;

	for(LL i = 2; i <= sqr; i++)
	{
		LL tmp = 1, j = i;
		while(1)
		{
			tmp *= j;
			if(n % tmp != 0)
				break;
			if(j - i + 1 > ansLen)
			{
				ansLen = j - i + 1;
				ansI = i;
			}
			j++;
		}
	}
	if(ansLen == 0)
		printf("1\n%lld", n);
	else
	{
		printf("%lld\n", ansLen);
		for(int i = 0; i < ansLen; i++)
		{
			printf("%lld", i + ansI);
			if(i + 1 != ansLen)
				printf("*");
		}
	}

	return 0;
}