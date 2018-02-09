#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> vch[2500];
int main()
{
	char name[5];
	int n, k, courNum, courNo;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s %d", name, &courNum);
		for(int j = 0; j < courNum; j++)
		{
			scanf("%d", &courNo);
			vch[courNo].push_back(name);
		}
	}

	for(int i = 1;i <= k; i++)
	{
		printf("%d %d\n", i, vch[i].size());
		sort(vch[i].begin(), vch[i].end());
		for(int j = 0; j < vch[i].size(); j++)
		{
			printf("%s\n", vch[i][j].c_str());
		}
	}
	return 0;
}