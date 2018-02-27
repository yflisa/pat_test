#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node
{
	int data, next, pre;
	bool flag;
}node[maxn];

bool cmp(Node a, Node b)
{
	if(a.flag == false || b.flag == false)
		return a.flag > b.flag;
	else
		return a.data < b.data;
}

int main()
{
	int pre, data, next, start, n;
	scanf("%d %d", &n, &start);
	if(n == 1)
	{
		scanf("%d %d %d", &pre, &data, &next);
		if(pre != start)
			printf("0 -1\n");
		else
		{
			printf("1 %05d\n", pre);
			printf("%05d %d -1\n", pre, data);
		}
		return 0;
	}

	for(int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &pre, &data, &next);
		node[pre].data = data;
		node[pre].next = next;
		node[pre].pre = pre;
	}

	int count = 0;
	for(int i = start; i != -1; i = node[i].next)
	{
		node[i].flag = true;
		count++;
	}

	if(count == 0)
	{
		printf("0 -1\n");
		return 0;
	}

	sort(node, node + maxn, cmp);

	printf("%d %05d\n", n, node[0].pre);
	for(int i = 0; i < n; i++)
	{
		if(i + 1 != n)
			printf("%05d %d %05d\n", node[i].pre, node[i].data, node[i+1].pre);
		else
			printf("%05d %d -1\n", node[i].pre, node[i].data);
	}
	return 0;
}