#include <cstdio>
char radix[13] = {'0', '1','2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B','C'};
int main()
{
	int count = 0, a[40], number[3] = {0};

	scanf("%d%d%d", &number[0], &number[1], &number[2]);
	printf("#");
	for(int i = 0; i < 3; i++)
	{
		do 
		{
			a[count++] = number[i] % 13;
			number[i] = number[i] / 13;
		} while (number[i] != 0);

		if(count == 1 && a[0] == 0)
		{
			printf("00");
			count = 0;
			continue;
		}
		if(count == 1 && a[0] != 0)
		{
			printf("0");
		}
		for(int j = count-1; j >= 0; j--)
		{
			printf("%c", radix[a[j]]);
		}
		count = 0;
	}
	return 0;
}