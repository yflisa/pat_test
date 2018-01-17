#include <cstdio>

int main()
{
	int n, ans[3] = {0};
	scanf("%d", &n);
	ans[0] = n / 100;
	ans[1] = n % 100 / 10;
	ans[2] = n % 10;

	for(int i = 0; i < ans[0]; i++)
	{
		printf("B");
	}
	for(int i = 0; i < ans[1]; i++)
		printf("S");
	for(int i = 1; i <= ans[2]; i++)
		printf("%d", i);

	return 0;
}