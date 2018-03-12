#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1010;
int main()
{
	vector<int> vi[maxn];
	int m, n, min, max, child, change;
	scanf("%d%d%d%d%d", &m, &n, &min, &max, &change);
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &child);
			vi[i].push_back(child);
		}
	}
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(vi[i][j] >= min && vi[i][j] <= max)
				printf("%03d", change);
			else
				printf("%03d", vi[i][j]);
			if(j + 1 != n)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}