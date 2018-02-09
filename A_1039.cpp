#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 26 * 26 * 26 * 10;
vector<int> findCourse[maxn];

int Change(char str[])
{
	int n = 0, len = strlen(str); 
	for(int i = 0; i < len - 1; i++)
	{
		n = n * 26 + (str[i] - 'A');
	}
	n = n * 10 + (str[len-1] - '0');
	return n;
}
int main()
{
	int n, k, stuNum, courseNo;
	char name[6];
	int tmp;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; i++)
	{
		scanf("%d%d", &courseNo, &stuNum);
		for(int j = 0; j < stuNum; j++)
		{
			scanf("%s", name);
			tmp = Change(name);
			findCourse[tmp].push_back(courseNo);
		}
	}

	for(int i = 0; i < n; i++)
	{
		scanf("%s", name);
		tmp = Change(name);
		printf("%s %d", name, findCourse[tmp].size());
		sort(findCourse[tmp].begin(), findCourse[tmp].end());
		for(int j = 0; j < findCourse[tmp].size(); j++)
		{
			printf(" %d", findCourse[tmp][j]);
		}
		printf("\n");
	}
	return 0;
}