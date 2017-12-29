#include <cstdio>
#include <queue>
using namespace std;
#define MAX (100)

struct node
{
	int data;
	node* lchild;
	node* rchild;
};
int nNum = 0;
int nIn[MAX] = {0}, nPost[MAX] = {0}, nPre[MAX] = {0};

node* Create(int nPostL, int nPostR, int nInL, int nInR)
{
	if(nPostL > nPostR)
		return NULL;
	node* tNewNode = new node;
	tNewNode->data = nPost[nPostR];
	int k = 0;
	for(k = nInL; k <= nInR; k++)
	{
		if(nIn[k] == nPost[nPostR])
			break;
	}

	int nNumLeft = k - nInL;

	tNewNode->lchild = Create(nPostL, nPostL + nNumLeft - 1, nInL, k-1);
	tNewNode->rchild = Create(nPostL + nNumLeft, nPostR - 1, k + 1,nInR);

	return tNewNode;
}

void BFS(node* root)
{
	if (NULL == root)
	{
		printf("root is NULL, %s(%d)", __FUNCTION__ ,__LINE__);
		return;
	}
	queue<node*> q;
	q.push(root);
	int nTmpNum = 0;
	while(!q.empty())
	{
		node* tNow = q.front();
		q.pop();
		printf("%d", tNow->data);
		nTmpNum++;
		if(nTmpNum < nNum)
			printf(" ");
		if(tNow->lchild != NULL)
			q.push(tNow->lchild);
		if(tNow->rchild != NULL)
			q.push(tNow->rchild);
	}
}
int main()
{
	scanf("%d", &nNum);
	for(int i = 0; i < nNum; i++)
		scanf("%d", &nPost[i]);

	for(int i = 0; i < nNum; i++)
		scanf("%d", &nIn[i]);

	node* root = Create(0, nNum - 1, 0, nNum - 1);
	BFS(root);

	return 0;
}