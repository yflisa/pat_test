#include <cstdio>
#include <cmath>
typedef long long LL;

typedef struct tagFactor
{
	int x;
	int num;
}Factor;

int nNum = 0, nPrime[10] = {0};
bool bIsPrime[10] = {false};
//找出前十个质因子
void Find_Prime()
{
	for(int i = 0; i < 10; i++)
	{
		if(bIsPrime[i] == false)
		{
			nPrime[nNum++] = i;
			for(int j = i + i; j < 10; j += i)
			{
				bIsPrime[j] == true;
			}
		}
	}
}

//循环查找相应的质因子
void Find_Prime_Factor(LL n, Factor tFactor[])
{
	Find_Prime();
	int nCount = 0;

	for(int i = 0; i < 10; i++)
	{
		tFactor[i].x = nPrime[i];
	}

	for(int i = 0; i < 10; i++)
	{
		while(n % nPrime[i] == 0)
		{
			 tFactor[i].num++;
			 n /= nPrime[i];
		}
	}
}

int main()
{
	Factor tFactor[10] = {0};
	LL n;
	scanf("%lld", &n);

	Find_Prime_Factor(n ,tFactor);
	for(int i = 0; i < 10; i++)
	{
		printf("%d=", n);
		if(tFactor[i].num = 1)
		{
			printf("%ld", tFactor[i].x);
			break;
		}
		else
		{
			printf("%ld^%ld", tFactor[i].x, tFactor[i].num);
		}
		printf("*");
			
	}
	return 0;
}