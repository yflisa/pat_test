#include <stdio.h>

int main()
{
	int n, nTime = 0;

	scanf("%d", &n);
	while(1)
	{
		nTime++;
		if (n % 2 == 0)
			n = n / 2;
		else
			n = (3 * n + 1) / 2;

		if (1 == n)
			break;
	}
	printf("%d\n", nTime);
	return 0;
}