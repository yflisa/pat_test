/*
	注意：
	这里注意当次数为负的时候，下标从1开始，原因，在输出0之前已经输出了0.，如果从0开始，就多输了
*/

#include <cstdio>

int main()
{
	char head, a[10001] = {0};
	int ex;

	scanf("%c%c.%[0-9]E%d", &head, &a[0], a+1, &ex);

	if(head == '-')
		printf("-");
	if(ex >= 0)
	{
		for(int i = 0; i < (ex + 1) || a[i] != 0; i++)
		{
			if(i == ex + 1)
				printf(".");
			printf("%c", a[i] == 0 ? '0':a[i]);
		}
	}
	else
	{
		printf("0.");
		for(int i = 1; i < (-ex); i++)
			printf("0");
		printf("%s", a);
	}

	return 0;
}