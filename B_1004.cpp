#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct tagStu
{
	char name[11];
	char id[11];
	int score;
}Stu;

bool cmp(Stu a, Stu b)
{
	return a.score > b.score;
}

int main()
{
	int n;
	Stu st[1001] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s%s%d", &st[i].name, &st[i].id, &st[i].score);
	}
	sort(st, st + n, cmp);

	printf("%s %s\n", st[0].name, st[0].id);
	printf("%s %s\n", st[n-1].name, st[n-1].id);
	return 0;
}