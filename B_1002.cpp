#include <cstdio>
#include <cstring>
char chinese[10][5] = {"ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
	char str[110];
	scanf("%s", str);
	int sum = 0, ans[1000] = {0}, count = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		sum += (str[i] - '0');
	}

	while(sum != 0)
	{
		ans[count++] = sum % 10;
		sum /= 10;
	}

	for(int i = count-1; i >= 0; i--)
	{
		printf("%s", chinese[ans[i]]);
		if(i != 0)
			printf(" ");
	}

	return 0;
}