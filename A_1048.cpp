#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int N[maxn], n, m;

int upper_bound(int l, int r, int x)
{
	int left = l, right = r, mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(N[mid] == x)
			return mid;
		else if(N[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &N[i]);
	sort(N, N + n);

	for(int i = 0; i < n; i++)
	{
		int j = upper_bound(0, n, m - N[i]);
		if(j != -1 && i != j)
		{
			printf("%d %d", N[i], N[j]);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}