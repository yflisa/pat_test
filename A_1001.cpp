#include <cstdio>
int ans[1000010] = {0}, a, b;
int main()
{
	int tmp, num = 0;

	scanf("%d %d", &a, &b);
	tmp = a + b;
	if(tmp < 0)
	{
		printf("-");
		tmp = -tmp;
	}
	if(tmp == 0)
		ans[num++] = 0;
	while(tmp != 0)
	{
		ans[num++] = tmp % 10;
		tmp /= 10;
	}
	
	for(int i = num - 1; i >= 0; i--)
	{
		printf("%d", ans[i]);
		if( i > 0 && i % 3 == 0 )
			printf(",");
	}
	
	return 0;
}