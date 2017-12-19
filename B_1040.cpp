#include <cstdio>
#include <cstring>
#define MAX (100010)
#define MOD (1000000007)

int main()
{
	char chStr[MAX] = {0};
	int nLeftNumP[MAX] = {0}, nLen = 0;

	gets(chStr);
	nLen = strlen(chStr);

	for(int i = 0; i < nLen; i++)
	{
		if(i > 0)
			nLeftNumP[i] = nLeftNumP[i - 1];
		
		if(chStr[i] == 'P')
		{
			nLeftNumP[i]++;
		}
	}

	int ans = 0, nRightNumT = 0;

	for(int i = nLen - 1; i >= 0; i--)
	{
		if(chStr[i] == 'T')
			nRightNumT++;
		else if(chStr[i] == 'A')
		{
			ans = (ans + nLeftNumP[i] * nRightNumT) % MOD;
		}
	}

	printf("%d\n", ans);
	return 0;
}