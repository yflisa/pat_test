#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;
#define MAX (100010)
int nA[MAX] = {0};
int nNum = 0;

inline double round(double d)
{
	return floor(d + 0.5);
}

int randPartition(int nA[], int nLeft, int nRight)
{
	int P = round(1.0 * rand()/RAND_MAX*(nRight - nLeft) + nLeft);

	swap(nA[nLeft], nA[P]);
	int nTmp = nA[nLeft];
	while(nLeft < nRight)
	{
		while(nLeft < nRight && nA[nRight] > nTmp)
			nRight--;
		nA[nLeft] = nA[nRight];
		while(nLeft < nRight && nA[nLeft] < nTmp)
			nLeft++;
		nA[nRight] = nA[nLeft];
	}
	nA[nLeft] = nTmp;
	return nLeft;
}

void randSelect(int nA[], int nLeft, int nRight, int K)
{
	if(nLeft == nRight)
		return;

	int P = randPartition(nA, nLeft, nRight);
	int M = P - nLeft + 1;
	if(K == M)
		return;

	if(K < M)
		randSelect(nA, nLeft, P - 1, K);
	else
		randSelect(nA, P + 1, nRight, K - M);
}

int main()
{
	int nSum = 0, nSum1 = 0;

	srand((unsigned)time(NULL));
	scanf("%d", &nNum);
	for(int i = 0; i < nNum; i++)
	{
		scanf("%d", &nA[i]);
		nSum += nA[i];
	}

	//排序
	randSelect(nA, 0 , nNum - 1, nNum / 2);
	//计算一半的总和
	for(int i = 0; i < nNum / 2; i++)
	{
		nSum1 += nA[i];
	}

	printf("%d\n", (nSum - nSum1) - nSum1);

	return 0;
}