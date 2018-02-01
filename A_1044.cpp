#include <cstdio>
const int maxn = 100010;
int sum[maxn];
int n, S, nearS = 1000000010;

int upper_bound(int l, int r, int x)
{
	int left = l, right = r, mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(sum[mid] > x)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main()
{
	scanf("%d%d", &n, &S);
	sum[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}

	for(int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + S);
		if(sum[j - 1] - sum[i - 1] == S)
		{
			nearS = S;
			break;
		}
		else if(j <= n && sum[j] - sum[i - 1] < nearS)
		{
			nearS = sum[j] - sum[i - 1];
		}
	}

	for(int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);
		if(sum[j - 1] - sum[i - 1] == nearS)
			printf("%d-%d\n", i, j - 1);
	}
	return 0;
}