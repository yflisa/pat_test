#include <cstdio>
const int Galleon = 17 * 29;
const int Sickle = 29;

int main()
{
	int a1, a2, a3;
	int b1, b2, b3;
	scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
	long long num1 = a1 * Galleon + a2 * Sickle + a3;
	long long num2 = b1 * Galleon + b2 * Sickle + b3;

	long long ans = num1 + num2;
	long long res[3] = {0};
	res[0] = ans / Galleon;
	res[1] = ans % Galleon / Sickle;
	res[2] = ans % Sickle;
	printf("%d.%d.%d", res[0], res[1], res[2]);

	return 0;
}