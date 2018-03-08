#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 110;
vector<int> vi[maxn];
int hashtable[maxn] = {0};
void DFS(int index, int level)
{
	hashtable[level]++;
	for(int i = 0; i < vi[index].size(); i++)
		DFS(vi[index][i], level+1);
}

int main()
{
	int n, m, child, parent, num;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &parent, &num);
		for(int j = 0; j < num; j++)
		{
			scanf("%d", &child);
			vi[parent].push_back(child);
		}
	}
	DFS(1, 1);

	int maxlevel = -1, maxnum = -1;
	for(int i = 1; i < maxn; i++)
	{
		if(hashtable[i] > maxnum)
		{
			maxnum = hashtable[i];
			maxlevel = i;
		}
	}
	printf("%d %d\n", maxnum, maxlevel);
	return 0;
}