#include <cstdio>
#define MAX (100010)
typedef struct tagNode
{
	char data;
	int  Next; 
	bool flag;
}Node;
Node tNode[MAX] = {0};

int main()
{
	for(int i = 0; i < MAX; i++)
	{
		tNode[i].flag = false;
	}

	int nAddress1 = 0, nAddress2 = 0, nNum = 0, nNext = 0;
	char chCharac;

	scanf("%d %d %d", &nAddress1, &nAddress2, &nNum);

	for(int i = 0; i < nNum; i++)
	{
		int nTmpAddr = 0;
		scanf("%d %c %d", &nTmpAddr, &chCharac, &nNext);
		tNode[nTmpAddr].data = chCharac;
		tNode[nTmpAddr].Next = nNext;
	}
	int i = 0;
	for(i = nAddress1; i != -1; i = tNode[i].Next)
	{
		tNode[i].flag = true;
	}

	int nFirstNode = -1;
	for(int i = nAddress2; i != -1; i = tNode[i].Next)
	{
		if(tNode[i].flag == true)
		{
			nFirstNode = i;
			break;
		}
	}

	if(nFirstNode == -1)
		printf("-1");
	else
		printf("%05d", nFirstNode);

	return 0;
}