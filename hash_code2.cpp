/*
	������hash_code2.cpp������ͬ��������ֻ��ͳ��ĳ�������ֵĴ���
*/
#include <cstdio>

const int Max = 10010;
int nHashTable[Max] = {0};

int main()
{
	int nN = 0, nM = 0, nIndex = 0;
	scanf("%d %d", &nN, &nM);
	for(int i = 0; i < nN; i++)
	{
		scanf("%d", &nIndex);
		nHashTable[nIndex]++;
	}
	nIndex = 0;
	for(int i = 0; i <nM; i++)
	{
		scanf("%d", &nIndex);
		printf("%d\n", nHashTable[nIndex]);
	}
	return 0;
}