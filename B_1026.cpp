#include <cstdio>
const int CLK_TCK = 100;
int main()
{
	int C1, C2;
	scanf("%d%d", &C1, &C2);
	int ans = C2 - C1;
	if(ans % 100 >= 50)
		ans = ans / 100 + 1;
	else
		ans = ans / 100;

	printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);

	return 0;
}