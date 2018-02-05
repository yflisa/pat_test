#include <cstdio>
int main()
{
	int n = 0;
	double ans = 0.00, a = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &a);
		ans += a * i * (n - i + 1);
	}
	printf("%.2f\n", ans);
	return 0;
}