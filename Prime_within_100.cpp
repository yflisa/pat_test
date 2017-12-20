#include <cstdio>
#include <cmath>
#define MAX (101)

int nPrime[MAX] = {0};
int nNum = 0;

bool isPrime(int n)
{
	if(n <= 1)
		return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++)
	{
		if( n % i == 0)
			return true;
	}
	return false;
}

void Find_Prime()
{
	for(int i = 1; i < 101; i++)
	{
		if(isPrime(i) == false)
			nPrime[nNum++] = i;
	}

}
int main()
{
	Find_Prime();
	for(int i = 0; i < nNum; i++)
	{
		printf("%d ", nPrime[i]);
	}
	return 0;
}