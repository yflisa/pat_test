#include <cstdio>

const int N = 110;
int main()
{
	int num; 
	int A1[N], sum1[N], A2[N], sum2[N], ans1 = 0, ans2 = 0;
	scanf("%d", &num);
	for(int i = 0; i < num; i++)
	{
		scanf("%d%d%d%d", &A1[i], &sum1[i], &A2[i], &sum2[i]);
	}

	for(int i = 0; i < num; i++)
	{
		if(A1[i] + A2[i] == sum1[i] && A1[i] + A2[i] != sum2[i])
			ans2++;
		else if(A1[i] + A2[i] == sum2[i] && A1[i] + A2[i] != sum1[i])
			ans1++;
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}