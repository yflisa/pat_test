#include <cstdio>
using namespace std;
#define MAX (100010)

int nPrime[MAX] = {0};
int nNum = 0;
bool bIsPrime[MAX] = {false};

void FindPrime(int nMax)
{
	for(int i = 2; i < MAX; i++)
	{
		if(bIsPrime[i] == false)
		{
			nPrime[nNum++] = i;
			if(nNum >= nMax)
				break;
			for(int j = i + i; j < MAX; j += i)
			{
				bIsPrime[j] = true;
			}
		}
	}
}
int main()
{
	int nMin = 0, nMax = 0, nCount = 0;
	scanf("%d %d", &nMin, &nMax);
	FindPrime(nMax);
	for(int i = nMin; i <= nMax; i++)
	{
		printf("%d",nPrime[i - 1]);
		nCount++;
		if((nCount % 10 == 0) && (i < nMax))
			printf("\n");
		else if((nCount % 10 != 0) && (i < nMax))
			printf(" ");
		else if(i == nMax);
			
	}
	
	return 0;
}
