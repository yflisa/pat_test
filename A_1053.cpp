#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX (100)

typedef struct tagNode
{
	int nWeight;
	vector<int> child;
}Node;

int nNum = 0, nS = 0, nM = 0;
Node tNode[MAX] = {0};
int nPath[MAX] = {0};
bool cmp(int a, int b)
{
	return tNode[a].nWeight > tNode[b].nWeight;
}

void DFS(int index, int nNumNode, int nSum)
{
	if(nM < nSum)
		return;
	if(nM == nSum)
	{
		if(tNode[index].child.size() != 0)
			return;

		for(int i = 0; i < nNumNode; i++)
		{
			printf("%d", tNode[nPath[i]].nWeight);
			if(i < nNumNode - 1)
				printf(" ");
			else
				printf("\n");
		}
	}

	for(int i = 0; i < tNode[index].child.size() ; i++)
	{
		int child = tNode[index].child[i];
		nPath[nNumNode] = child;
		DFS(child, nNumNode + 1, nSum + tNode[child].nWeight);
	}
}
int xxxxx()
{
	scanf("%d%d%d", &nNum, &nS, &nM);
	for(int i = 0; i < nS; i++)
		scanf("%d", &tNode[i].nWeight);

	int nTmpNode = 0 , nTmpNum = 0, nChild = 0, nTmpSum = 0;
	for(int i = 0; i < nNum; i++)
	{
		scanf("%d%d", &nTmpNode, &nTmpNum);
		for(int j = 0; j < nTmpNum; j++)
		{
			scanf("%d", &nChild);
			tNode[nTmpNode].child.push_back(nChild);
		}
		sort(tNode[nTmpNode].child.begin(), tNode[nTmpNode].child.end(), cmp);
	}

	nPath[0] = 0;
	DFS(0, 1, tNode[0].nWeight);
	return 0;
}