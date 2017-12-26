#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX (100010)

typedef struct tagNode
{
	int address;
	int data;
	int next;
	bool flag;
}Node;

Node tNode[MAX] = {0};

bool cmp(Node a, Node b)
{
	if(a.flag == false || b.flag == false)
		return a.flag > b.flag;
	else
		return a.data < b.data;
}

int main()
{
	int nNum = 0, nFirstAddr = 0, nAddress = 0;
	scanf("%d%d", &nNum, &nFirstAddr);

	for(int i = 0; i < nNum; i++)
	{
		scanf("%d", &nAddress);
		scanf("%d%d", &tNode[nAddress].data, &tNode[nAddress].next);
		tNode[nAddress].address = nAddress;
	}

	int nCount = 0, nTmpAddr = nFirstAddr;
	while(nTmpAddr != -1)
	{
		tNode[nTmpAddr].flag = true;
		nCount++;
		nTmpAddr = tNode[nTmpAddr].next;
	}


	if(nNum == 0)
		printf("0 -1");
	else
	{
		sort(tNode, tNode + MAX, cmp);
		printf("%d %d\n", nCount, tNode[0].address);
		for(int i = 0; i < nCount; i++)
		{
			if(i != nCount - 1)
				printf("%05d %d %05d\n", tNode[i].address, tNode[i].data, tNode[i+1].address);
			else
				printf("%05d %d -1\n", tNode[i].address, tNode[i].data);
		}
	}	

	return 0;
}