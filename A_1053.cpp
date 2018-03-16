#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct Node
{
	int weight;
	vector<int> child;
}node[maxn];
int n, m, sum;
int ans[maxn] = {0}, xxx = 0;
bool cmp(int a, int b)
{
	return node[a].weight > node[b].weight;
}
void DFS(int index, int path, int tmp_sum)
{
	if(tmp_sum > sum)
		return;

	if(sum == tmp_sum && node[index].child.size() == 0)
	{
		for(int i = 0; i < path; i++)
		{
			printf("%d", node[ans[i]].weight);
			if(i+1 != path)
				printf(" ");
			else
				printf("\n");
		}
		return;
	}
	else if(sum == tmp_sum && node[index].child.size() != 0)
		return;

	for(int i = 0; i < node[index].child.size(); i++)
	{
		int child = node[index].child[i];
		ans[path] = child;
		DFS(child, path+1, node[child].weight+tmp_sum);
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &sum);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &node[i].weight);
	}

	for(int i = 0; i < m; i++)
	{
		int parent, k, child;
		scanf("%d%d", &parent, &k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			node[parent].child.push_back(child);
		}
		sort(node[parent].child.begin(), node[parent].child.end(), cmp);
	}
	DFS(0, 1, node[0].weight);

	return 0;
}