#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, m, k, question, block = 0;
vector<int> vi[maxn];
bool isask[maxn] = {false};

void dfs(int index)
{
	isask[index] = true;
	if(index == question)
		return;
	for(int i = 0; i < vi[index].size(); i++)
	{
		if(isask[vi[index][i]] == false)
			dfs(vi[index][i]);
	}
}
int main()
{
	int start, end;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &start, &end);
		vi[start].push_back(end);
		vi[end].push_back(start);
	}

	for(int ask = 0; ask < k; ask++)
	{
		scanf("%d", &question);
		memset(isask, false, sizeof(isask));
		block = 0;
		for(int i = 1; i <=n; i++)
		{
			if(isask[i] == false&& i != question)
			{
				dfs(i);
				block++;
			}
		}
		printf("%d\n", block-1);
	}
	return 0;
}