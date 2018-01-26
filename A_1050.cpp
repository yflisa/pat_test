#include <cstdio>
#include <cstring>

int main()
{
	char str1[100010], str2[100010];
	bool hashtable[256] = {false};
	gets(str1);
	gets(str2);

	for(int i = 0; i < strlen(str2); i++)
	{
		hashtable[str2[i]] = true;
	}

	for(int i = 0; i < strlen(str1); i++)
	{
		if(hashtable[str1[i]] == false)
			printf("%c", str1[i]);
	}

	return 0;
}