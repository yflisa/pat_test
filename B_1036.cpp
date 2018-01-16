#include <cstdio>

int main()
{
	int n, c = 0, r = 0;
	char ch;
	scanf("%d %c", &n, &ch);
	if(n % 2 == 0)
		c = n / 2;
	else 
		c = n / 2 + 1;
	r = n;
	for(int i = 0; i < c; i++)
	{
		if(i == 0 || i + 1 == c)
		{
			for(int j = 0; j < r; j++)
				printf("%c", ch);
			printf("\n");
		}
		else
		{
			printf("%c", ch);
			for(int j = 1; j < r - 1; j++)
				printf(" ");
			printf("%c", ch);
			printf("\n");
		}
			
	}

	return 0;
}