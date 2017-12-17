#include <cstdio>
using namespace std;
#define MAX (10)
int n = 0;
int P[MAX] = {0};
bool hashTable[MAX] = {false};

void generateP(int nIndex)
{
	if(n + 1 == nIndex)
	{
		for(int i = 1; i <= n; i++)
		{
			printf("%d", P[i]);
		}
		printf("\n");
		return ;
	}

	for(int i =1; i <= n; i++)
	{
		if(false == hashTable[i])
		{
			P[nIndex] = i;
			hashTable[i] = true;
			generateP(nIndex + 1);
			hashTable[i] = false;
		}
	}
}

int main()
{
	n = 5;
	generateP(1);
	return 0;
}