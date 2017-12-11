#include <stdio.h>
const int maxn = 100010;
int school[maxn] = {0};

int main()
{
	int n = 0, schID = -1, score = -1;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &schID, &score);
		school[schID] += score;
	}

	int nTopSchoolID = -1, nTopschoolScore = 0;

	for (int i = 1; i < n; i++)
	{
		if(school[i] > nTopschoolScore)
		{
			nTopschoolScore = school[i];
			nTopSchoolID = i;
		}
	}

	printf("%d %d\n", nTopSchoolID, nTopschoolScore);
	getchar();
	getchar();
	return 0;
}