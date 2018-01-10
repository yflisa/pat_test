#include <cstdio>
typedef long long LL;
const int N = 200;
int main()
{
	int nNum;
	LL n1[N], n2[N], n3[N];
	scanf("%d", &nNum);
	for(int i = 1; i <= nNum; i++)
	{
		scanf("%lld%lld%lld", &n1[i], &n2[i], &n3[i]);
	}

	for(int i = 1; i <= nNum; i++)
	{
		if(n1[i] + n2[i] > n3[i])
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}

	return 0;
}