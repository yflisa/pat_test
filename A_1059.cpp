#include <cstdio>
#include <cmath>
typedef long long LL;
#define MAX 10010
typedef struct tagFactor
{
	int x;
	int num;
}Factor;

int nNum = 0, nPrime[10010] = {0};
bool bIsPrime[10010] = {false};
//找出前十个质因子
void Find_Prime()
{
	for(int i = 2; i < 10010; i++)
	{
		if(bIsPrime[i] == false)
		{
			nPrime[nNum++] = i;
			for(int j = i + i; j < 10010; j += i)
			{
				bIsPrime[j] = true;
			}
		}
	}
}

//循环查找相应的质因子
void Find_Prime_Factor(LL n, Factor tFactor[])
{
	Find_Prime();
	int nCount = 0;

	for(int i = 0; i < nNum; i++)
	{
		if(n % nPrime[i] == 0)
		{
			 tFactor[nCount].num++;
			 n /= nPrime[i];
			 while(n % nPrime[i] == 0)
			 {
				 tFactor[nCount].num++;
				 n /= nPrime[i];
			 }
			 tFactor[nCount++].x = nPrime[i];
		}
	}
}

int main()
{
	Factor tFactor[10] = {0};
	LL n;
	scanf("%lld", &n);
	if(n == 1)
	{
		printf("1=1\n");
		return 0;
	}

	Find_Prime_Factor(n ,tFactor);
	printf("%d=", n);
	for(int i = 0; i < 10; i++)
	{
		if(tFactor[i].x == 0)
			break;
		if(i > 0)
			printf("*");
		if(tFactor[i].x != 0)
		{
			printf("%d", tFactor[i].x);
			if(tFactor[i].num > 1)
				printf("^%d", tFactor[i].num);
		}
	}
	return 0;
}