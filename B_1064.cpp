#include <cstdio>
#include <cstring>
bool arr[10010] = {false};
int main()
{
	int n, cnt = 0;
	char str[5];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", str);
		int len = strlen(str),ans = 0;;
		for(int j = 0; j < len; j++)
		{
			ans += str[j] - '0';
		}
		if(arr[ans] == false)
		{
			arr[ans] = true;
			cnt++;
		}
	}
	int res = 0;
	printf("%d\n", cnt);
	for(int i = 0; i < 10010; i++)
	{
		if(arr[i] == true)
		{
			printf("%d", i);
			res++;
			if(res <= cnt - 1)
				printf(" ");
		}
	}
	return 0;
}