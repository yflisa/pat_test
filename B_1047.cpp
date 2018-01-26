#include <cstdio>

int main()
{
	int n, score[10010] = {0};
	int team, person, num;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d-%d %d", &team, &person, &num);
		score[team] += num;
	}

	int max = -1, top;
	for(int i = 0; i < 10010; i++)
	{
		if(max < score[i])
		{
			max = score[i];
			top = i;
		}
	}

	printf("%d %d", top, max);
	return 0;
}