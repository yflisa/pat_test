#include <cstdio>
#include <cstring>

int main()
{
	int A[10] = {0};
	int tmp;
	char num[1001];
	scanf("%s", num);

	for(int i = 0; i < strlen(num); i++)
	{
		tmp = num[i] - '0';
		A[tmp]++;
	}
	
	for(int i = 0; i < 10; i++)
	{
		if(A[i] != 0)
			printf("%d:%d\n", i, A[i]);
	}
	return 0;
}