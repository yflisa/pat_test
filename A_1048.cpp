/*
solution1:
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
*/


/*
solution 2:
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int A[10010];
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A, A + n);
	int i = 0, j = n - 1;
	while(i < j)
	{
		if(A[i] + A[j] == m)
		{
			break;
		}
		else if(A[i] + A[j] < m)
			i++;
		else
			j--;
	}
	if(i < j)
		printf("%d %d", A[i], A[j]);
	else
		printf("No Solution\n");
	return 0;
}
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int hashtable[N];

int main()
{
	int n, m, a;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		hashtable[a]++;
	}

	for(int i = 0; i < m; i++)
	{
		if(hashtable[i] && hashtable[m - i])
		{
			if(i == m - i && hashtable[i] <= 1)
				continue;
			printf("%d %d", i, m - i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}