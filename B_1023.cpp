
#include <cstdio>
using namespace std;

int main()
{
	int nCount[10] = {0}; 

	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &nCount[i]);
	}

	for(int i = 1; i < 10; i++)
	{
		if(nCount[i] > 0)
		{
			printf("%d", i);
			nCount[i]--;
			break;
		}
	}

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < nCount[i]; j++)
		{
			if(j < nCount[i])
			{
				printf("%d", i);
			}
		}
	}
	return 0;
}