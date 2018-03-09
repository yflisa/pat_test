#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
vector<int> vi[maxn];
int leaf[maxn] = {0};
int maxdepth = -1;

void DFS(int index, int depth)
{
	maxdepth = max(depth, maxdepth);
	if(vi[index].size() == 0)
	{
		leaf[depth]++;
		return;
	}
	for(int i = 0; i < vi[index].size(); i++)
		DFS(vi[index][i], depth+1);
}

int main()
{
	int n, m, index, child, k;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &index, &k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			vi[index].push_back(child);
		}
	}
	DFS(1, 1);
	for(int i = 1; i <= maxdepth; i++)
	{
		printf("%d", leaf[i]);
		if(i != maxdepth)
			printf(" ");
	}
	return 0;
}