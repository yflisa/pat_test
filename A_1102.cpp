#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 12;
int pre[maxn], in[maxn], post[maxn], n, num = 0;
bool hashtable[maxn] = {false};
struct Node
{
	int data;
	int lchild;
	int rchild;
}node[maxn];

int strToNum(char c)
{
	if (c == '-')
		return -1;
	hashtable[c-'0'] = true;
	return c-'0';
}

int findRoot()
{
	for(int i = 0; i < n; i++)
	{
		if(hashtable[i] == false)
			return i;
	}
}

void print(int root)
{
	printf("%d", root);
	num++;
	if(num < n)
		printf(" ");
	else
		printf("\n");
}

void layerorder(int root)
{
	if(root == -1)
		return;
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		print(now);
		if(node[now].lchild != -1)
			q.push(node[now].lchild);
		if(node[now].rchild != -1)
			q.push(node[now].rchild);
	}
}

void inorder(int root)
{
	if(root == -1)
		return;
	inorder(node[root].lchild);
	print(root);
	inorder(node[root].rchild);
}

void postorder(int root)
{
	if(root == -1)
		return;
	postorder(node[root].lchild);
	postorder(node[root].rchild);
	swap(node[root].lchild, node[root].rchild);
}
int main()
{
	scanf("%d", &n);
	char c1, c2;
	int x;
	for(int i = 0; i < n; i++)
	{
		getchar();
		scanf("%c %c", &c1, &c2);
		node[i].lchild = strToNum(c1);
		node[i].rchild = strToNum(c2);
	}
	int root = findRoot();
	postorder(root);
	layerorder(root);
	num = 0;
	inorder(root);
	return 0;
}