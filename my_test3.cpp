#include <cstdio>
#include <stdlib.h>
using namespace std;
#define MAX (10)

int n = 0; 
int nCount = 0;
int P[MAX] = {0};
bool hashTable[MAX] = {false};

void generateP(int nIndex)
{
	if(n == nIndex + 1)
	{
		nCount++;
		return ;
	}

	for(int i = 0; i <= n; i++)
	{
		if(false == hashTable[i])
		{
			bool flag = true;
			for(int j = 1; j < nIndex; j++)
			{
				if(abs(nIndex - j) == abs(i - P[j]) )
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				P[nIndex] = i;
				hashTable[i] = true;
				generateP(nIndex + 1);
				hashTable[i] = false;
			}
		}
	}
}
int main()
{
	n = 5;
	generateP(1);
	printf("%d\n", nCount);
	return 0;
}