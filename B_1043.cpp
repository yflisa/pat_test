#include <cstdio>
#include <cstring>

int main()
{
	char pat[] = {'P', 'A', 'T', 'e', 's', 't'}, str[10010];
	int len, hashtable[6] = {0}, count = 0;
	gets(str);
	len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(str[i] == pat[j])
			{
				hashtable[j]++;
				count++;
			}
		}
	}

	while(count > 0)
	{
		for(int i = 0; i < 6; i++)
		{
			if(hashtable[i] > 0)
			{
				printf("%c", pat[i]);
				hashtable[i]--;
				count--;
			}
		}
	}
	return 0;
}