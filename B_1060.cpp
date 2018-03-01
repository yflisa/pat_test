#include <cstdio>
int arr[100010] = {0};
int main()
{
	int n, tmp;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int count = 0;
	for(int i = 1; i <= n; i++)
	{
		if(arr[i] > i)
			count++;
	}

	printf("%d\n", count);
	return 0;
}