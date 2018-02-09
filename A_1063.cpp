#include <cstdio>
#include <set>
using namespace std;

set<int> si[51];
int main()
{
	int n, m, num, tmp, first, second;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		for(int j = 0; j < num; j++)
		{
			scanf("%d", &tmp);
			si[i].insert(tmp);
		}
	}
	scanf("%d", &m);
	int count, total;
	for(int i = 0; i < m; i++)
	{
		count = 0;
		total = 0;
		scanf("%d %d", &first, &second);
		set<int>::iterator sit = si[first].begin();
		for(; sit != si[first].end(); sit++)
		{
			if(si[second].find(*sit) != si[second].end())
				count++;
		}
		total = si[first].size() + si[second].size() - count;
		printf("%.1f%%\n", count * 100.0/ total);
	}
	return 0;
}