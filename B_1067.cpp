#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int n, cnt = 0;
	char str[22] = {0}, right[22] = {0};
	scanf("%s %d", right, &n);
	getchar();
	while(1)
	{
		gets(str);
		cnt++;
		if(str[0] == '#')
			break;
		if(strncmp((const char*)right, str, strlen((const char*)right)) == 0)
		{
			printf("Welcome in\n");
			break;
		}
		else
		{
			printf("Wrong password: %s\n", str);
			if(n == cnt)
			{
				printf("Account locked\n");
				break;
			}
		}
	}

	return 0;
}