#include <cstdio>
typedef struct tagPattest
{
	char stuID[15];
	int testID;
	int examID;
}PAT;

int main()
{
	int n;
	PAT pat[1001] = {0};
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%s%d%d", &pat[i].stuID, &pat[i].testID, &pat[i].examID);
	}

	int query[1001] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &query[i]);
		for(int j = 0; j <= 1000; j++)
		{
			if(query[i] == pat[j].testID)
				printf("%s %d\n", pat[j].stuID, pat[j].examID);
		}
	}
	return 0;
}