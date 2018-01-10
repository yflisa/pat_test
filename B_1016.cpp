#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10010;
int main()
{
	char str1[N] = {0}, str2[N] = {0};
	char substr1, substr2;

	scanf("%s %c %s %c", str1, &substr1, str2, &substr2);

	int n1 = 0, n2 = 0;
	
	for(int i = 0; i < strlen(str1); i++)
	{
		if(str1[i] == substr1)
		{
			n1 = n1 * 10 + (substr1 - '0');
		}
	}

	for(int i = 0; i < strlen(str2); i++)
	{
		if(str2[i] == substr2)
		{
			n2 = n2 * 10 + (substr2 - '0');
		}
	}

	printf("%d\n", n1 + n2);
	return 0;
}