#include <cstdio>
typedef long long LL;

int main()
{
	LL a, b, c, ans = 0;
	bool flag = false;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		ans = a + b;
		if(a > 0 && b > 0 && ans < 0)
			flag = true;
		else if(a < 0 && b < 0 && ans >= 0)
			flag = false;
		else if(ans > c)
			flag = true;
		else 
			flag = false;

		if(!flag)
			printf("Case #%d: false\n", i);
		else
			printf("Case #%d: true\n", i);
	}
	return 0;
}