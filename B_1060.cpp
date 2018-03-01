#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1000010] = {0};
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, tmp;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max = 0, count = 0;
	sort(arr+1, arr+1+n, cmp);
	for(int i = 1; i <= n; i++)
	{
		if(arr[i] > i)
			count++;
	}

	printf("%d\n", count);
	return 0;
}