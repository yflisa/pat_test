#include <cstdio>
#include <cstring>

struct Node
{
	int next;
	char data;
	bool flag;
}node[100010];

int main()
{
	int pre, next, start1, start2, n;
	char data;
	scanf("%d %d %d", &start1, &start2, &n);
	memset(node, 0, sizeof(node));
	for(int i = 0; i < n; i++)
	{
		scanf("%d %c %d", &pre, &data, &next);
		node[pre].data = data;
		node[pre].next = next;
	}

	for(int i = start1; i != -1; i = node[i].next)
	{
		node[i].flag = true;
	}

	for(int i = start2; i != -1; i = node[i].next)
	{
		if(node[i].flag == true)
		{
			printf("%05d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}