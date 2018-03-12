#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1000000;
int couple[maxn] = {-1}, guest[maxn] = {-1};
int isExist[maxn] = {0};
int main()
{
	int n, m, c1, c2;
	set<int> s;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &c1, &c2);
		couple[c1] = c2;
		couple[c2] = c1;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &guest[i]);
		if(couple[guest[i]] != -1)
			isExist[couple[guest[i]]] = 1;
	}
	for(int i = 0; i < m; i++)
	{
		if(!isExist[guest[i]])
			s.insert(guest[i]);
	}
	printf("%d\n", s.size());
	for(auto it = s.begin(); it != s.end(); it++)
	{
		if(it != s.begin())
			printf(" ");
		printf("%d", *it);
	}
	return 0;
}