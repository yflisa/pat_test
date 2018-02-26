#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;
struct mouse
{
	int weight;
	int R;
}mouse[maxn];

int main()
{
	int np, ng, order;
	queue<int> q;
	scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; i++)
		scanf("%d", &mouse[i].weight);
	for(int i = 0; i < np; i++)
	{
		scanf("%d", &order);
		q.push(order);
	}

	int group, temp = np;
	while(q.size() != 1)
	{
		if(temp % ng == 0)
			group = temp / ng;
		else
			group = temp / ng + 1;

		for(int i = 0; i < group; i++)
		{
			int k = q.front();
			for(int j = 0; j < ng; j++)
			{
				if(i * ng + j >= temp)
					break;
				int front = q.front();
				if(mouse[k].weight < mouse[front].weight)
					k = front;
				mouse[front].R = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	mouse[q.front()].R = 1;
	for(int i = 0; i < np; i++)
	{
		printf("%d", mouse[i].R);
		if(i + 1 != np)
			printf(" ");
	}
	
	return 0;
}