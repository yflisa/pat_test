#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, father[maxn], isRoot[maxn] = {0}, k;
void init()
{
	for(int i = 0; i < maxn; i++)
		father[i] = i;
}
//包含了压缩路径的操作
int findFather(int x)
{
	int a = x;
	while(x != father[x])
		x = father[x];
	while(a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB)
		father[faA] = faB;
}

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int t, cnt = 0, course[maxn] = {0};
	scanf("%d", &n);
	init();
	for(int i = 1; i <= n; i++)
	{
		scanf("%d:", &k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &t);
			if(course[t] == 0)
				course[t] = i;
			Union(i, findFather(course[t]));
		}
	}
	for(int i = 1; i <= n; i++)
	{
		isRoot[findFather(i)]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(isRoot[i] != 0)
			cnt++;
	}
	sort(isRoot, isRoot + n + 1, cmp);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
	{
		printf("%d", isRoot[i]);
		if(i + 1 != cnt)
			printf(" ");
	}
	return 0;
}