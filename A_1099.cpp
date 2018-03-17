#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 110;
int n, number[maxn], ans[maxn] = {0}, cnt = 0, index = 0;
struct Node
{
	int left, right, data;
}node[maxn];
void levelorder(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		printf("%d", node[now].data);
		index++;
		if(index < n)
			printf(" ");
		if(node[now].left != -1)
			q.push(node[now].left);
		if(node[now].right != -1)
			q.push(node[now].right);
	}
}
void inorder(int root)
{
	if(root == -1)
		return;
	inorder(node[root].left);
	node[root].data = number[cnt++];
	inorder(node[root].right);
}
int main()
{
	scanf("%d", &n);
	int left, right;
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d",&left, &right);
		node[i].left = left;
		node[i].right = right;
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &number[i]);
	}
	sort(number , number+n);
	inorder(0);
	levelorder(0);
	return 0;
}