#include <iostream>
using namespace std;

int main()
{
	int A, B, D, res[50] = {0}, count = 0;
	cin >> A >> B >> D;
	int ans = A + B;
	if(ans == 0)
		printf("0");
	else
	{
		for(int i = 0; ans != 0; i++)
		{
			res[i] = ans % D;
			ans /= D;
			count++;
		}

		for(int i = count - 1; i >= 0; i--)
		{
			printf("%d", res[i]);
		}
	}

	return 0;
}