#include <cstdio>
#include <cmath>
int main()
{
	int n, max = 0, a, b;
	double ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		if(max < a * a + b * b)
			max = a * a + b * b;
	}
	printf("%.2f\n", sqrt(max*1.0+0.005));
	return 0;
}