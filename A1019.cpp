#include <cstdio>
typedef long long LL;

int main()
{
	LL n, b;
	int ans[40000] = {0}, count = 0;
	scanf("%lld%lld", &n, &b);
	do 
	{
		ans[count++] = n % b;
		n = n / b;
	} while (n != 0);

	int i;
	for(i = 0; i < count / 2; i++)
	{
		if(ans[i] != ans[count -i - 1])
		{
			printf("No\n");
			break;
		}
	}

	if(i == count / 2)
		printf("Yes\n");

	for(int j = count - 1; j >= 0; j--)
	{
		printf("%d", ans[j]);
		if(j != 0)
			printf(" ");
	}

	return 0;
}